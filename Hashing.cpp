#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "Registro.h"
#include "Hashing.h"


using namespace std;
static bool verificaPrimo(int n)
{
    if(n == 0)
    {
        return false;
    }
    int cont = 0;
    for(int i = 1; i <= n; i++)
    {
        if(n%i == 0)
        {
            cont ++;
            if(cont > 2)
            {
                return false;
            }
        }
    }
    return true;

}
static int encontraPrimo(int n)
{
    int h = n;
    while(verificaPrimo(h) == false)
    {
        h++;

    }
    return h;
}


Hashing::Hashing(int n)
{
    tam = encontraPrimo(n);
    tabelaHash = new Registro[tam];
    chavesArmazenadas = 0;
    /*for(int i = 0; i < tam; i++)
    {
        tabelaHash[i]. = -1;
    }*/

}
Hashing::~Hashing()
{
    delete []tabelaHash;
    chavesArmazenadas = 0;
}
int Hashing::funcaoHash(int val,int i)
{

    int h = ((val%tam)+i)%tam;
    return h;
}
int Hashing::auxInsere(Registro *v,int codigo,Registro r) 
{

     verificaRedistribuicao(fatorCarga(chavesArmazenadas, tam));
     int h,hInicial;
     int i = 0;
     h = funcaoHash(codigo,i);
     hInicial = h;
     while(tabelaHash[h].getCasos()!= -1)
     {
         /*if(tabelaHash[h] == val)
         {
             chavesArmazenadas --;
             break;
         }*/
         i++;
         h = funcaoHash(codigo,i);

         if(h = hInicial)
         {
             return -1;
         }

     }
     tabelaHash[h] = r;
     chavesArmazenadas ++;
     return h;
}
int Hashing::insere(int codigo, Registro r)
{
    int a = auxInsere(tabelaHash,codigo, r);
    return a;
}

int Hashing::getChavesArmazenadas()
{
    return chavesArmazenadas;
}
double Hashing::fatorCarga(int n, int d)
{
      return (double)n/d * 100;

}
 void Hashing::verificaRedistribuicao(int n)
{
    if(n >= 50)
    {

         Registro* nova;
         Registro* antiga;
         int n = tam;
         tam = encontraPrimo(tam*2);
         chavesArmazenadas = 0;
         nova = new Registro[tam];
         /*for(int i = 0; i< tam ; i++)
         {
             nova[i]. = -1;
         }*/
        antiga = tabelaHash;
        tabelaHash = nova;
        for(int i = 0; i < n; i++)
        {
             if(antiga[i].getCasos() != -1)
             {
                  auxInsere(tabelaHash,getCodigo(i),antiga[i]);
             }
        }
        delete []antiga;
    }

}
void Hashing::imprime()
{

    for(int i = 0; i < tam; i++)
    {
        if(tabelaHash[i].getCasos() != -1)
        {
            cout<<tabelaHash[i].getCasos()<<" ";

        }
    }
    cout<<endl;
    cout<<"tamanho da hash: "<<tam<<endl;
}
int Hashing::getCodigo(int i)
{
    return tabelaHash[i].getCodigoCidade();
}
int Hashing::getData(int i)
{
    string str1 = tabelaHash[i].getDataCompleta();
    string str2;

    for (int contador = 0; contador < str1.size(); contador++)
    {

        if (str1[contador] != '-')
        {
            str2 += str1[contador];
        }
    }
    int data = stoi(str2);

    return data;
}