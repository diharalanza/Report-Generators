/*
Purpose: To declare ReportGenerator(s) in a ReportGeneratorclub which have:
         an id, title and author
         and manages the ReportGenerator data.
*/
#ifndef REPGEN_H
#define REPGEN_H
#include <string>
#include <vector>
#include <fstream>

#include "NGSReport.h"
#include "Property.h"

using namespace std;

class ReportGenerator
{
  protected:

  string reportName;//"Employment percentage for each region..."

  public:
    ReportGenerator();
    ~ReportGenerator();
    string getReportName();
    static void loadData();//loads data from grad.dat to the primary collection
    static void populateYears();//populates allYears collection
    static void populateRegions();//populates allRegions collection
    static void populateDegrees();//populates allDegrees collection

    static vector <NGSReport*> data;//primary collection of NGS data

    virtual void execute(string&) = 0;

    //partial collections
    static vector < Property<int>* > allYears;//organized by year
    static vector < Property<string>* > allRegions;//organized by regions
    static vector < Property<string>* > allDegrees;//organized by degrees

};

class FirstReportGenerator : public ReportGenerator
{
  public:
    FirstReportGenerator();
    virtual void execute(string&);

};

class SecondReportGenerator : public ReportGenerator
{
  public:
    SecondReportGenerator();
    virtual void execute(string&);

};

class ThirdReportGenerator : public ReportGenerator
{
  public:
    ThirdReportGenerator();
    virtual void execute(string&);

};

class FourthReportGenerator : public ReportGenerator
{
  public:
    FourthReportGenerator();
    virtual void execute(string&);

};

class FifthReportGenerator : public ReportGenerator
{
  public:
    FifthReportGenerator();
    virtual void execute(string&);

};


#endif
