#include <vector>
#include <iostream>
#include <cstdlib>
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
    void insere(int codigo, Registro r);
    void imprime();
    int getChavesArmazenadas();




};

#endif // HASHING_H_INCLUDED