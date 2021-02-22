#include <iostream>
#include <vector>
#include "Balde.h"

using namespace std;

Balde::Balde(int tBalde,int tOverflow)
{
    tamBalde = tBalde;
    tamOverflow = tOverflow;
    balde = new int[tamBalde + tamOverflow];
    for(int i = 0; i < tamBalde + tamOverflow; i++)
    {
        setChave(i,-1);

    }
}
Balde::~Balde()
{

}
int Balde::getTamBalde()
{
    return tamBalde;
}
int Balde::getChave(int i)
{
    return balde[i];
}
void Balde::setChave(int i, int val)
{
    balde[i] = val;
}

void Balde::excluiElemento(int i)
{
    balde[i] = -1;

}
int Balde::getTamOverflow()
{
    return tamOverflow;
}
int Balde::indiceDsponivel()
{
    for(int i =0; i < getTamBalde() + getTamOverflow(); i++)
    {
        if(getChave(i)== -1)
        {
            return i;
        }
    }
    return -1;
}
bool Balde::baldeCheio()
{
    if(indiceDsponivel() == -1)
    {
        return true;
    }
    return false;
}
void Balde::busca(int val)
{
    int x = 0;
    for(int i = 0; i < tamBalde + tamOverflow; i++)
    {
        if(balde[i] == val)
        {
            cout<<"Valor encontrado!"<<endl;
            x++;
            break;
        }
    }
    if(x == 0)
        cout<<"Valor nao encontrado"<<endl;
}
void Balde::imprime()
{

    for(int i = 0; i < tamBalde ; i++)
    {
        if(getChave(i) != -1)
        {
            cout<<getChave(i)<<" ";
        }


    }
    cout<<endl;
    cout<<"Area de overflow: ";
    for(int i = tamBalde; i < tamBalde + tamOverflow; i++)
    {
          if(getChave(i) != -1)
        {
            cout<<getChave(i)<<" ";
        }

    }
    cout<<endl;
}
