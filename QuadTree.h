#include <iostream> 
#include <cmath> 
using namespace std; 

struct Ponto
{   
    //Mudar para Long ou float
    float latitude;
    float longitude;

    Ponto(float latitude_,float longitude_)
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
    string nome;
    string capital;
   

    No(Ponto pos_, string nom, string _capital)
    {   
        position=pos_;
        nome = nom;
        capital = _capital;
    }

    No()
    {
        nome=nullptr;
        capital = false;
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
        void imprimiTree(No *aux);
        

};



