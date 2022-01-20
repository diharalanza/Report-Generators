using namespace std;

#include "ReportGenerator.h"
#include <sstream>

FifthReportGenerator::FifthReportGenerator()
{
  reportName = " Generate years with most number of male and female graduates for each region in Canada ";
}

void FifthReportGenerator::execute(string &outStr)
{

  stringstream ss;
  int i, j, p, k;

  for (i = 0; i < allRegions.size(); i++)
  {
    string r = allRegions[i]->getSign(); //e.g. AB
    //cout << r <<endl;
    if (r.size() == 2)
    { //covers all regions apart from CAN
      ss << "\nRegion: " << r << endl;
      int bestMale = 0, bestFemale = 0, bestMyear, bestFyear;

      for (j = 0; j < allYears.size(); j++)
      {
        int maleNum = 0, femaleNum = 0;
        for (k = 0; k < allYears[j]->getInfoSize(); k++)
        {

          if ((*allYears[j])[k]->getGender() == "Males" &&
              (*allYears[j])[k]->getRegion() == r)
          {
            maleNum += (*allYears[j])[k]->getNumGrads();
          }
          if ((*allYears[j])[k]->getGender() == "Females" &&
              (*allYears[j])[k]->getRegion() == r)
          {
            femaleNum += (*allYears[j])[k]->getNumGrads();
          }
        }

        if (maleNum > bestMale)
        {
          bestMale = maleNum;
          bestMyear = allYears[j]->getSign();
        }
        if (femaleNum > bestFemale)
        {
          bestFemale = femaleNum;
          bestFyear = allYears[j]->getSign();
        }
      }
      ss << "Most male graduates were in " << bestMyear << ", Number of male graduates = " << bestMale << endl;
      ss << "Most female graduates were in " << bestFyear << ", Number of female graduates = " << bestFemale << endl;
    }
    else
    {
      p = i;
    }
  }

  string r = allRegions[p]->getSign(); //e.g. AB

  ss << "\n"
     << r << ": " << endl;
  int bestMale = 0, bestFemale = 0, bestMyear, bestFyear;

  for (j = 0; j < allYears.size(); j++)
  {
    int maleNum = 0, femaleNum = 0;
    for (k = 0; k < allYears[j]->getInfoSize(); k++)
    {

      if ((*allYears[j])[k]->getGender() == "Males" &&
          (*allYears[j])[k]->getRegion() == r)
      {
        maleNum += (*allYears[j])[k]->getNumGrads();
      }
      if ((*allYears[j])[k]->getGender() == "Females" &&
          (*allYears[j])[k]->getRegion() == r)
      {
        femaleNum += (*allYears[j])[k]->getNumGrads();
      }
    }

    if (maleNum > bestMale)
    {
      bestMale = maleNum;
      bestMyear = allYears[j]->getSign();
    }
    if (femaleNum > bestFemale)
    {
      bestFemale = femaleNum;
      bestFyear = allYears[j]->getSign();
    }
  }
  ss << "Most male graduates were in " << bestMyear << ", Number of male graduates = " << bestMale << endl;
  ss << "Most female graduates were in " << bestFyear << ", Number of female graduates = " << bestFemale << endl;

  outStr = ss.str();
}
