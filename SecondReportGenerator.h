/*
Purpose: To declare ReportGenerator(s) in a ReportGeneratorclub which have:
         an id, title and author
         and manages the ReportGenerator data.
*/
#ifndef SECONDREPGEN_H
#define SECONDREPGEN_H
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "ReportGenerator.h"


class SecondReportGenerator : public ReportGenerator
{
  public:
    virtual void execute(string&);

};

#endif
