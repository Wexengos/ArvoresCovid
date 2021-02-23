#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include "NoArvB.h"

using namespace std;

void NoArvB::split(int i,NoArvB *p)
{
    NoArvB *q = new NoArvB();
    q->setFolha(p->getFolha());
    q->setN(N -1);

   
    for(int j = 0 ; j<N-1;j++){
        q->setChaves(p->getChave(j+N),j);
        cout<<"chave: "<<q->getChave(j);
    }
    cout<<"Folha? "<< p->getFolha();

    if(p->getFolha() == false){
        cout<<"entrou aqui"<<endl;
        for(int j = 0;j<N;j++)
            q->setFilhos(p->getFilhos(j+N),j);
    }

    p->setN(N-1);
    
    for(int j=p->getN(); j>= i+1;j--)
        filhos[j+1] = filhos[j];

    filhos[i+1] = q;

    for(int j=p->getN()-1; j>= i;j--){
        chaves[j+1] = chaves[j];
        cout<<"chave: "<<chaves[i]<<endl;
    }
    chaves[i] = p->getChave(N-1);

    p->setN(n+1);
   
    


        
}


void NoArvB::insertFilho(int k){

    int i = n - 1;
       

    if(getFolha()==true)
    {   
        
        while (i>= 0 && chaves[i] > k)
        {
            chaves[i+1] = chaves[i];
            i--;
        }

        chaves[i+1] = k;
        n = n + 1; 

    }else{
         
        while (i>= 0 && chaves[i]>k)  
            i--;

        if(filhos[i+1]->n == 2 * N -1){
            split(i+1,filhos[i+1]);

            if(chaves[i+1]<k)
                i++;
        }

        filhos[i+1]->insertFilho(k);
        
         
    }
}

NoArvB* NoArvB::busca(int chave)
{
    int i = 0 ;

    while (i<n && chave>chaves[i])
        i++;

    if(chaves[i]==chave)
        return this;
    if(getFolha()==true)
        return NULL;

    return filhos[i]->busca(chave);
}

void NoArvB::imprime()
{
    int i;
    for(i= 0; i<n;i++)
    {
        if(getFolha() == false)
            filhos[i]->imprime();

        cout<<"Chaves: "<<chaves[i];
    }

    if(getFolha() == false)
       filhos[i]->imprime();
}