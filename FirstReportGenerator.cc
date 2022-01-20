#include <string>
#include <iomanip>
using namespace std;
#include <sstream>

#include "ReportGenerator.h"

FirstReportGenerator::FirstReportGenerator()
{
  reportName = "Generate employment percentage for each region, by degree, for all years and all genders in Canada";
}

void FirstReportGenerator::execute(string &outStr)
{

  stringstream ss;
  int i, j, k, p;
  string arr[4] = {"   ", "       ", "    ", "      "};

  ss << "\n"
     << "     ";
  for (i = 0; i < allDegrees.size(); i++)
  {
    ss << allDegrees[i]->getSign() << "  ";
  }
  ss << endl;

  for (i = 0; i < allRegions.size(); i++)
  {
    string r = allRegions[i]->getSign(); //e.g. AB
    if (r.size() == 2)
    { //covers all regions apart from CAN
      ss << r;
      for (j = 0; j < allDegrees.size(); j++)
      {
        double num = 0.0, total = 0.0;
        for (k = 0; k < allDegrees[j]->getInfoSize(); k++)
        {

          if ((*allDegrees[j])[k]->getGender() == "All" &&
              (*allDegrees[j])[k]->getRegion() == r)
          {
            num += (*allDegrees[j])[k]->getNumEmployed();
            total += (*allDegrees[j])[k]->getNumGrads();
          }
        }
        if (total == 0.0)
        {
          ss << arr[j] + " "
             << "0.00";
        }
        else
        {
          ss << arr[j] << fixed << setprecision(2) << (num * 100) / total;
        }
      }
      ss << endl;
    }
    else
    {
      p = i;
    }
  }

  string r = allRegions[p]->getSign(); //e.g. AB

  ss << r;
  for (j = 0; j < allDegrees.size(); j++)
  {
    double num = 0.0, total = 0.0;
    for (k = 0; k < allDegrees[j]->getInfoSize(); k++)
    {
      if ((*allDegrees[j])[k]->getGender() == "All" &&
          (*allDegrees[j])[k]->getRegion() == r)
      {
        num += (*allDegrees[j])[k]->getNumEmployed();
        total += (*allDegrees[j])[k]->getNumGrads();
      }
    }
    if (j == 0)
    {
      ss << "  ";
    }
    else
    {
      ss << arr[j];
    }
    ss << fixed << setprecision(2) << (num * 100) / total;
  }
  ss << endl;

  outStr = ss.str();
}
