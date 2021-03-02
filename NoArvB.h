#include <iostream> 
#include <cmath> 
#include "Hashing.h"


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
    void insertFilho(int k,Hashing *tabela);
    void split(int i,NoArvB *p,Hashing *tabela);
    void imprime();
    int getN(){return n;};
    int getTam(){return tam;};
    bool getFolha(){return folha;};
    void setN(int i){n=i;};
    void setFilhos(int i, NoArvB *f){filhos[i]=f;};
    void setChave(int i,int ch){chaves[i]=ch;};
    NoArvB* getFilhos(int i){return filhos[i];};
    int getChaves(int i){return chaves[i];};
    int comparaChaveHashing(int ch,Hashing *tabela);

    NoArvB* busca_no_No(int k,Hashing tabela); 
    ~NoArvB();

    friend class ArvB;
};

