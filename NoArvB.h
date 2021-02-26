#include <iostream> 
#include <cmath> 
using namespace std; 


class NoArvB
{
private:
    
    
    int *chaves;
    NoArvB **filhos;
    int n=0;
    bool folha;
    int tam;
   

public:
    NoArvB(int tamanho,bool f);
    void insertFilho(int k);
    void split(int i,NoArvB *p);
    void imprime();
    NoArvB* busca_no_No(int k); 
    ~NoArvB();

    friend class ArvB;
};

