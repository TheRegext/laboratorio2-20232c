#ifndef SUBMENUARTICULOS_H_INCLUDED
#define SUBMENUARTICULOS_H_INCLUDED
///PROTOTIPOS
void submenuArticulos();
void agregarRegistroArticulo();
void mostrarArticulos();
bool bajaLogicaArticulo();
///FIN PROTOTIPOS

void subMenuArticulos(){
    int opc;
    while(true){
        system("cls");
        cout<<"ARTICULOS"<<endl;
        cout<<"1. AGREGAR ARTICULO"<<endl;
        cout<<"2. MOSTRAR ARTICULOS"<<endl;
        cout<<"3. BAJA LOGICA ARTICULO"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:agregarRegistroArticulo();
                break;
            case 2:mostrarArticulos();
                break;
            case 3:bajaLogicaArticulo();
                break;
            case 0:return;
                break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }
}

void agregarRegistroArticulo(){
    Articulo reg;

    ArchivoArticulo archi("articulos.dat");
    ///Asignamos valores al objeto de memoria
    char codigo[5];
    cout<<"CODIGO: ";
    cargarCadena(codigo,4);
    int pos=archi.buscarRegistro(codigo);
    if(pos==-1){
        reg.Cargar(codigo);
    ///Escribimos el registro en el archivo
        bool agregar=archi.AgregarRegistro(reg);
    ///Chequeamos que la operación se haya ejecutado correctamente
        if(agregar==true){
            cout<<"REGISTRO AGREGADO";
        }
        else{
            cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        }
    }
    else{
        cout<<"YA EXISTE UN REGISTRO CON ESE CODIGO"<<endl;
    }
}

void mostrarArticulos(){
        ArchivoArticulo archi("articulos.dat");
        archi.listarRegistros();
}


bool bajaLogicaArticulo(){
    ///PEDIR AL USUSARIO QUE INGRESE EL CODIGO DEL ARTICULO QUE SE QUIERE DAR DE BAJA
    ArchivoArticulo archi("articulos.dat");
    char codigo[5];
    int pos;
    cout<<"INGRESE EL CODIGO DEL ARTICULO A BORRAR ";
    cin>>codigo;
    ///BUSCAR EL REGISTRO QUE CONTENGA EL CODIGO INGRESADO EN EL ARCHIVO.
    pos=archi.buscarRegistro(codigo);///buscarRegistro(const char *) devuelve la posición del registro en el archivo
    ///SI NO EXISTE INFORMARLO
    if(pos==-1){
        cout<<"NO EXISTE EL REGISTRO CON ESE CODIGO"<<endl;
        return false;
    }
    else{
        if(pos==-2){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
            return false;
        }
    }
    ///SI EXISTE:
                ///COPIAR EN UNA VARIABLE DE MEMORIA (OBJETO) EL REGISTRO
    Articulo reg=archi.leerRegistro(pos);
    ///* CAMBIAR EL VALOR DEL CAMPO ESTADO A false (variable de memoria)
    reg.Mostrar();
    reg.setEstado(false);
    ///* REESCRIBIR EL REGISTRO EN EL ARCHIVO
    bool quePaso=archi.modificarRegistro(pos,reg);
    if(quePaso==true){
        cout<<"REGISTRO BORRADO";
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }
    cout<<endl;
    return true;
}

#endif // SUBMENUARTICULOS_H_INCLUDED
