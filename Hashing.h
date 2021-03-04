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
    Registro *tabelaHash;
    int tam;
    int chavesArmazenadas;

public:
    Hashing(int tam);
    ~Hashing();
    int funcaoHash(int val,int i);
    int insere(int codigo,Registro r);
    int auxInsere(Registro* v,int codigo, Registro r);
    int getChavesArmazenadas();
    double fatorCarga(int n, int d);
    void verificaRedistribuicao(int n);
    void imprimeTXT(std::ofstream& myfile);
    void imprime();
    void casosTotaisCidade(int codigoCidade);
    int getCodigo(int i);
    int getData(int i);
    //int getContaColisao(){return contaColisao;};
    string buscaNome(int i);




};

#endif // HASHING_H_INCLUDED