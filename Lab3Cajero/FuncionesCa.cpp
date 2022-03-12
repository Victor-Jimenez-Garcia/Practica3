#include <FuncionesCa.h>
#include "DocumentoCa.h"

void Selec_Met(string name,  int n,int codif,int metodo)
{
    string texto,binario;
    texto=Leer_Docum(name);
    binario=toBinary(texto);

    if(metodo==1){
        if(codif==1){
            binario=Metodo1Cod(binario,n);
        }
        if(codif==2){
            binario=Metodo1Deco(binario,n);
        }
    }
    else if(metodo==2){
        binario=Metodo2CodDec(binario,n,codif);
    }
    texto=toText(binario);
    Escribir_Docum(name,texto);
//    cout<<texto<<endl;

}

void GuardarInfo(string name,  int n,int codif,string texto)
{
    string binario;
    binario=toBinary(texto);
    binario=Metodo2CodDec(binario,n,codif);
    texto=toText(binario);
    Escribir_Docum(name,texto);
}

string Seleccion(string name,  int n,int codif)
{
    string texto,binario;
    texto=Leer_Docum(name);
    binario=toBinary(texto);
    binario=Metodo2CodDec(binario,n,codif);
    texto=toText(binario);
    Escribir_Docum(name,texto);
    return texto;
}

string Metodo1Cod(string binario, int n)
{
    short caso=1, unos;
    string partido, final;
    for(unsigned long long int i=0,k=0; i<binario.size(); i++){
        partido.push_back(binario[i]);
        if((k+1)*n-1==i || i==binario.size()-1){
            for(unsigned long long int i=0; i<partido.size(); i++){
                switch (caso) {
                case 1:
                    if (partido[i]=='0')final.push_back('1');
                    else final.push_back('0');
                    break;

                case 2:
                    if(2*(k+1)-1==i){
                        if (partido[i]=='0')final.push_back('1');
                        else final.push_back('0');
                    }
                    else final.push_back(partido[i]);
                    break;
                default:
                    if((3*(k+1)-1==i)){
                        if (partido[i]=='0')final.push_back('1');
                        else final.push_back('0');
                    }
                    else final.push_back(partido[i]);
                    break;
                }
            }
            unos=contar1(partido);
            if(unos==(int(partido.size())-unos)) caso=1;
            else if(unos<(int(partido.size())-unos)) caso=2;
            else caso=3;
            partido.clear();
            k++;
        }
    }
    return final;
}

string Metodo1Deco(string binario, int n)
{
    short caso=1, unos;
    string partido, final;
    for(unsigned long long int i=0,k=0; i<binario.length(); i++){
        partido.push_back(binario[i]);
        if((k+1)*n-1==i || i==binario.length()-1){
            for(unsigned long long int i=0; i<partido.length(); i++){
                switch (caso) {
                case 1:
                    if (partido[i]=='0'){
                        final.push_back('1');
                        partido[i]='1';
                    }
                    else{
                        final.push_back('0');
                        partido[i]='0';
                    }
                    break;

                case 2:
                    if(2*(k+1)-1==i){
                        if (partido[i]=='0'){
                            final.push_back('1');
                            partido[i]='1';
                        }
                        else{
                            final.push_back('0');
                            partido[i]='0';
                        }
                    }
                    else final.push_back(partido[i]);
                    break;
                default:
                    if(3*(k+1)-1==i){
                        if (partido[i]=='0'){
                            final.push_back('1');
                            partido[i]='1';
                        }
                        else{
                            final.push_back('0');
                            partido[i]='0';
                        }
                    }
                    else final.push_back(partido[i]);
                    break;
                }
            }
            unos=contar1(partido);
            if(unos==(int(partido.length())-unos)) caso=1;
            else if(unos<(int(partido.length())-unos)) caso=2;
            else caso=3;
            partido.clear();
            k++;
        }
    }
//    cout<<final<<endl;
    return final;
}


string Metodo2CodDec(string binario, int n,int codif)
{
    string partido, temp,final; int d=0;

    if(codif==2)d=2; //si se requiere decdificar se asigna 2 a d

    for(unsigned long long int i=0,k=0; i<binario.length(); i++){
        partido.push_back(binario[i]);
        if((k+1)*n-1==i || i==binario.length()-1){
            for(unsigned long long int j=0;j<partido.length();j++){
              if(j==0){
                  if(codif==2){
                      temp=partido[j];
                      if(partido[j+1]=='0') final.push_back('0');
                      else final.push_back('1');
                      //final+=partido[j+1];
                  }
                  else{
                      if(partido[partido.length()-1]=='0') final.push_back('0');
                      else final.push_back('1');
                  }
              }
            else if(j==partido.length()-1){
                  if(codif==2){
                      if(temp[0]=='0') final.push_back('0');
                      else final.push_back('1');
                  }
              }
              else{
                  if(partido[j-1+d]=='0') final.push_back('0');
                  else final.push_back('1');
              }
            }
            if(codif!=2){
                if(partido[partido.length()-2]=='0') final.push_back('0');
                else final.push_back('1');
            }

            partido.clear();
            k++;
        }
    }

//    cout<<final<<endl;
    return final;
}
