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

/*
void queHago(const char *palabra="nada"){
    if(strcmp(palabra,"nada")==0){
        cout<<"palabra CONTIENE nada ";
    }
    else{
        cout<<"palabra contiene "<<palabra;
    }
    cout<<endl;
}
  */
int main(){
  /*  cout<<"LLAMO A LA FUNCION Y LE ENVIO COMO PARAMETRO hola!"<<endl;
    queHago("hola!");
    system("pause");
    cout<<"LLAMO A LA FUNCION Y NO LE ENVIO NADA"<<endl;
    queHago();
    system("pause");
    return 0;
    */
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
