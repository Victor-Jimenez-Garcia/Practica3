//#include "funciones.h"
//#include "Documento.h"
//#include <iostream>
//#include <fstream>
//#include <stdlib.h>
//#include <cstdlib>
//#include <stdio.h>
//#include <string.h>

//using namespace std;

//int n=4,codif=2;
//ifstream fin;     //stream de entrada
//ofstream fout;    //stream de salida
//ofstream temp;
//string salida, entrada;

//int main()
//{
//    ifstream fin; ofstream fout;
//    bool band=true; char arreglo[100];
//    int cedula,saldo;
//    char bclave[100];
//    while(band){
//        int opcion;
//        cout<<"1. Ingresar como administrador."<<endl;
//        cout<<"2. Ingresar como usuario."<<endl;
//        cout<<"3. Salir."<<endl;
//        cout <<"Ingrese la opcion: "<<endl;
//        cin>>opcion;
//        switch (opcion) {
//        case 1:{
//            int validar=0,c=0;
//            char clave[100];
//            string s="sudo.txt"; string ad="Admin.txt";
//            while(c<3){
//                int codif=2,n=4;
//                cout<<"Ingrese clave: "<<endl;
//                cin>>clave;
//                Selec_Met(s,n,codif,2);
//                fin.open(ad); //En este archivo esta clave decodificada
//                fin.getline(arreglo,100); //Le asigno la clave al arreglo
//                fin.seekg(0); fin.close();
//                if(strcmp(clave,arreglo)==0){ //comparo si la clave coincide
//                    cout<<"Bienvenido......"<<endl;
//                    validar=1;    //utilizo la variable para darle ingreso al programa
//                    c=3;
//                }
//                else{
//                    cout<<"Intente nuevamente.."<<endl;
//                    c++;
//                }
//            }
//            if(validar==1){ // si a es 1 entonces puede ingresar a hacer las funciones como administrador

//                    bool band2=true;
//                    int opc2=0;

//                    while(band2){
//                        cout<<"1.Ingresar usuarios."<<endl;
//                        cout<<"2.Salir."<<endl;
//                        cout<<"Ingrese opcion:"<<endl;
//                        cin>>opc2;
//                        switch (opc2) {
//                        case 1:{
//                            int clave, codif=1, n=4;
//                            cout<<"Ingrese cedula: "<<endl; cin>>cedula;
//                            cout<<"Ingrese clave: "<<endl; cin>>bclave;
//                            cout<<"Ingrese saldo: "<<endl; cin>>saldo;
//                            clave=atoi(bclave); //Convierto la cadena de caracteres en un entero
//                            fout.open("Usuarios.txt",ios::app);
//                            fout<<cedula<<" "<<clave<<" "<<saldo; //guardo los datos
//                            fout.close();
//                            //codificacion2(bclave,n,codif);
//                            break;
//                                }
//                            case 2:{
//                            band2=false;
//                            break;

//                                }
//                            }
//                        }
//                     }
//            else{
//                cout<<"-------------------Saliendo del modo administrador-----------------"<<endl;
//            }
//            break;
//            }
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
//        }
//    return 0;
//    }
//}

