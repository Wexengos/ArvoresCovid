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
//.teste

bool verificaCapital(string capital)
{
   
    string verifica = "TRUE";
    int comparaString= verifica.compare(capital);

    if(comparaString == 0)
    {
        return true;
    }
    return false;
}

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
        

        if(verificaCapital(capital))
        {
            notest->setCapital(true);

        }else{
            notest->setCapital(false);
        }

        arv->insere(notest);
        //cout<<"Latitude: "<<lat<<"/"<<"Longitude: "<<longe<<"/"<<"Nome da cidade: "<<nom<<endl;
         
        

        if(contaLinha>N)
            break;
        contaLinha++;

    }
    cout<<"Inserido->"<<contaLinha<<" na QuadTree"<<endl;
    arq.close();
    

}


int main(int argc, char *argv[])
{   
    
    QuadTree *arv = new QuadTree();

    primeiraLeitura(arv,5571);

    NoArvQuad *procura = new NoArvQuad();
    procura->setLatitude(-7.74149);
    procura->setLongitude(-35.2193);

   
    
    //arv->imprime();
    arv->buscaValor(procura);
    //arv->imprimeCapital();

    cout<<"Fim"<<endl;

    return 0;
    
}
