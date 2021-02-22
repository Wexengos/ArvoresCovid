#include <vector>
#include <iostream>
#include <cstdlib>
#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

using namespace std;
class Hashing
{
private:
    int *vet;
    int tam;
    int chavesArmazenadas;


public:
    Hashing(int tam);
    ~Hashing();
    int busca(int val);
    void insere(int val);
    void imprime();
    int getChavesArmazenadas();




};

#endif // HASHING_H_INCLUDED