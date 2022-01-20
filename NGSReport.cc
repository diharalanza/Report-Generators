#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;
#include "NGSReport.h"

NGSReport::NGSReport(int y, string r, string d, string g, int ne, int ng)
{
  year = y;
  region = r;
  degree = d;
  gender = g;
  numEmployed = ne;
  numGrads = ng;
}

NGSReport::~NGSReport() {}

int NGSReport::getYear() { return year; }

string NGSReport::getDegree() { return degree; }

string NGSReport::getRegion() { return region; }

string NGSReport::getGender() { return gender; }

int NGSReport::getNumEmployed() { return numEmployed; }

int NGSReport::getNumGrads() { return numGrads; }
