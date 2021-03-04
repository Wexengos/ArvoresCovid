#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <math.h>
#include "Hashing.h"

using namespace std;

Hashing::Hashing(int n)
{
    tam = n*66;
    cout<<"TAM: "<<tam;
    tabelaRegistros = new Registro[tam];
    chavesArmazenadas = 0;
    contaColisao = 0;
    
}
Hashing::~Hashing()
{
    //delete tabelaRegistros;
}
int Hashing::hash(int val)
{   
    
    double a = (sqrt(5)-1)/2;
    int f1 = floor(((val*a) - floor(val*a))*tam);
    int f2 = 1+(val%17);
    int i = 0;
    int h = f1 +(i*f2);
    //cout<<"h: "<<h<<endl;
   
    //Tratamento de colisão sodagem dupla
    while(h < tam)
    {
        if(tabelaRegistros[h].getVisitado() == false)
        {   
            
            chavesArmazenadas ++;
            return h;
        }
        contaColisao++;
        i++;
        h = f1 +(i*f2);
        

    }
    
    return -1;

}
int Hashing::insere(int codigo, Registro r)
{
    
    int h = hash(codigo);
    
    //cout<<"Posi: "<<h<<endl;
    if(h == -1)
    {
        cout<<"nao foi possivel inserir o elemento "<<endl;
    }
    else
    {
        tabelaRegistros[h] = r;
        tabelaRegistros[h].setVisitado(true);
        
    }
    return h;
}
void Hashing::imprime()
{
    for(int i =0; i <tam; i++)
    {
        if(tabelaRegistros[i].getCasos()!=-1)
        {
            cout<<tabelaRegistros[i].getCidade()<<" ";
        }

    }
}
int Hashing::getCodigo(int i)
{   

    return tabelaRegistros[i].getCodigoCidade();
    
}
string Hashing::buscaNome(int i)
{
    return tabelaRegistros[i].getCidade();
}
int Hashing::getData(int i)
{   
    
    return tabelaRegistros[i].getDataInt();
}