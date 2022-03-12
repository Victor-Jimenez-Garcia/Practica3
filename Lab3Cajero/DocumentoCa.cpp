#include "DocumentoCa.h"
#include "FuncionesCa.h"

void Escribir_Docum(string name, string datos)
{
    ofstream archivoEscritura;

    archivoEscritura.open(name); //Abrir el archivo en modo lectura

    if(archivoEscritura.fail()){//Hay error al abrir el archivo
        cout<<"No se pudo abrir el archivo. Error de escritura."<<endl;
        exit(-1); //Finalizar la ejecucion del programa
    }

    archivoEscritura<<datos;
    archivoEscritura.close();
}

string Leer_Docum(string name)
{
    string linea,datos;
    ifstream archivoLectura;

    archivoLectura.open(name); //Abrir el archivo en modo lectura

    if(archivoLectura.fail()){//Hay error al abrir el archivo
        cout<<"No se pudo abrir el archivo. Error de Lectura."<<endl;
        exit(-1); //Finalizar la ejecucion del programa
    }

    while (!archivoLectura.eof()) {//mientras no se haya llegado al final del archivo
        getline(archivoLectura,linea,'\n');
        datos += linea+'\n';
        //cout<<linea<<endl;//CONTROL
    }
    //cout<<texto<<endl;
    archivoLectura.close();
    return datos;
}

int contar1(string r){
    int cont=0;
    for(unsigned long long int i=0;i<r.length();i++){
        if(r[i]=='1') cont++;
    }
    return cont;
}

string toBinary(string texto){
    string binario;
    for(unsigned long int i=0; i<texto.length(); i++){
        for(int j=0;j<8;j++) binario.push_back(char((((texto[i]<<j)&(0x80))/128)+48));
    }
    return binario;
}

string toText(string binario){
    string  texto;
    int length_b = binario.length();
    int posicion=0;
    for (int i=0,contador=128,suma=0;i<length_b;) {
        for (int j=0;j<8;i++,j++) {

            if(binario[i]==49){
               suma+=contador;
               contador/=2;
            }else{
               contador/=2;
            }
        }
        contador=128;
        texto+=suma;
        posicion ++;
        suma=0;
    }
    //cout<<frase<<endl;
    return texto;
}

void usersInfo(string users,size_t posicion, string *cedula,string *pass,string *saldo)//extrae la informacion de cada usuario
{
    *cedula="";*pass="";*saldo="";

    for (unsigned long long int i=posicion,k=0;k!=3;i++) {

        if(users[i]==',' || users[i]=='\n'){
            k++;
        }
        else if(k==0){
            *cedula+=users[i];
        }
        else if(k==1){
            *pass+=users[i];
        }
        else if(k==2){
            *saldo+=users[i];
        }

    }

}
