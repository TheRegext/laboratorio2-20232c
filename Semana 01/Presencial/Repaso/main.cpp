#include <iostream>
#include <cstring>
using namespace std;

#include "funciones.h"

int main()
{
    char mNombres[20][30];
    int vIngresos[20]={};
    int mIngresosXDia[20][31]={};
    int opc;
    while(true){
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"==============="<<endl;
        cout<<"1- INGRESO DATOS MATERIAS"<<endl;
        cout<<"2- INGRESO ASISTENCIAS ALUMNOS"<<endl;
        cout<<"3- MATERIAS SIN ALUMNOS"<<endl;
        cout<<"4- MATERIA CON MAS ALUMNOS"<<endl;
        cout<<"5- POR DIA DE AGOSTO, CANTIDAD DE ASISTENCIAS"<<endl;
        cout<<"0- SALIR"<<endl;
        cout<<"==============="<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            ingresoMaterias(mNombres);
            break;
        case 2:
            ingresoAsistencias(vIngresos, mIngresosXDia);
            break;
        case 3:
            materiasSinAsistencias(vIngresos, mNombres);
            break;
        case 4:
            materiaMasAsistencias(vIngresos, mNombres);
            break;
        case 5:
            asistenciasXDiaAgosto(mIngresosXDia);
            break;
        case 0:
            return 0;
        }
        system("pause");
    }
    return 0;
}
