#pragma once
#include "Fecha.h"
class Persona
{
public:
  Persona(Fecha fechaNacimiento);
  Fecha getFechaNacimiento();
private:
  Fecha _fechaNacimiento;
};