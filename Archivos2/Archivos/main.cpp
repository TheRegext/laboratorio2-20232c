#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "funcionesGlobales.h"
#include "clsFecha.h"
#include "clsArticulo.h"
#include "clsCliente.h"
#include "funcionesArticulo.h"
#include "submenuClientes.h"
#include "submenuArticulos.h"

int main(){

  Articulo art;

  art.Cargar("123");




  return 0;



    ArchivoArticulo archi("articulos.dat");
    int cantReg=archi.contarRegistros();
    cout<<cantReg<<endl;
    system("pause");
    int opc;
    while(true){
        system("cls");
        cout<<"***MENU PRINCIPAL***"<<endl;
        cout<<"1. MENU ARTICULOS"<<endl;
        cout<<"2. MENU CLIENTES"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"********************"<<endl;
        cout<<"SELECCIONAR OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: subMenuArticulos();
                break;
            case 2: subMenuClientes();
                break;
            case 0: return 0;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;


        }
        system("pause");
    }
    return 0;
}
