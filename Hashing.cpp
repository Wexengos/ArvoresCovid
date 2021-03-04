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

         if(h == hInicial)
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
    //cout<<auxInsere(tabelaHash,codigo, r)<<endl;
    //cout<<codigo<<endl;
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
        cout<<"Aumentando e redtribuindo"<<endl;
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

void Hashing::imprimeTXT(std::ofstream& myfile)
{   
    int i;
    for( i =0; i <tam; i++)
    {
        if(tabelaHash[i].getCasos()!=-1)
        {
            myfile<<"Cidade: "<<tabelaHash[i].getCidade()<<"|Data: "<<tabelaHash[i].getDataCompleta()<<"|Casos dia: "<<tabelaHash[i].getCasos()<<endl;
        }

    }
    myfile<<"Quant registros Hash: "<<i<<endl;
}
void Hashing::imprime()
{
    for(int i =0; i <tam; i++)
    {
        if(tabelaHash[i].getCasos()!=-1)
        {
            cout<<"Cidade: "<<tabelaHash[i].getCidade()<<endl;
        }

    }
}
void Hashing::casosTotaisCidade(int codigoCidade)
{   
    int casosCidade = 0;
    string cidade;
    for(int i =0; i <tam; i++)
    {
        if(tabelaHash[i].getCodigoCidade() == codigoCidade)
        {
           casosCidade = casosCidade + tabelaHash[i].getCasos();
           cidade = tabelaHash[i].getCidade();
        }

    }

    cout<<"A cidade "<<cidade<<"teve "<< casosCidade <<"casos"<<endl;
}
int Hashing::getCodigo(int i)
{   

    return tabelaHash[i].getCodigoCidade();
    
}
string Hashing::buscaNome(int i)
{
    return tabelaHash[i].getCidade();
}
int Hashing::getData(int i)
{   
    
    return tabelaHash[i].getDataInt();
}