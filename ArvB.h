#include <iostream>
#include <cstdlib>
#include <math.h>
#include "NoArvB.h"

using namespace std;

class ArvB
{
private:
    NoArvB *raiz;
public:
    ArvB();
    ~ArvB();
    //NoArvB* buscaArvB(int chave, NoArvB *p);
    void insereArvB(int chave);
    void imprimeArv();
    NoArvB* busca(int chave);
};


