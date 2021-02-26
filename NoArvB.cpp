#include <iostream>
#include <cstdlib>
#include <stdio.h>
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

void NoArvB::split(int i,NoArvB *r)
{
    NoArvB *q = new NoArvB(r->tam,r->folha);
    q->n = tam - 1;

    for(int j=tam+1 ;j<2*tam;j++)
    {   
        //Transfere as chaves com valores maiores para o novo No
        q->chaves[j] = r->chaves[j];
        cout<<" "<<q->chaves[j]<<endl;
    }

    if(r->folha==false)
    {
        for(int j=tam+1;j<2*tam;j++){
            q->filhos[j] = r->filhos[j];
        }

    }

    r->n=tam-1;

    for(int j=n;j>=i+1;j--)
    {
        filhos[j+1]=filhos[j];
    }
    
    filhos[i+1]=q;

    for (int j = n - 1; j >= i; j--)
    {
        chaves[j + 1] = chaves[j]; 
    }
       
   

    chaves[i] = q->chaves[tam - 1];
    n = n + 1;
}


void NoArvB::insertFilho(int k)
{
    int i = n - 1;

    //Se for folha inseria a chave na posição correta 
    if(folha==true){

        while (i>=0 && chaves[i]>k)
        {   
            //Ajusta as chaves dentro do No
            chaves[i+1]=chaves[i];
            i--;
        }
        
        chaves[i+1] = k;
        cout<<"Inserido: "<<chaves[i+1]<<endl;
        n=n+1;

    }else{
        
        while (i>=0 && chaves[i]>k)
        {
            i--;
        }
        
        if(filhos[i+1]->n == 2*tam-1)
        {
            split(i+1,filhos[i+1]);

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
    for(i = 0; i<n;i++)
    {
        if(folha == false)
        {
            filhos[i]->imprime();
        }

        cout<<"Ch: "<< chaves[i] <<endl;

    }

    if(folha == false){
        filhos[i]->imprime();
    }
}
