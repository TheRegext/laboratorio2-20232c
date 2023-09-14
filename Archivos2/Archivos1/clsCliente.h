#ifndef CLSCLIENTE_H_INCLUDED
#define CLSCLIENTE_H_INCLUDED

class Cliente{
private:
    int DNI;
    Fecha fechaNacimiento;
    char nombre[25];
    char apellido[25];
    char email[25];
    char telefono[20];
    bool estado;
public:
    Cliente(const char *n="NOMBRE"){
        strcpy(nombre, n);
        estado=true;
        }

    int getDNI(){return DNI;}
    Fecha getFechaNacimiento();

    Cliente(Fecha aux){
        fechaNacimiento=aux;
        estado=true;
    }

    Cliente(int d, int m, int a){
        fechaNacimiento.setDia(d);
        fechaNacimiento.setMes(m);
        fechaNacimiento.setAnio(a);
        estado=true;
    }


    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}

    void setDNI(const int d){DNI=d;}
    void setFechaNacimiento(Fecha f){fechaNacimiento=f;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}

    void Cargar();
    void Mostrar();

};


Fecha Cliente::getFechaNacimiento(){
        return fechaNacimiento;
    }

void Cliente::Cargar(){
    cout<<"DNI: ";
    cin>>DNI;
    cout<<"Fecha Nacimiento: "<<endl;
    fechaNacimiento.Cargar();
    cout<<"Nombre: ";
    cargarCadena(nombre, 24);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,24);
    cout<<"EMAIL: ";
    cargarCadena(email,24);
    cout<<"TELEFONO: ";
    cargarCadena(telefono,19);
    estado=true;
}

void Cliente::Mostrar(){
    if(estado){
        cout<<"DNI: ";
        cout<<DNI<<endl;
        cout<<"Fecha Nacimiento: "<<endl;
        fechaNacimiento.Mostrar();
        cout<<"Nombre: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"EMAIL: ";
        cout<<email<<endl;
        cout<<"TELEFONO: ";
        cout<<telefono<<endl;
    }

}


#endif // CLSCLIENTE_H_INCLUDED
