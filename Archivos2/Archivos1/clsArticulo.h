#ifndef CLSARTICULO_H_INCLUDED
#define CLSARTICULO_H_INCLUDED

class Articulo{
  private:
    char codigo[5];
    char descripcion[30];
    int stock;
    float pu;
	bool estado;
  public:
    Articulo(int s=0, const char * c="0000",const char *d="nada", float p=0){
        strcpy(codigo, c);
        strcpy(descripcion, d);
        stock=s;
        pu=p;
        estado=true;
    }
    Articulo(const char *desc){
        strcpy(descripcion, desc);
    }
    void Cargar(const char*);
    void Mostrar();
    int getStock(){return stock;}
    void setStock(int s){
      if(s<0){
        stock=0;
      }
      else
        stock=s;
    }

    bool getEstado(){return estado;}

    void setEstado(bool s){
      estado=s;
    }

    const char * getCodigo(){return codigo;}

 };

void Articulo::Cargar(const char *cod=" "){
    if(strcmp(cod," ")==0){
        cout<<"CODIGO: ";
        cargarCadena(codigo,4);
    }
    else{
        strcpy(codigo,cod);
    }
    cout<<"DESCRIPCION: ";
    cargarCadena(descripcion,29);
    cout<<"STOCK: ";
    cin>>stock;
    cout<<"PU: ";
    cin>>pu;
    estado=true;
}


void Articulo::Mostrar(){
      if(estado==true){
          cout<<"CODIGO: ";
          cout<<codigo<<endl;
          cout<<"DESCRIPCION: ";
          cout<<descripcion<<endl;
          cout<<"STOCK: ";
          cout<<stock<<endl;
          cout<<"PU: ";
          cout<<pu<<endl;
    }
}


class ArchivoArticulo{
    private:
        char nombre[30];
    public:
        ArchivoArticulo(const char *nAr){
            strcpy(nombre,nAr);
        }
        const char *getNombre(){return nombre;}
        bool listarRegistros();
        bool AgregarRegistro(Articulo );
        int buscarRegistro(const char *codigo);
        Articulo leerRegistro(int pos);
        bool modificarRegistro(int pos, Articulo reg);
        int contarRegistros();


};

bool ArchivoArticulo::listarRegistros(){
    Articulo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg, sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

bool ArchivoArticulo::AgregarRegistro(Articulo reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoArticulo:: buscarRegistro(const char *codigo){
    Articulo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int cont=0;
    while(fread(&reg, sizeof reg,1,p)==1){
        if(strcmp(reg.getCodigo(),codigo)==0){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}


Articulo ArchivoArticulo::leerRegistro(int pos){
    Articulo reg;
    reg.setEstado(false);
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    ///fseek(PUNTERO_FILE,CUANTOS_BYTES_ME_QUIERO_DESPLAZAR,DESDE_DONDE); 0: PRINCIPIO; 1: POSICION ACTUAL; 2: FIN
    fseek(p,sizeof(Articulo)*pos,0);                                                                     ///SEEK_SET        SEEK_CUR         SEEK_END
    fread(&reg, sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool ArchivoArticulo::modificarRegistro(int pos, Articulo reg){
    FILE *p=fopen(nombre,"rb+");///+ agrega al modo lo que le falta
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    fseek(p,sizeof(Articulo)*pos,0);
    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;



}
int ArchivoArticulo::contarRegistros(){
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    fseek(p,0,2); ///SEEK_END
    ///ftell(p)->devuelve la cantidad de bytes que hay desde el principio del archivo hasta la posición del puntero FILE
    int cantByte=ftell(p);
    fclose(p);
    return cantByte/sizeof(Articulo);

}
#endif // CLSARTICULO_H_INCLUDED
