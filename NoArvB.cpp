#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "NoArvB.h"
#include <bits/stdc++.h> 

using namespace std;

NoArvB::NoArvB(int tamanho,bool f)
{
    tam = tamanho;
    folha = f;
    chaves = new int [tam-1];
    filhos = new NoArvB * [tam];
    n = 0;
}

void NoArvB::split(int i,NoArvB *r)
{
    NoArvB *q = new NoArvB(r->getTam(),r->getFolha());
    q->setN(tam);

    for(int j=0;j<tam-1;j++)
    {   
        //Transfere as chaves com valores maiores para o novo No
        q->chaves[j] = r->chaves[j+tam];
        
    }

    if(r->getFolha()==false)
    {
        for(int j=0;j<tam-1;j++){
            q->filhos[j] = r->filhos[j+tam];
        }

    }

    r->setN(tam-1);

    for(int j=n;j>=i+1;j--)
    {
        filhos[j+1]=filhos[j];
    }
    
    filhos[i+1]=q;
   

    for (int j =n; j >= i; j--)
    {
       this-> chaves[j + 1] = this->chaves[j]; 
    }
       
    
   
    chaves[i]=q->chaves[tam/2];
    n =n + 1;
}


void NoArvB::insertFilho(int k)
{
    int i = n;

    
    //Se for folha inseria a chave na posição correta 
    if(folha==true){
        
        while (i>=0 && this->chaves[i]>k)
        {   
            //Ajusta as chaves dentro do No
            chaves[i+1]=chaves[i];
            i--;
        }

        
        chaves[i+1] = k;
        n++;
        /*
        int aux=chaves[0];
          for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    if (chaves[i] < chaves[j])
                    {
                        aux = chaves[i];
                        chaves[i] = chaves[j];
                        chaves[j] = aux;
                    }
                }
            }
        n++;
        */
    }else{
        
        
        while (i>=0 && this->chaves[i]>k)
        {
            i--;
        }
        
        if(filhos[i+1]->getN() == filhos[i+1]->getTam())
        {
            split(i+1,this->filhos[i+1]);

            if(chaves[i+1]<k)
                i++;
        }
       filhos[i+1]->insertFilho(k);
    }
   
}

NoArvB* NoArvB::busca_no_No(int k)
{
   int i=0;
    
    while (i<n && k>chaves[i])
    {
       i++;
    }

    if(chaves[i] == k){
        cout<<"Chave encotrada: "<<chaves[i]<<endl;
        return this;
    }
    
    if(folha == true)
        return NULL;
    
    return filhos[i]->busca_no_No(k);
}

void NoArvB::imprime()
{   
    int i;
    for(i = 0; i<this->n;i++)
    {
        if(this->folha == false)
        {
            this->filhos[i]->imprime();
        }

        cout<<"Ch: "<< this->chaves[i] <<endl;

    }

    if(this->folha == false){
        this->filhos[i]->imprime();
    }
}
