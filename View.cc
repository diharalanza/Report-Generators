#include <iostream>
using namespace std;
#include <sstream>
#include <string>

#include "View.h"

void View::checkChoice(int &choice)
{
  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 1 || choice > 5)
  {
    cout << "Enter your selection: ";
    cin >> choice;
  }
}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int &n)
{
  cin >> n;
}

void View::readStr(string &str)
{
  cin >> str;
}
