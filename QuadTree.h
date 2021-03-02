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
        void auxCidadesNoIntervalo(NoArvQuad *p, float x0, float x, float y0, float y);
      

    public:
        QuadTree();
        ~QuadTree();
        void insere(NoArvQuad *r);
        NoArvQuad* compara(NoArvQuad *r,NoArvQuad *p);
        NoArvQuad* quadrante(NoArvQuad *r,NoArvQuad *p);
        NoArvQuad* buscaValor(NoArvQuad *r);
        void imprime();
        void imprimeCapital();
        void auxImprimeCapital(NoArvQuad *p);
        void cidadesNoIntervalo(float x0, float x, float y0, float y);
        
        


};



