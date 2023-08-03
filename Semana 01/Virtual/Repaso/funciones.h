#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROTOTIPOS
void cargarVector(int v[5], int tam);///CARGA VECTORES DE ENTEROS.
void mostrarVector(int v[], int tam);
int buscarMaximo(int v[], int tam);
int buscarMinimo(int v[], int tam);

///FIN PROTOTIPOS



void cargarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"INGRESE UN NUMERO ";
        cin>>v[i];
    }
}


void mostrarVector(int *v, int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<endl;
    }
}
int buscarMaximo(int *v, int tam){
    int maximo=v[0], i;
    for(i=1;i<tam;i++){
        if(v[i]>maximo){
            maximo=v[i];
        }
    }
    return maximo;
}

int buscarMinimo(int *v, int tam){
    int posMini=0, i;
    for(i=1;i<tam;i++){
        if(v[i]<v[posMini]){
            posMini=i;
        }
    }
    return posMini;
}


#endif // FUNCIONES_H_INCLUDED
