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
static int encontraPrimo(int n, bool x)
{
    int h = n;
    while(verificaPrimo(h) == false)
    {
        if(h > 0)
        {
            if(x == true)
            {
                h++;
            }
            else
            {
                h--;
            }

        }
        else
        {
            break;
        }


    }
    return h;
}

Hashing::Hashing(int n)
{   
    tam = encontraPrimo(n+((n/7)*2), true);
    //cout<<"Tam: "<<tam<<endl;
    tabelaHash = new Registro[tam];
    chavesArmazenadas = 0;

}
Hashing::~Hashing()
{
    delete []tabelaHash;
    chavesArmazenadas = 0;
}
bool Hashing::cheio()
{
    return (chavesArmazenadas == tam);
}

int Hashing::funcaoHash(int val,int i)
{
    //cout<<h<<endl;
    return val%tam;
}
int Hashing::funcaoHash2(int val,int i)
{
    //cout<<h<<endl;
    return (1572869 - (val % 1572869));
}

bool Hashing::verifica(int ha)
{
    if(tabelaHash[ha].getVisitado()!=false)
        return 1;
    else
        return 0;

}

int Hashing::insere(int val,Registro *r)
{


    int h,hInicial;
    int i = 1;

     h = funcaoHash(val,i);
     hInicial = h;

    if(verifica(h)){
        int h2 = funcaoHash2(val,i);
        //i = 1;
        while(true)
        {   
            int novoh = (h +  i * h2)%tam;
            if(!verifica(novoh))
            {

                chavesArmazenadas ++;
                tabelaHash[novoh] = *r;
                tabelaHash[novoh].setVisitado(true);
                return novoh;
            }
            
                i++;
                //h =  funcaoHash2(val,i);; //((val%tam)+i)%tam;;
            

        }
    }else{
        chavesArmazenadas ++;
        tabelaHash[h] = *r;
        tabelaHash[h].setVisitado(true);
        return h;
    }

     return h;

}


/*
int Hashing::hash(int val)
{
    
    double a = (sqrt(5)-1)/2;
    int f1 = floor(((val * a) - floor(val * a)) * tam);
    int f2 = 1+(val%17);
    int i = 0;
    int h = f1 +(i*f2); //((val%tam)+i)%tam; //f1 +(i*f2);


    //Tratamento de colisão sodagem dupla
    
    
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
        tabelaHash[h] = r;
        tabelaHash[h].setVisitado(true);
        
        
        
    }
    return h;
    

  

}

*/
int Hashing::getChavesArmazenadas()
{
    return chavesArmazenadas;
}

void Hashing::imprime()
{

    for(int i = 0; i < tam; i++)
    {
        if(tabelaHash[i].getVisitado()!= false)
        {
            cout<<tabelaHash[i].getCidade()<<" ";

        }
    }
    cout<<endl;
    
}

void Hashing::imprimeTXT(std::ofstream& myfile)
{   
    int i;
    for(i=0; i <tam; i++)
    {
        
        if(tabelaHash[i].getVisitado() != false)
        {
            myfile<<"Cidade: "<<tabelaHash[i].getCidade()<<"|Data: "<<tabelaHash[i].getDataCompleta()<<"|Casos dia: "<<tabelaHash[i].getCasos()<<endl;
        }

    }
    myfile<<"Quant registros Hash: "<<i<<endl;
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
string Hashing::data(int i){
    return tabelaHash[i].getDataCompleta();
}