#include <vector>
#ifndef BALDE_H_INCLUDED
#define BALDE_H_INCLUDED


using namespace std;

class Balde
{
private:
    int* balde;
    int tamBalde;
    int tamOverflow;

public:
    Balde(int tBalde,int tOverflow);
    ~Balde();
    int getChave(int i);
    void setChave(int i, int val);
    int getTamBalde();
    int getTamOverflow();
    int indiceDsponivel();
    void excluiElemento(int i);
    bool baldeCheio();
    void imprime();
    void busca(int val);




} ;

#endif // BALDE_H_INCLUDED
