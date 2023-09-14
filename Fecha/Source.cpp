#include <iostream>
#include "Fecha.h"
#include "Persona.h"
using namespace std;

int main() {
  Persona persona(Fecha(22,6,1990));

  Fecha fechaActual = persona.getFechaNacimiento();

  cout << fechaActual.getDay() << "/" << fechaActual.getMonth() << "/" << fechaActual.getYear() << endl;

  return 0;
}