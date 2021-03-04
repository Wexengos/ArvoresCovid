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
#include "ArvB.h"
#include "RegistroCoordinates.h"


using namespace std;


using namespace std::chrono;
#define TAMANHOMAX 1431490
#define QUANTCIDADES 5571

//g++ -o teste -O3 *.cpp 
//.teste

void criaArquivoSaidaTxt(string nomeArquivo){
    ofstream arq(nomeArquivo);
    arq.close();
}

void testeQuadTree(RegistroCoordinates *registroCidades,int N)
{   
    
    QuadTree *quad = new QuadTree();

    //arq."Cidades Inseridades na QuadTree"<<endl;

    for(int i = 0; i < N; i++)
    {   
        NoArvQuad *no = new NoArvQuad();
        no->setLatitude(registroCidades[i].getLatitude());
        no->setLongitude(registroCidades[i].getLongitude());
        no->setNome(registroCidades[i].getcidade_nome());
        quad->insere(no);
        //arq<<"Nome Cidade: "<<no->getNome()<<endl;
    }

    if(N <= 20){
        cout<<"Saida Console"<<endl;
        quad->imprime(); 
    }else{
        cout<<"Arquivo TXT criado"<<endl;
        ofstream arq;// ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("QuadTreeTXT", ios::ate| ios::out | ios::in);
        quad->imprimeTXT(arq);
        arq.close();
    }
    
    cout<<"Final"<<endl;



}

void testeHash(Registro *registro,int N)
{   
    
    Hashing *hash = new Hashing(N);

    //arq."Cidades Inseridades na QuadTree"<<endl;

    for(int i = 0; i < N; i++)
    {   
        int chave = registro[i].getCodigoCidade() + registro[i].getDataInt();
        hash->insere(chave,registro[i]);
        
    }

    if(N <= 20){
        cout<<"Saida no Console ===> Cidades Inseridas na Hash"<<endl;
        hash->imprime();

    }else{
        cout<<"Arquivo TXT criado"<<endl;
        ofstream arq;// ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("HashingTXT", ios::ate| ios::out | ios::in);
        hash->imprimeTXT(arq); 
        hash->casosTotaisCidade(330010);
        arq.close();
    }
    
    cout<<"Final"<<endl;



}

void moduloTeste(Registro *registro, RegistroCoordinates *registroCidades)
{   
    
    int menuTeste,n;
    cout << "===============Modulo de Teste===============" << endl;
    cout << "[1] Inserção de N cidades na quad tree"<<endl;
    cout << "[2] Inserção de N registros na tabela hash "<<endl;
    cout << "[3] Inserção de N chaves na árvore AVL"<<endl;
    cout << "[4] Inserção de N chaves na árvore B"<<endl;
    
    cin>> menuTeste;

    
    
    switch (menuTeste)
    {
    case 1:
            cout<<"Digite N cidades que sera inseridas"<<endl;
            cin >> n;
            criaArquivoSaidaTxt("QuadTreeTXT");
            testeQuadTree(registroCidades,n);

        break;
    case 2:
            cout<<"Digite  N registro que sera inseridos"<<endl;
            cin >> n;
            criaArquivoSaidaTxt("HashingTXT");
            testeHash(registro,n);
            
        break;
    case 3:
            cout<<"Digite N chaves que sera inseridas na AVL"<<endl;
            cin >> n;
        break;
    
    case 4:
            cout<<"Digite N cidades que sera inseridas na ARV B"<<endl;
            cin >> n;

        break;
    
    default:
        break;
    }

}   



int main(int argc, char *argv[])
{   
    setlocale(LC_ALL,"UTF-8");

    int tamanhoN[] = {10000, 50000, 100000, 500000, 1000000, TAMANHOMAX};
    Registro *registros = new Registro[tamanhoN[5]];
    registros->leArquivo(registros,tamanhoN[5]);
    registros->transformaCasosAcumuladosEmCasosDiarios(registros,tamanhoN[5]);


    RegistroCoordinates *registrosCoordinate = new RegistroCoordinates[QUANTCIDADES];
    registrosCoordinate->leArquivoCoordi(registrosCoordinate,QUANTCIDADES);
    
    moduloTeste(registros,registrosCoordinate);
   
    
    return 0;
    
}
