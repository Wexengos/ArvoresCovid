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
    tamanhodoNo = tam;
}
ArvB::~ArvB(){}



void ArvB::insereArvB(int chave)
{
    if(raiz == NULL)
    {   
        
        raiz = new NoArvB(tamanhodoNo,true);
        raiz->chaves[0] = chave;
        raiz->n=1;
        raiz->filhos=NULL;

            
    }else{

        if(raiz->n == 2*tamanhodoNo-1){

            //Se raiz estiver cheia
            int i = 0;
            NoArvB *p = new NoArvB(tamanhodoNo, false);
            p->filhos[0]=raiz;
            p->split(0,raiz);

            //Aumenta o index para a achar a chave corresponde
            //que seja maior do que a chave que quer ser inserida assim ligando a folha correta
            if(p->chaves[0]<chave){
                i++;
            }

            p->filhos[i]->insertFilho(chave);
            raiz = p;
        }else{
            cout<<"Raiz n ta cheia"<<endl;
            raiz->insertFilho(chave);
        }
    }
}

void ArvB::imprimeArv()
{
    if(raiz!=NULL)
    {
    
        raiz->imprime();
    }
}


NoArvB* ArvB::busca(int chave)
{
    return (raiz == NULL) ? NULL : raiz->busca_no_No(chave);
}

