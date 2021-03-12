#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm> 
#include <climits>
#include "ArvB.h"

using namespace std;


ArvB::ArvB(int tam)
{
    raiz = NULL;
    tamanhodoNo = tam/2;
    
}
ArvB::~ArvB(){}

int ArvB::comparaData(int x,int *ch,Hashing *tabela,int i)
{
  
    if(tabela->getData(x) < tabela->getData(ch[i]))
        return -2;
    else 
        return 2;
}

int ArvB::compara(int x,int *ch,Hashing *tabela,int i)
{
  
    if(tabela->getCodigo(x) < tabela->getCodigo(ch[i]))
        return -1;
    else if(tabela->getCodigo(x) > tabela->getCodigo(ch[i]))
        return 1;
    else if(tabela->getCodigo(x) == tabela->getCodigo(ch[i]))
    {
        int comp = comparaData(x,ch,tabela,i);
        return comp;
    }
    return 0;
}



void ArvB::insereArvB(int chave,Hashing *tabela)
{
    if(raiz == NULL)
    {   
        
        raiz = new NoArvB(tamanhodoNo,true);
        raiz->setChave(0, chave);
        raiz->setN(1);
        //cout<<"tam: "<<raiz->getN()<<endl;

            
    }else{

        if(raiz->getN() == 2*tamanhodoNo-1){
            
            //Se raiz estiver cheia
          
            NoArvB *p = new NoArvB(tamanhodoNo, false);
            p->setFilhos(0,raiz);
            p->split(0,raiz,tabela);

            //Aumenta o index para a achar a chave corresponde
            //que seja maior do que a chave que quer ser inserida assim ligando a folha correta
            int i = 0;
            
         
            if((compara(chave,p->chaves,tabela,0) == 1 ||compara(chave,p->chaves,tabela,0) == 2 )){
                i++;
            }

            p->getFilhos(i)->insertFilho(chave,tabela);
            raiz = p;
        }else{
            //cout<<"Raiz n ta cheia"<<endl;
            raiz->insertFilho(chave,tabela);
        }
    }
}

void ArvB::imprimeArv(Hashing *tabela)
{
    if(raiz!=NULL)
    {
        raiz->imprime(tabela);
    }

    /*
    for (int i = 0; i < raiz->getN(); i++)
    {
        cout<<" /"<<raiz->chaves[i];
    }
    */
}
void ArvB::imprimeArvTXT(Hashing *tabela,std::ofstream& myfile)
{
    if(raiz!=NULL)
    {
        raiz->imprimeTXT(tabela,myfile);
    }
}
void ArvB::imprimeArvTXTBusca(Hashing *tabela,std::ofstream& myfile,int k,int &cont)
{
    if(raiz!=NULL)
    {
        raiz->imprimeTXTBusca(tabela,myfile,k,cont);
    }
}
NoArvB* ArvB::busca(int chave,Hashing *tabela)
{
    return (raiz == NULL) ? NULL : raiz->busca_no_No(chave,tabela);
}

void ArvB::buscaCodigo(int codigo,Hashing *tabela,int &cont)
{
    if(raiz!=NULL)
    {   
        raiz->buscaCodigo(codigo,tabela,cont);
    }
}
