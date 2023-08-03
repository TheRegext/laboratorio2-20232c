#include <iostream>

using namespace std;

#include "funciones.h"


int main(){
    int opc, maxValor, minValor;
    int vec[10];

    bool cargado=false;
    while(true){
        system("cls");
        cout << "---------MENU-------" << endl;
        cout << "--------------------" << endl;
        cout << "1. CARGAR VECTOR"<<endl;
        cout << "2. MOSTRAR VECTOR"<<endl;
        cout << "3. MOSTRAR MAXIMO"<<endl;
        cout << "4. MOSTRAR MINIMO"<<endl;
        cout << "0. SALIR"<<endl;
        cout << "--------------------" << endl;
        cout << "INGRESE UNA OPCION: " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarVector(vec, 10);
                    cargado=true;
                    break;
            case 2: if(cargado==true)mostrarVector(vec, 10);
                    break;
            case 3: maxValor=buscarMaximo(vec, 10);
                    cout<<"VALOR MAXIMO "<<maxValor<<endl;
                    break;
            case 4: minValor=buscarMinimo(vec, 10);
                    cout<<"VALOR MINIMO "<<vec[minValor]<<endl;
                    break;
            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA. VUELVA A INGRESAR"<<endl;
                    break;
        }
        system("pause");
    }
    return 0;
}
