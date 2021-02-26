#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include "Hashing.h"

using namespace std;

Hashing::Hashing(int n)
{
    tam = n + (n/2);
    tabelaRegistros = new Registro[tam];
    chavesArmazenadas = 0;

    
}
Hashing::~Hashing()
{
    //delete tabelaRegistros;
}
int Hashing::hash(int val)
{   
    
    int f1 = val%17;
    int f2 = 1+(val%13);
    int i = 0;
    int h = f1 +(i*f2);
    

    //Tratamento de colisão sodagem dupla
    while(h < tam)
    {
        if(tabelaRegistros[h].getCasos() == -1)
        {   
            
            chavesArmazenadas ++;
            return h;
        }
      
        i++;
        h = f1 +(i*f2);
        

    }
    for(int i = 0; i < tam; i++)
    {
        if(tabelaRegistros[i].getCasos() == -1)
        {
            chavesArmazenadas ++;
            return h;
        }
    }
    return -1;

}
int Hashing::insere(int codigo, Registro r)
{
    
    int h = hash(codigo);
   
    if(h == -1)
    {
        cout<<"nao foi possivel inserir o elemento "<<endl;
    }
    else
    {
        tabelaRegistros[h] = r;
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
int Hashing::getData(int i)
{   
    string str1 =tabelaRegistros[i].getDataCompleta();
    string str2;

   for(int contador = 0; contador <str1.size(); contador++){

        if(str1[contador]!='-'){
            str2+=str1[contador];
        }
   }
   int data = stoi(str2);
 
    
    return data;
}