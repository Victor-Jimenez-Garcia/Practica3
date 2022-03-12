#include "FuncionesCa.h"
#include "DocumentoCa.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

using namespace std;

int n=4,codif=2;
ifstream fin;     //stream de entrada
ofstream fout;    //stream de salida
ofstream temp;
string salida, entrada;

int main()
{
    ifstream fin; ofstream fout;
    bool band=true; char arreglo[100];
    int cedula,saldo;
    char bclave[100];
    string aux,sudo,users,contra,user,CedulaUs,permiso,SaldoUs,ListUsers; size_t posicion;
    int retiro,operacion;
    while(band){
        int opcion;
        cout<<"1. Ingresar como administrador."<<endl;
        cout<<"2. Ingresar como usuario."<<endl;
        cout<<"3. Salir."<<endl;
        cout <<"Ingrese la opcion: "<<endl;
        cin>>opcion;
        switch (opcion) {
        case 1:{
            int validar=0,c=0;
            char clave[100];
            string s="sudo.txt";
            //string ad="Admin.txt";
            while(c<3){
                int codif=2,n=4;
                cout<<"Ingrese clave: "<<endl;
                cin>>clave;
                Selec_Met(s,n,codif,2);
                fin.open(s); //En este archivo esta clave codificada
                fin.getline(arreglo,100); //Le asigno la clave al arreglo
                fin.seekg(0);
                fin.close();
                Selec_Met(s,n,1,2);

                if(strcmp(clave,arreglo)==0){ //comparo si la clave coincide
                    cout<<"Bienvenido......"<<endl;
                    validar=1;    //utilizo la variable para darle ingreso al programa
                    c=3;
                }
                else{
                    cout<<"Intente nuevamente.."<<endl;
                    c++;
                }
            }
            if(validar==1){ // si a es 1 entonces puede ingresar a hacer las funciones como administrador

                    bool band2=true;
                    int opc2=0;

                    while(band2){
                        cout<<"1.Ingresar usuarios."<<endl;
                        cout<<"2.Listar usuarios."<<endl;
                        cout<<"3.Salir."<<endl;
                        cout<<"Ingrese opcion: "<<endl;
                        cin>>opc2;
                        switch (opc2) {
                        case 1:{
                            int clave;
                            cout<<"Ingrese cedula: "<<endl; cin>>cedula;
                            cout<<"Ingrese clave: "<<endl; cin>>bclave;
                            cout<<"Ingrese saldo: "<<endl; cin>>saldo;
                            clave=atoi(bclave);
                            Selec_Met("Usuarios.txt",4,2,2);
                            fout.open("Usuarios.txt",ios::app);
                            fout<<cedula<<","<<clave<<","<<saldo<<endl;
                            fout.close();
                            Selec_Met("Usuarios.txt",4,1,2);
                            break;
                                }
                        case 2 :{ //Listar Usuarios
                            cout<<"\n\tLista de usuarios"<<endl;
                            Selec_Met("Usuarios.txt",4,2,2);
                            ListUsers=Leer_Docum("Usuarios.txt");

                            cout<<ListUsers<<endl;

                            Selec_Met("Usuarios.txt",4,1,2);
                                }
                        case 3:{
                            band2=false;
                            break;

                                }
                            }
                        }
                     }
            else{
                cout<<"-------------------Saliendo del modo administrador-----------------"<<endl;
            }
            break;
            }
//        case 2 :{ //Ingreso como usuario
//            bool band3 = true; int opc3; char claveu[100];
//            cout<<"Ingrese clave:"<<endl; cin>>claveu;
//            try{
//                fin.open("Usuarios.txt");
//                if (!fin.is_open()){
//                    throw '1';
//                }
//                fin.close();
//            }
//            catch (char c){
//                if (c=='1'){
//                    cout<<"-------Clave incorrecta------"<<endl;
//                    break;
//                    }
//                }
//            catch (...){
//                cout<<"Error inesperado."<<endl;
//                }
//            while(band3){
//                cout<<"1.Consultar saldo."<<endl;
//                cout<<"2.Retirar dinero."<<endl;
//                cout<<"3.Ingresar dinero a la cuenta."<<endl;
//                cout<<"4.Salir."<<endl;
//                cout<<"Ingrese opcion:"<<endl; cin>>opc3;
//                switch (opc3) {
//                case 1:{

//                    break;
//                    }
//                }
//              }
//            }
        case 2 :{
            users=Seleccion("Usuarios.txt", 4,2);
            cout<<"Ingrese su numero de usuario: ";
            fflush(stdin);
            getline(cin,user);
            posicion=users.find(user);
            Seleccion("Usuarios.txt", 4,1);
            if(posicion != string::npos){
                usersInfo(users,posicion,&CedulaUs,&permiso,&SaldoUs);
                cout<<"Ingrese su clave: ";
                fflush(stdin);
                getline(cin,contra);
                if (contra==permiso) {
                    cout<<"Logeado correctamente\n\n\tBIENVENIDO USUARIO: \n"<<endl;
                    cout<<"(1) Consultar saldo"<<endl;
                    cout<<"(2) Retirar dinero"<<endl;
                    cout<<"(3) Salir"<<endl;
                    sudo.clear();
                    bool menu_user=true;
                    while (menu_user) {
                        users=Seleccion("Usuarios.txt", 4,2);
                        usersInfo(users,posicion,&CedulaUs,&permiso,&SaldoUs);
                        cout<<"\nDigite una opcion: "; cin>>opcion;
                        switch (opcion) {
                        case 1:
                            if (1000>stoi(SaldoUs)) {
                                cout<<"No puede realizar esta operacion, saldo insuficiente"<<endl;
                            }
                            else{
                                cout<<"Saldo disponible: "<<SaldoUs<<endl;
                                operacion=stoi(SaldoUs);
                                operacion-=1000;
                                users.replace(users.find(SaldoUs,posicion),SaldoUs.size(),to_string(operacion));
                            }
                            break;
                        case 2:{
                            cout<<"Saldo disponible: "<<SaldoUs<<endl;
                            cout<<"Cuanto dinero desea retirar: "; cin>>retiro;
                            operacion=stoi(SaldoUs);
                            if (retiro>stoi(SaldoUs)) {
                                cout<<"No puede retirar esa cantidad"<<endl;
                            }
                            else{
                                operacion-=retiro+1000;
                                users.replace(users.find(SaldoUs,posicion),SaldoUs.size(),to_string(operacion));
                                cout<<"Nuevo saldo: "<<operacion<<endl;
                            }
                        }
                            break;
                        case 3:
                            menu_user=false;
                            break;

                        default:
                            cout<<"Opcion invalida"<<endl;
                            break;
                        }
                        GuardarInfo("Usuarios.txt", 4,1,users);
                    }
                }
                else cout<<"Clave incorrecta"<<endl;
            }
            else cout<<"Ese usuario no esta registrado"<<endl;
            break;
        case 3:
                exit(-1);
                break;
            default:
                cout<<"Opcion invalida"<<endl;
                break;
        }
        }
    return 0;
    }
}
