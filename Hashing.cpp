#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>

#include "Hashing.h"

using namespace std;

Hashing::Hashing(int n)
{
    tam = n;
    vet = new int[tam];
    chavesArmazenadas = 0;
    for(int i = 0; i < tam; i++)
    {
        vet[i] = -1;
    }
}
Hashing::~Hashing()
{
    //delete vet;
}
int Hashing::busca(int val)
{
    int f1 = val%17;
    int f2 = 1+(val%13);
    int i = 0;
    int h = f1 +(i*f2);
    while(h < tam)
    {
        if(vet[h] == -1)
        {
            chavesArmazenadas ++;
            return h;
        }
        i++;
        h = f1 +(i*f2);
    }
    for(int i = 0; i < tam; i++)
    {
        if(vet[i] == -1)
        {
            chavesArmazenadas ++;
            return h;
        }
    }
    return -1;

}
void Hashing::insere(int val)
{
    int h = busca(val);
    if(h == -1)
    {
        cout<<"nao foi possivel inserir o elemento "<<val<<endl;
    }
    else
    {
        vet[h] = val;
    }

}
void Hashing::imprime()
{
    for(int i =0; i <tam; i++)
    {
        if(vet[i] != -1)
        {
            cout<<vet[i]<<" ";
        }

    }
}
int Hashing::getChavesArmazenadas()
{
    return chavesArmazenadas;
}
