#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm> 
#include <climits>
#include "QuadTree.h"

using namespace std;

QuadTree::QuadTree()
{
    raiz = NULL;
}

QuadTree::~QuadTree()
{
  
}

NoArvQuad* QuadTree::compara(NoArvQuad *r,NoArvQuad *p)
{
    
    if(p->getLatitude()<r->getLatitude()){

        if(p->getLongitude()<r->getLongitude())
            return p->getSW();
        else
            return p->getNW();
    }else{

        if(p->getLongitude()<r->getLongitude())
            return p->getSE();
        else
            return p->getNE();
    }

}

NoArvQuad* QuadTree::quadrante(NoArvQuad *q,NoArvQuad *p)
{
    
    if(p->getLatitude()<q->getLatitude()){

        if(p->getLongitude()<q->getLongitude())
            return q->getSW();
        else
            return q->getNW();
    }else{

        if(p->getLongitude()<q->getLongitude())
            return q->getSE();
        else
            return q->getNE();
    }
}

void QuadTree::insere(NoArvQuad *r){

    NoArvQuad *p = auxInsere(raiz,r);

    if(raiz == NULL){
        raiz = p;

    }


}

NoArvQuad* QuadTree::auxInsere(NoArvQuad *p,NoArvQuad *r)
{
    if(p==NULL)
    {   
        
        p=new NoArvQuad();
        p->setLatitude(r->getLatitude());
        p->setLongitude(r->getLongitude());
        p->setNome(r->getNome());
        p->setNE(NULL);
        p->setNW(NULL);
        p->setSE(NULL);
        p->setSW(NULL);
      
    }else if(p->getLatitude()<r->getLatitude()){

        if(p->getLongitude()<r->getLongitude())
             p->setSW(auxInsere(p->getSW(),r));
        else
            p->setNW(auxInsere(p->getNW(),r));
    }else{

        if(p->getLongitude()<r->getLongitude())
            p->setSE(auxInsere(p->getSE(),r));
        else
            p->setNE(auxInsere(p->getNE(),r));
    }
    return p;
}

void QuadTree::imprime()
{   
   
    auxImprime(raiz);
    
    cout << endl;
}

void QuadTree::auxImprime(NoArvQuad *p)
{   
    

    if(p!=NULL)
    {   
        
        cout<<"Nome: "<<p->getNome()<<"/Lat: "<<p->getLatitude()<<"/Long: "<<p->getLongitude()<<endl;
        auxImprime(p->getSW());
        auxImprime(p->getNW());
        auxImprime(p->getSE());
        auxImprime(p->getNE());   
       
    }
}

void QuadTree::imprimeCapital()
{   
   
    auxImprimeCapital(raiz);
    
    cout << endl;
}

void QuadTree::auxImprimeCapital(NoArvQuad *p)
{   
    

    if(p!=NULL)
    {   
        
        if(p->getCapital()){
            cout<<"Nome Capital: "<<p->getNome()<<endl;
            

        }
        auxImprimeCapital(p->getSW());
        auxImprimeCapital(p->getNW());
        auxImprimeCapital(p->getSE());
        auxImprimeCapital(p->getNE());   
       
    }
}

NoArvQuad* QuadTree::buscaValor(NoArvQuad *p)
{
    
    NoArvQuad *q = raiz;
    if(raiz == NULL)
    {
        cout<<"Arvore vazia"<<endl;
        return NULL;

    }else
    {
        while (q!=NULL)
        {

            
            if((p->getLatitude() == q->getLatitude() )&& (p->getLongitude()==q->getLongitude()))
            {
                cout<<"Achado"<<endl;
                cout<<"Nome Cidade: "<<q->getNome()<<"/Lat: "<<q->getLatitude()<<"/Longe: "<<q->getLongitude()<<endl;
                return q;
            }else if(q->getLatitude()<p->getLatitude()){

                    if(q->getLongitude()<p->getLongitude())
                        q=q->getSW();
                    else
                        q=q->getNW();
            }else{

                if(q->getLongitude()<p->getLongitude())
                    q=q->getSE();
                else
                    q=q->getNE();
            }
        
            cout<<"N tem"<<endl; 
        }
        
        return NULL; 
    }

}