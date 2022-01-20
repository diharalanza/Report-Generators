/*
Purpose: To manage all operations of a school67ui
*/
#ifndef CONTROL_H
#define CONTROL_H

#include "ReportGenerator.h"

#include "View.h"
#include <vector>

class Control
{
  public:
    Control();
    ~Control();

    //controls all operations on the school
    void launch();

    //initializes students in the school
    void initData();
    void format(string&, int,string);

    //initializes courses in the school
    //void cleanup();

  private:

    vector <ReportGenerator*> repGens;//for later
    //FifthReportGenerator fifth;

    //displays main menu and reads user selection
    View view;
};

#endif
