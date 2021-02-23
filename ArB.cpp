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


ArvB::ArvB()
{
    raiz = NULL;
}
ArvB::~ArvB(){}



void ArvB::insereArvB(int chave)
{
    if(raiz == NULL)
    {   
        
        raiz = new NoArvB();
        raiz->setChaves(chave,0);
        raiz->setN(1);
        raiz->setFolha(true);
            
    }else{

        if(raiz->getN() == 2*N -1){

            
            NoArvB *p = new NoArvB();  
            p->setFolha(false); 
            p->setFilhos(raiz,0);
            
            p->split(0,raiz);
            int i =0;
            
            for(int i = 0; i < N; i++)
            {   
                cout<<"Ch: "<<p->getChave(i)<<endl;
            }
            
            if(p->getChave(0) < chave)
                i++;
            p->getFilhos(i)->insertFilho(chave);
            raiz = p;
        }else{
            raiz->insertFilho(chave);
        }
    }
}

void ArvB::imprimeArv()
{
    if(raiz!=NULL){
        cout<<"entrou" <<endl;
        raiz->imprime();
    }
}

NoArvB* ArvB::busca(int chave)
{
    return (raiz == NULL) ? NULL : raiz->busca(chave);
}