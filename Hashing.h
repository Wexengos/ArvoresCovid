#include <vector>
#include <iostream>
#include <cstdlib>
#include "Registro.h"
#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

using namespace std;
class Hashing
{
private:
    Registro *tabelaRegistros;
    int tam;
    int chavesArmazenadas;


public:
    Hashing(int tam);
    ~Hashing();
    int hash(int val);
    int insere(int codigo, Registro r);
    void imprime();
    int getCodigo(int i);
    int getData(int i);




};

#endif // HASHING_H_INCLUDED