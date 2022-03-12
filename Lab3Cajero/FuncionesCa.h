#ifndef FUNCIONESCA_H
#define FUNCIONESCA_H

#include "DocumentoCa.h"


void Selec_Met(string name,  int n,int codif,int metodo);
void GuardarInfo(string name,  int n,int codif,string texto);

string Seleccion(string name,  int n,int codif);

string Metodo1Cod(string binario, int n);
string Metodo1Deco(string binario, int n);
string Metodo2CodDec(string binario, int n,int codif);


#endif // FUNCIONESCA_H
