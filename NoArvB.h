#include <iostream> 
#include <cmath> 
using namespace std; 


class NoArvB
{
private:
    
    
    int *chaves;
    NoArvB **filhos;
    int n;
    bool folha;
    int tam;
   

public:
    NoArvB(int tamanho,bool f);
    void insertFilho(int k);
    void split(int i,NoArvB *p);
    void imprime();
    int getN(){return n;};
    int getTam(){return tam;};
    bool getFolha(){return folha;};
    void setN(int i){n+=i;};
    NoArvB* busca_no_No(int k); 
    ~NoArvB();

    friend class ArvB;
};

