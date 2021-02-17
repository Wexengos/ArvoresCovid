#include <iostream>
#include <cmath>
#include "QuadTree.h"

using namespace std;

// g++ -o teste.exe main.cpp 

int main()
{
    //QuadTree *centro = new QuadTree();
    QuadTree *centro = new QuadTree(); 
   

    
    centro->setQuadTree(Ponto(0,0),Ponto(8,8));
 
    No a(Ponto(1,1),1);
    No b(Ponto(2,5),2);
    No c(Ponto(7,6),3);
    
    

    centro->insere(&a);
    centro->insere(&b);
    centro->insere(&c);

    cout<<"Final"<<endl;
    
    
    cout<<"No A: "<<centro->procura(Ponto(1,1))->info<<endl;
    cout<<"No B: "<<centro->procura(Ponto(2,5))->info<<endl;
    cout<<"No C: "<<centro->procura(Ponto(7,6))->info<<endl;
    cout<<"No Q n tem nessa buceta: "<<centro->procura(Ponto(5,5))<<endl;
    
    return 0;
}
