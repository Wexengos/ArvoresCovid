#include <iostream> 
#include <cmath> 
using namespace std; 
#define N 5 //arv 5

class NoArvB
{
private:
    
    
    int chaves[2*N-1];
    NoArvB* filhos[2*N];
    int n=0;
    bool folha;
   

public:
    NoArvB(){folha = NULL;};
    void setChaves(int ch,int i){chaves[i]=ch;n++;};
    void setFilhos(NoArvB *filhos,int i){filhos[i]=*filhos;};
    void setFolha(bool fol){folha =  fol;};
    void setN(int num){n = num;}
    bool getFolha(){return folha;};
    int getN(){return n;};
    int getChave(int i){return chaves[i];};
    NoArvB* getFilhos(int i){return filhos[i];};
    void split(int i, NoArvB *p);
    void insertFilho(int k);
    void imprime();
    NoArvB* busca(int chave);


    
    ~NoArvB();
};

