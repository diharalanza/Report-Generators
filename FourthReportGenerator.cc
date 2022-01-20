using namespace std;
#include <sstream>

#include "ReportGenerator.h"

FourthReportGenerator::FourthReportGenerator()
{
  reportName = "Generate employment precentage for each degree by year for all genders for a selected region in Canada";
}

void FourthReportGenerator::execute(string &outStr)
{
  stringstream ss;
  int i, j, k, p;
  string arr[4] = {"  ", "     ", "   ", "    "};

  for (i = 0; i < allYears.size(); i++)
  {
    if (i == 0)
    {
      ss << string(12, ' ');
    }
    else
    {
      ss << "   ";
    }
    ss << allYears[i]->getSign();
  }
  ss << endl;

  for (i = 0; i < allDegrees.size(); i++)
  {
    string d = allDegrees[i]->getSign(); //e.g. AB
    ss << d;
    for (j = 0; j < allYears.size(); j++)
    {
      double num = 0.0, total = 0.0;
      for (k = 0; k < allYears[j]->getInfoSize(); k++)
      {

        if ((*allYears[j])[k]->getGender() == "All" &&
            (*allYears[j])[k]->getDegree() == d &&
            (*allYears[j])[k]->getRegion() == outStr)
        {
          num += (*allYears[j])[k]->getNumEmployed();
          total += (*allYears[j])[k]->getNumGrads();
        }
      }
      if (j == 0)
      {
        ss << arr[i];
      }
      else
      {
        ss << "  ";
      }

      if (total == 0.0)
      {
        ss << "0.00";
      }
      else
      {
        ss << fixed << setprecision(2) << (num * 100) / total;
      }
    }
    ss << endl;
  }

  outStr = ss.str();
}
