/*
Purpose: To declare ReportGenerator(s) in a ReportGeneratorclub which have:
         an id, title and author
         and manages the ReportGenerator data.
*/
#ifndef FIFTHREPGEN_H
#define FIFTHREPGEN_H
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "ReportGenerator.h"


class FifthReportGenerator : public ReportGenerator
{
  public:
    virtual void execute(string&);

};

#endif
