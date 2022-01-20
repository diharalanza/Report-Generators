#ifndef NGS_H
#define NGS_H
#include <string>

using namespace std;

class NGSReport
{
  public:
    NGSReport(int,string,string,string,int,int);
    ~NGSReport();
    int getYear();
    string getDegree();
    string getRegion();
    string getGender();
    int getNumEmployed();
    int getNumGrads();

  private:

    int year;
    string region;
    string degree;
    string gender;
    int numEmployed;
    int numGrads;


};

#endif
