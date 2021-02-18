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

void primeiraLeitura(QuadTree *centro,int N)
{
    ifstream arq("brazil_cities_coordinates.csv");

    if(!arq.is_open()){
        cout<<"ERRO LEITURA DE ARQUIVO!"<<endl;
        return;
    }
    string linha,capital,nome,stringT,stringT2,stringT3,cidadeCodigo;
    int estadoCodigo;
    float lat,longe;
    int contaLinha = 0;

   //Pula a primeira linha; 
    getline(arq,linha);

    while (getline(arq,linha))
    {
        stringstream ss(linha);
        getline(ss,stringT,',');
        istringstream(stringParaInt);
        getline(ss,cidadeCodigo,',');
        getline(ss,nome,',');
        getline(ss,stringT2,',');
        istringstream(stringT2)>>lat;
        getline(ss,stringT3,',');
        istringstream(stringT3)>>longe;
        getline(ss,capital,',');
        

        Ponto ponto(lat,longe);//criando ponto
        No no(ponto,nome,capital);//criando no
        cout<<"Latitude: "<<ponto.latitude<<"/"<<"Longitude: "<<ponto.longitude<<"/"<<"Nome da cidade: "<<nome<<endl;
         
        centro->insere(&no);// inserindo info da linha

        if(contaLinha>N)
            break;
        contaLinha++;

    }
    cout<<"Inserido->"<<contaLinha<<" na QuadTree"<<endl;
    arq.close();
    

}

int main()
{
    
    QuadTree *centro = new QuadTree(); 
    centro->setQuadTree(Ponto(-100,-100),Ponto(0,0));


    //primeiraLeitura(centro,5571);

    AVLTree *robinho = new AVLTree();
    robinho->insere(12); robinho->insere(51);
    robinho->insere(54); robinho->insere(11);
    robinho->insere(28); robinho->insere(99);

    robinho->imprime();

    cout << "a altura de robinho eh " << robinho->altura() << endl;

    return 0;
    
}
