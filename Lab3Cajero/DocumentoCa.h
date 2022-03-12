#ifndef DOCUMENTOCA_H
#define DOCUMENTOCA_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Escribir_Docum(string name, string data);
string Leer_Docum(string name);

int contar1(string r);
string toBinary(string texto);
string toText(string binario);

void usersInfo(string users,size_t posicion, string *cedula,string *pass,string *saldo);
#endif // DOCUMENTOCA_H
