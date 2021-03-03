#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#include "Tabela.h"
#include "Registro.h"

using namespace std;

class Hashing
{
private:
    Tabela *vet;
    int tam;
    int tamPorao;
    int tamMax;
    int poraoLivre;
    int chavesArmazenadas;
    int contaColisoes;


public:
     Hashing(int n);
     ~Hashing();
     int funcaoHash(int val);
     int insere(int codigo, Registro r);
     int getCodigo(int i);
     int getData(int i);
     void imprime();
     int getChavesArmazenadas();
     int getContaColisoes();
     int indiceLivre(int h); //indice livre

};


#endif // HASHING_H_INCLUDED