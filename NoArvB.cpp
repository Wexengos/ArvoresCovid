#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "NoArvB.h"


using namespace std;

NoArvB::NoArvB(int tamanho,bool f)
{
    tam = tamanho;
    folha = f;
    chaves = new int [2*tam-1];
    filhos = new NoArvB * [2*tam];
    n = 0;
}

void NoArvB::split(int i,NoArvB *r, Hashing *tabela)
{
    cout<<"Split"<<endl;
    NoArvB *q = new NoArvB(r->getTam(),r->getFolha());
    q->setN(tam-1);
    
    int k;
    for(int j=0;j<tam-1;j++)
    {   
        //Transfere as chaves com valores maiores para o novo No
        q->setChave(j,r->getChaves(j+tam));
        //cout<<"Chaves K: "<<q->getChaves(j)<<endl;
        //cout<<"Chaves J: "<<r->getChaves(j+tam)<<endl;
    }

    if(r->getFolha()==false)
    {
        for(int j=0;j<tam;j++){
            q->setFilhos(j,r->getFilhos(j+tam));
        }

    }
    
    r->setN(tam-1);
    

    for(int j=n;j>=i+1;j--)
    {
        filhos[j+1]=filhos[j];
        this->setFilhos(j+1,this->getFilhos(j));
    }
    
    this->setFilhos(i+1,q);
   

    for (int j=n-1; j >= i; j--)
    {
       this->setChave(j + 1, this->getChaves(j)); 
    }
       
    
    this->setChave(i, r->getChaves(tam-1)); 
    //chaves[i]=q->chaves[tam-1];
    n=n + 1;
}


void NoArvB::insertFilho(int k, Hashing *tabela)
{
    int i = n-1;

    //cout<<"N: "<<n<<endl;
    //Se for folha inseria a chave na posição correta 
    if(folha==true){
        
        while (i>=0 && chaves[i]>k)
        {   
            //Ajusta as chaves dentro do No
            chaves[i+1]=chaves[i];
            i--;
        }

        
        chaves[i+1] = k;
        n=n+1;
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
       
        if(filhos[i+1]->getN()==2*tam-1)
        {
            split(i+1,filhos[i+1],tabela);

            if(chaves[i+1]<k)
                i++;
        }
       filhos[i+1]->insertFilho(k,tabela);
    }
   
}

NoArvB* NoArvB::busca_no_No(int k,Hashing tabela)
{
   int i=0;
    
    while (i<n && k>chaves[i])
    {
       i++;
    }

    if(chaves[i] == k){
        //cout<<"Chave encotrada: "<<chaves[i]<<endl;
        cout<<"Nome: "<<tabela.buscaNome(k);
        return this;
    }
    
    if(folha == true)
        return NULL;
    
    return filhos[i]->busca_no_No(k,tabela);
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
