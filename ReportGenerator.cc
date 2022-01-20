#include <string>
using namespace std;
#include <sstream>
#include <iomanip>
#include "ReportGenerator.h"

vector<NGSReport *> ReportGenerator::data = vector<NGSReport *>(); //primary collection of NGS data
vector<Property<int> *> ReportGenerator::allYears = vector<Property<int> *>();
vector<Property<string> *> ReportGenerator::allRegions = vector<Property<string> *>();
vector<Property<string> *> ReportGenerator::allDegrees = vector<Property<string> *>();

ReportGenerator::ReportGenerator() {}

ReportGenerator::~ReportGenerator()
{
  cout << "ESfsdf";

  for (int i = 0; i < data.size(); i++)
  {
    delete data[i];
  }

  while (data.size() != 0)
  {
    data.pop_back();
  }

  for (int i = 0; i < allYears.size(); i++)
  {
    delete allYears[i];
  }

  allYears.clear();
  for (int i = 0; i < allRegions.size(); i++)
  {
    delete allRegions[i];
  }

  allRegions.clear();
  for (int i = 0; i < allDegrees.size(); i++)
  {
    delete allDegrees[i];
  }

  allDegrees.clear();
}

string ReportGenerator::getReportName() { return reportName; }

void ReportGenerator::loadData()
{
  int y, ne, ng;
  string r, d, g;
  ifstream fin("grad.dat");
  if (!fin)
  {
    cout << "Could not open grad.dat" << endl;
    exit(-1);
  }
  NGSReport *rep;
  while (fin >> y >> r >> d >> g >> ne >> ng)
  {
    rep = new NGSReport(y, r, d, g, ne, ng);
    data.push_back(rep);
  }
  fin.close();
}

void ReportGenerator::populateYears()
{
  int i, j;
  for (i = 0; i < data.size(); i++)
  {
    int y = data[i]->getYear();
    for (j = 0; j < allYears.size(); j++)
    {
      if (allYears[j]->getSign() >= y)
        break;
    }
    if (j < allYears.size())
    {
      if (allYears[j]->getSign() == y)
      {
        (*allYears[j]) += data[i];
      }
      else
      {
        Property<int> *p = new Property<int>(y);
        (*p) += data[i];
        allYears.insert(allYears.begin() + j, p);
      }
    }
    else
    {
      Property<int> *p = new Property<int>(y);
      (*p) += data[i];
      allYears.push_back(p);
    }
  }
}

void ReportGenerator::populateRegions()
{
  int i, j;
  for (i = 0; i < data.size(); i++)
  {
    string y = data[i]->getRegion();
    for (j = 0; j < allRegions.size(); j++)
    {
      if (allRegions[j]->getSign() >= y)
        break;
    }
    if (j < allRegions.size())
    {
      if (allRegions[j]->getSign() == y)
      {
        *(allRegions[j]) += data[i];
      }
      else
      {
        Property<string> *p = new Property<string>(y);
        (*p) += data[i];
        allRegions.insert(allRegions.begin() + j, p);
      }
    }
    else
    {
      Property<string> *p = new Property<string>(y);
      (*p) += data[i];
      allRegions.push_back(p);
    }
  }
}

void ReportGenerator::populateDegrees()
{
  int i, j;
  for (i = 0; i < data.size(); i++)
  {
    string y = data[i]->getDegree();
    for (j = 0; j < allDegrees.size(); j++)
    {
      if (allDegrees[j]->getSign() >= y)
        break;
    }
    if (j < allDegrees.size())
    {
      if (allDegrees[j]->getSign() == y)
      {
        (*allDegrees[j]) += data[i];
      }
      else
      {
        Property<string> *p = new Property<string>(y);
        (*p) += data[i];
        allDegrees.insert(allDegrees.begin() + j, p);
      }
    }
    else
    {
      Property<string> *p = new Property<string>(y);
      (*p) += data[i];
      allDegrees.push_back(p);
    }
  }
}
