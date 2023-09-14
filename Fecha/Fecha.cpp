#include "Fecha.h"
#include <ctime>
/*
Fecha::Fecha()
{
  time_t tiempo = time(nullptr);
  tm* fecha = localtime(&tiempo);

  setDay(fecha->tm_mday);
  setMonth(fecha->tm_mon + 1);
  setYear(fecha->tm_year + 1900);
}
*/
Fecha::Fecha(int day, int month, int year)
  : _day(0), _month(0), _year(0)
{
  setDay(day);
  setMonth(month);
  setYear(year);
}

int Fecha::getYear() 
{
  return _year;
}

void Fecha::setYear( int year)
{
  if(year >= 1)
  {
    _year = year;
  }
}

int Fecha::getMonth() {
  return _month;
}

void Fecha::setMonth(int month)
{
  if(month >= 1 && month <= 12)
  {
    _month = month;
  }
}

int Fecha::getDay(){
  return _day;
}

void Fecha::setDay(int day)
{
  if(day >= 1 && day <= 31)
  {
    _day = day;
  }
}
