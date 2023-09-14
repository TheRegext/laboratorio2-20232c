#ifndef SUBMENUCLIENTES_H_INCLUDED
#define SUBMENUCLIENTES_H_INCLUDED
///PROTOTIPOS
void submenuClientes();
void agregarRegistroCliente();
void mostrarClientes();
///FIN PROTOTIPOS

void subMenuClientes(){
    int opc;
    while(true){
        system("cls");
        cout<<"CLIENTES"<<endl;
        cout<<"1. AGREGAR CLIENTE"<<endl;
        cout<<"2. MOSTRAR CLIENTES"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:agregarRegistroCliente();
                break;
            case 2:mostrarClientes();
                break;
            case 0:return;
                break;
            default:cout<<"OPCION INCORRECTA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }

    Cliente regCli;
    regCli.Cargar();
    regCli.Mostrar();
}

void agregarRegistroCliente(){
    Cliente regCli;
    FILE *pCli=fopen("clientes.dat","ab");
    if(pCli==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    regCli.Cargar();
    int escribio=fwrite(&regCli,sizeof regCli,1, pCli);
    if(escribio==1) {
      cout<<"REGISTRO AGREGADO"<<endl;
    }
    fclose(pCli);
}

void mostrarClientes(){
    Cliente regCli;
    FILE *pCli=fopen("clientes.dat","rb");
    if(pCli==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    /*int leyo=fread(&regCli,sizeof regCli,1, pCli);
    /if(leyo==1) {
      regCli.Mostrar();
    }
      */
    while(fread(&regCli, sizeof regCli,1,pCli)==1){
        regCli.Mostrar();
        cout<<endl;
    }
    fclose(pCli);
}


#endif // SUBMENUCLIENTES_H_INCLUDED
