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
#include "Registro.h"
#include "RegistroCoordinates.h"
#define TAMANHOMAX 1431490



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

//Funções para teste das Estruturas para liberar a Main
void arvQuadTree(RegistroCoordinates *r, int N){

     QuadTree *arv = new QuadTree();
     int cont=0;
    
    //Isere os registros na ARVQUAD
    for(int i=1;i<N;i++)
    {
        NoArvQuad *no = new NoArvQuad();
        no->setLatitude(r[i].getLatitude());
        no->setLongitude(r[i].getLongitude());
        no->setNome(r[i].getcidade_nome());
        arv->insere(no);
        cont++;
    }

    cout<<"Cont: "<<cont<<endl;

    NoArvQuad *procura = new NoArvQuad();
    procura->setLatitude(-21.0276);
    procura->setLongitude(-44.3204);
   
    
    //arv->imprime();
    arv->buscaValor(procura);
    //arv->imprimeCapital();

    cout<<"Fim"<<endl; 

}

void avlTree(){

    AVLTree *piloto = new AVLTree();

    //TESTE ESQUERDA SIMPLES

    piloto->insere(10); piloto->insere(8);
    piloto->insere(16); piloto->insere(13);
    piloto->insere(19); piloto->insere(22);
    

    /*TESTE ESQUERDA DUPLA 

    piloto->insere(10); piloto->insere(8);
    piloto->insere(16); piloto->insere(14);
    piloto->insere(12); piloto->insere(22);
    
    piloto->imprime(); */

}

int main(int argc, char *argv[])
{   
    /*
    int tamanhoN[] = {10000, 50000, 100000, 500000, 1000000, TAMANHOMAX};
    Registro *registros = new Registro[tamanhoN[5]];

    registros->leArquivo(registros,tamanhoN[0]);
    registros->exibeRegistros(registros,tamanhoN[0]); 
    */

    int N = 5571;
    RegistroCoordinates *registrosCoordinate = new RegistroCoordinates[N];
    registrosCoordinate->leArquivoCoordi(registrosCoordinate,N);
    arvQuadTree(registrosCoordinate,N);
    

   
    return 0;
    
}
