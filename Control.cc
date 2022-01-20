#include <iostream>
#include <iomanip>
using namespace std;
#include <string>
#include <sstream>

#include "Control.h"

Control::Control()
{
  repGens = vector<ReportGenerator *>();

  FirstReportGenerator *first = new FirstReportGenerator();
  SecondReportGenerator *second = new SecondReportGenerator();
  ThirdReportGenerator *third = new ThirdReportGenerator();
  FourthReportGenerator *fourth = new FourthReportGenerator();
  FifthReportGenerator *fifth = new FifthReportGenerator();

  repGens.push_back(first);
  repGens.push_back(second);
  repGens.push_back(third);
  repGens.push_back(fourth);
  repGens.push_back(fifth);
}

Control::~Control()
{

  for (int i = 0; i < repGens.size(); i++)
  {

    delete repGens[i];
  }
  repGens.clear();
}

void Control::launch()
{
  int i, choice, incoming;
  string prompt, option;
  string output = " ";
  initData();

  while (1)
  {
    view.printStr("\n");
    for (i = 0; i < repGens.size(); i++)
    {
      format(option, i + 1, repGens[i]->getReportName());
      view.printStr(option);
      view.printStr("\n");
    }

    view.checkChoice(choice);

    if (choice == 0)
      break;

    //  Print students
    if (choice == 1)
    {
      repGens[choice - 1]->execute(output);
      view.printStr(output);
    }
    //  Print courses
    if (choice == 2)
    {
      repGens[choice - 1]->execute(output);
      view.printStr(output);
    }
    //  Print courses taken
    if (choice == 3)
    {
      repGens[choice - 1]->execute(output);
      view.printStr(output);
    }
    //  Print courses taken by student
    if (choice == 4)
    {
      //string provinces[11] = {"AB","BC","MB","NB","NL","NS","ON","PE","QC","SK","CAN"};
      while (true)
      {
        prompt = "Which region do you wish to know about (Enter a number) ? \n";
        view.printStr(prompt);
        for (i = 0; i < ReportGenerator::allRegions.size(); i++)
        {
          format(option, i + 1, ReportGenerator::allRegions[i]->getSign());
          view.printStr(option);
        }
        view.readInt(incoming);
        if (incoming >= 1 && incoming <= 11)
          break;
      }

      output = ReportGenerator::allRegions[incoming - 1]->getSign();
      view.printStr("\nRegion: " + output + "\n");
      repGens[choice - 1]->execute(output);
      view.printStr(output);
    }
    //  Add course taken by student
    if (choice == 5)
    {
      repGens[choice - 1]->execute(output);
      view.printStr(output);
    }
  }
}

void Control::initData()
{

  ReportGenerator::loadData();
  ReportGenerator::populateYears();
  ReportGenerator::populateRegions();
  ReportGenerator::populateDegrees();
}

void Control::format(string &str, int optionNum, string optionData)
{
  stringstream ss;
  ss << "(" << optionNum << ") " << optionData << "\n";
  str = ss.str();
}

/*
void Control::cleanup(){

  delete first, second, third, fourth;
}
*/
