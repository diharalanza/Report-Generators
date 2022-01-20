/*
Purpose: To declare ReportGenerator(s) in a ReportGeneratorclub which have:
         an id, title and author
         and manages the ReportGenerator data.
*/
#ifndef FOURTHREPGEN_H
#define FOURTHREPGEN_H
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "ReportGenerator.h"


class FourthReportGenerator : public ReportGenerator
{
  public:
    virtual void execute(string&);

};

#endif
