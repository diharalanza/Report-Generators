#include <sstream>
#include <iostream>
using namespace std;


int main(){

  stringstream ss;
  ss << "Daniel" << endl << "Bob" << endl ;
  string s = ss.str();
  cout << s;

  return 0;

}
