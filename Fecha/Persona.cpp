#include "Persona.h"

Persona::Persona(Fecha fechaNacimiento)
  : _fechaNacimiento(fechaNacimiento)
{
  //_fechaNacimiento = fechaNacimiento;
}

Fecha Persona::getFechaNacimiento()
{
  return _fechaNacimiento;
}
