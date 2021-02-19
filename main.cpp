#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm> 
#include <climits>
#include <stdio.h>
#include "QuadTree.h"
#include "AVLTree.h"



using namespace std;
using namespace std::chrono;
//g++ -o teste -O3 *.cpp 
//./teste

void primeiraLeitura(QuadTree *arv,int N)
{
    ifstream arq("brazil_cities_coordinates.csv");

    if(!arq.is_open()){
        cout<<"ERRO LEITURA DE ARQUIVO!"<<endl;
        return;
    }
    string linha,capital,nom,stringT,stringT2,stringT3,cidadeCodigo;
    int estadoCodigo;
    double lat,longe;
    int contaLinha = 0;

   //Pula a primeira linha; 
    getline(arq,linha);

    while (getline(arq,linha))
    {
        stringstream ss(linha);
        getline(ss,stringT,',');
        istringstream(stringParaInt);
        getline(ss,cidadeCodigo,',');
        getline(ss,nom,',');
        getline(ss,stringT2,',');
        istringstream(stringT2)>>lat;
        getline(ss,stringT3,',');
        istringstream(stringT3)>>longe;
        getline(ss,capital,',');
        
        NoArvQuad *notest = new NoArvQuad();
        notest->setLatitude(lat);
        notest->setLongitude(longe);
        notest->setNome(nom);

        arv->insere(notest);
        //cout<<"Latitude: "<<lat<<"/"<<"Longitude: "<<longe<<"/"<<"Nome da cidade: "<<nom<<endl;
         
        

        if(contaLinha>N)
            break;
        contaLinha++;

    }
    cout<<"Inserido->"<<contaLinha<<" na QuadTree"<<endl;
    arq.close();
    

}


int main(void)
{
    
    QuadTree *arv = new QuadTree();

    primeiraLeitura(arv,5571);
    
    /*
    NoArvQuad *notest = new NoArvQuad();
    notest->setLatitude(-23.1256);
    notest->setLongitude(-53.3678);
    notest->setNome("LULU");

    NoArvQuad *notest1 = new NoArvQuad();
    notest1->setLatitude(-12.74545);
    notest1->setLongitude(-6.85256);
    notest1->setNome("LULU2");

    
    NoArvQuad *notest2 = new NoArvQuad();
    notest2->setLatitude(-89.7874);
    notest2->setLongitude(-65.5532);
    notest2->setNome("LULU3");

    
    

    arv->insere(notest);
    arv->insere(notest1);
    arv->insere(notest2);

    */
   // arv->buscaValor(procura);
    

    NoArvQuad *procura = new NoArvQuad();
    procura->setLatitude(-27.2662);
    procura->setLongitude(-49.708);

   
    
    //arv->imprime();
    arv->buscaValor(procura);
    cout<<"Fim"<<endl;

    return 0;
    
}
