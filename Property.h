/*
Purpose: To declare a Property which has customer(s) and account(s)
*/

#include <string>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

#include "NGSReport.h"

template <class T>
class Property
{
public:
  Property(T);
  ~Property();
  Property<T> &operator+=(NGSReport *); //addition assignment operator
  NGSReport *&operator[](int);          //subscript operator
  T getSign();
  int getInfoSize();

private:
  T sign; //2000
  vector<NGSReport *> info;
};

template <class T>
Property<T>::Property(T t)
{
  sign = t;
}

template <class T>
Property<T>::~Property()
{
  info.clear();
}

template <class T>
Property<T> &Property<T>::operator+=(NGSReport *newElement)
{
  if (newElement == NULL)
  {
    cerr << "Element to be added is NULL " << endl;
    exit(1);
  }
  info.push_back(newElement);
  return *this;
}

template <class T>
NGSReport *&Property<T>::operator[](int index)
{

  if (index < 0 || index >= info.size())
  {
    cerr << "Index out of range! " << endl;
    exit(1);
  }

  return info[index];
}

template <class T>
T Property<T>::getSign() { return sign; }

template <class T>
int Property<T>::getInfoSize() { return info.size(); }
