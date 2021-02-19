#include <iostream> 
#include <cmath> 
#include "NoArvQuad.h"
using namespace std; 


class QuadTree
{
    private:
        
        NoArvQuad *raiz;
        NoArvQuad* auxInsere(NoArvQuad *r,NoArvQuad *p);
        void auxImprime(NoArvQuad *p);
      

    public:
        QuadTree();
        ~QuadTree();
        void insere(NoArvQuad *r);
        NoArvQuad* compara(NoArvQuad *r,NoArvQuad *p);
        NoArvQuad* quadrante(NoArvQuad *r,NoArvQuad *p);
        NoArvQuad* buscaValor(NoArvQuad *r);
        void imprime();
        
        


};



