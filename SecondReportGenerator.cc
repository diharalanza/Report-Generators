#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

#include "ReportGenerator.h"

SecondReportGenerator::SecondReportGenerator()
{
  reportName = "Generate top 3 and bottom 3 regions for percentage of female graduates, for all years and all degrees in Canada";
}

void SecondReportGenerator::execute(string &outStr)
{
  stringstream ss;
  int i, j, k, p;
  vector<string> regs;
  vector<int> femNums;
  vector<int> totalNums;

  ss << "\n";
  for (i = 0; i < allRegions.size(); i++)
  {
    string r = allRegions[i]->getSign(); //e.g. AB
    if (r.size() == 2)
    { //covers all regions apart from CAN
      long long num = 0, total = 0;

      for (j = 0; j < allRegions[i]->getInfoSize(); j++)
      {
        if ((*allRegions[i])[j]->getGender() == "Females")
        {
          num += (*allRegions[i])[j]->getNumGrads();
        }
        if ((*allRegions[i])[j]->getGender() == "All")
        {
          total += (*allRegions[i])[j]->getNumGrads();
        }
      }

      for (k = 0; k < regs.size(); k++)
      {
        if (num * totalNums[k] < femNums[k] * total)
        {
          break;
        }
      }
      regs.insert(regs.begin() + k, r);
      femNums.insert(femNums.begin() + k, num);
      totalNums.insert(totalNums.begin() + k, total);
      //ss << endl;
    }
    else
    {
      p = i;
    }
  }

  i = regs.size() - 1;
  ss << "Top 3 Regions" << endl;

  for (k = 0; k < 3; k++)
  {
    ss << regs[i] << "    " << fixed << setprecision(2) << (double)(femNums[i] * 100) / totalNums[i] << endl;
    i--;
  }

  ss << "\nBottom 3 Regions" << endl;

  for (k = 0; k < 3; k++)
  {
    ss << regs[k] << "    " << fixed << setprecision(2) << (double)(femNums[k] * 100) / totalNums[k] << endl;
  }

  string r = allRegions[p]->getSign(); //e.g. AB
  ss << endl;
  ss << r;
  int num = 0, total = 0;

  for (j = 0; j < allRegions[p]->getInfoSize(); j++)
  {
    if ((*allRegions[p])[j]->getGender() == "Females")
    {
      num += (*allRegions[p])[j]->getNumGrads();
    }
    if ((*allRegions[p])[j]->getGender() == "All")
    {
      total += (*allRegions[p])[j]->getNumGrads();
    }
  }
  ss << "   " << fixed << setprecision(2) << (double)(num * 100) / total << endl;

  outStr = ss.str();
}
