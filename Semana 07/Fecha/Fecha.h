#pragma once

class Fecha
{
public:
  Fecha(); // se cree con la fecha actual
  Fecha(int day, int month, int year);

  int getYear() ;
  void setYear(int year);
  int getMonth() ;
  void setMonth(int month);
  int getDay() ;
  void setDay(int day);

private:
  int _year;
  int _month;
  int _day;
};
