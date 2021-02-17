#include <iostream> 
#include <cmath> 
using namespace std; 




struct Ponto
{   
    //Mudar para Long ou float
    int latitude;
    int longitude;

    Ponto(int latitude_,int longitude_)
    {
        latitude = latitude_;
        longitude = longitude_;
    }
    
    Ponto()
    {
        latitude = 0;
        longitude = 0;
    }

};

struct No
{
    Ponto position;
    //Mudar para string
    int info;
   

    No(Ponto pos_, int info_)
    {   
        position=pos_;
        info = info_;
    }

    No()
    {
        info = 0;
    }


};



class QuadTree
{
    private:
        Ponto cimaEsq;
        Ponto baixoDir;
        No *n;
        QuadTree *cimaEsqArv;
        QuadTree *cimaDirArv;
        QuadTree *baixoEsqArv;
        QuadTree *baixoDirArv;

    public:
        
        QuadTree();
        void setQuadTree(Ponto cimaEsq,Ponto baixoDir);
        void insere(No *);
        No* procura(Ponto);
        bool contemPonto(Ponto p);
        

};



