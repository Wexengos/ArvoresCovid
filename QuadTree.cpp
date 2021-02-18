#include <iostream>
#include <cmath>
#include "QuadTree.h"

using namespace std;

struct Ponto;
struct No;


QuadTree::QuadTree()
{       
        
        this->cimaEsq = Ponto(0,0);
        this->baixoDir = Ponto(0,0);
        this->cimaEsqArv=NULL;
        this->cimaDirArv=NULL;
        this->baixoEsqArv=NULL;
        this->baixoDirArv=NULL;
        this->n=NULL;

}

void QuadTree::setQuadTree(Ponto cimaEsq,Ponto baixoDir)
{
        this->cimaEsq = cimaEsq;
        this->baixoDir = baixoDir;
        this->cimaEsqArv=NULL;
        this->cimaDirArv=NULL;
        this->baixoEsqArv=NULL;
        this->baixoDirArv=NULL;
        this->n=NULL;
}


void QuadTree::insere(No *no)
{

    if (no == NULL)
        return;

    if (!contemPonto(no->position))
        return;

    if (abs(cimaEsq.latitude - baixoDir.latitude) <= 1 && abs(cimaEsq.longitude - baixoDir.longitude) <= 1)
    {
        if (n == NULL)
            n = no;
        return;
    }

    if ((cimaEsq.latitude + baixoDir.latitude) / 2 >= no->position.latitude)
    {
        //Arvore cimaEsq

        if ((cimaEsq.longitude + baixoDir.longitude) / 2 >= no->position.longitude)
        {
            if (cimaEsqArv == NULL){
                cimaEsqArv = new QuadTree();
                cimaEsqArv->setQuadTree(Ponto(cimaEsq.latitude, cimaEsq.longitude), Ponto((cimaEsq.latitude + baixoDir.latitude) / 2, (cimaEsq.longitude + baixoDir.longitude) / 2));
            }
            
            cimaEsqArv->insere(no);
        }
        else
        {
            if (baixoEsqArv == NULL){
                baixoEsqArv = new QuadTree();
                baixoEsqArv->setQuadTree(Ponto(cimaEsq.latitude, (cimaEsq.longitude + baixoDir.longitude) / 2), Ponto((cimaEsq.latitude + baixoDir.latitude) / 2, baixoDir.longitude));
            }
           
            baixoEsqArv->insere(no);

       
        }


       
    }else
    {
        if((cimaEsq.longitude + baixoDir.longitude)/2 >= no->position.longitude)
        {
            if(cimaDirArv == NULL){
                cimaDirArv = new QuadTree();
                cimaDirArv->setQuadTree(Ponto((cimaEsq.latitude + baixoDir.latitude)/2,cimaEsq.longitude),Ponto(baixoDir.latitude,(cimaEsq.longitude + baixoDir.longitude)/2));
            }
              
            cimaDirArv->insere(no);
        }
        else
        {
            if(baixoDirArv == NULL){
                baixoDirArv = new QuadTree();
                baixoDirArv->setQuadTree(Ponto((cimaEsq.latitude + baixoDir.latitude)/2,(cimaEsq.longitude + baixoDir.longitude)/2),Ponto(baixoDir.latitude, baixoDir.longitude));
            }
            
            baixoDirArv->insere(no);
        }
    }
  

    }
    No* QuadTree::procura(Ponto p)
    {
        if(!contemPonto(p))
            return NULL;
        
        if(n!=NULL)
            return n;
        
        if((cimaEsq.latitude + baixoDir.latitude)/2 >= p.latitude)
        {   
            if((cimaEsq.longitude + baixoDir.longitude)/2 >= p.longitude)
            {
                if(cimaEsqArv == NULL)
                    return NULL;
                return cimaEsqArv->procura(p);
             }
            else
            {
                if(baixoEsqArv == NULL)
                    return NULL;
                return baixoEsqArv->procura(p);
            }
        }else
        {
            if((cimaEsq.longitude + baixoDir.longitude)/2 >= p.longitude)
            {
                if(cimaDirArv == NULL)
                    return NULL;
                return cimaDirArv->procura(p);
            }else
            {
                if(baixoDirArv == NULL)
                    return NULL;
                return baixoDirArv->procura(p);
            }
        }
    }

    bool QuadTree::contemPonto(Ponto p)
    {
        return (p.latitude >= cimaEsq.latitude && 
                p.latitude <= baixoDir.latitude &&
                p.longitude >= cimaEsq.longitude && 
                p.longitude <= baixoDir.longitude);
    }
    
    