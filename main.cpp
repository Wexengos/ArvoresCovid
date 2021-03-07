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

void criaArquivoSaidaTxt(string nomeArquivo)
{
    ofstream arq(nomeArquivo);
    arq.close();
}

void testeQuadTree(RegistroCoordinates *registroCidades, int N)
{

    QuadTree *quad = new QuadTree();

    //arq."Cidades Inseridades na QuadTree"<<endl;
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        NoArvQuad *no = new NoArvQuad();
        no->setLatitude(registroCidades[i].getLatitude());
        no->setLongitude(registroCidades[i].getLongitude());
        no->setNome(registroCidades[i].getcidade_nome());
        quad->insere(no);
        //arq<<"Nome Cidade: "<<no->getNome()<<endl;
    }
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    int tem = duration_cast<duration<double>>(fim - inicio).count();
    if (N <= 20)
    {
        cout << "Saida Console" << endl;
        quad->imprime();
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("QuadTreeTXT", ios::ate | ios::out | ios::in);
        quad->imprimeTXT(arq);
        arq << "Tempo: " << tem << endl;
        arq.close();
    }

    cout << "Final" << endl;
}

void testeHash(Registro *registro, int N)
{

    Hashing *hash = new Hashing(N);
    int cont = 0;
    register int chave, id;
    //arq."Cidades Inseridades na QuadTree"<<endl;
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        //cout<<"Cidade "<<registro[i].getCidade()<<"foi visitada? "<<registro[i].getVisitado()<<endl;
        chave = registro[i].getCodigoCidade() + registro[i].getDataInt();
        id = hash->insere(chave, &registro[i]);
        cont++;
        //cout<<"id=> "<<id<<endl;
        //cout<<"chave: "<<chave<<endl;
        //cout<<"id: "<<id<<endl;
    }
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    double tem = duration_cast<duration<double>>(fim - inicio).count();
    if (N <= 20)
    {
        cout << "Saida no Console ===> Cidades Inseridas na Hash" << endl;
        hash->imprime();
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("HashingTXT", ios::ate | ios::out | ios::in);
        hash->imprimeTXT(arq);
        hash->casosTotaisCidade(330010);
        arq << "Tempo: " << tem << endl;
        arq.close();
    }
    cout << endl;
    cout << "Ch: " << hash->getChavesArmazenadas() << endl;
    cout << "Teste finalizado" << endl;
}
void testeAvl(Registro *registro, int N)
{
    Hashing *hash = new Hashing(N);
    int cont = 0;
    register int chave, id;
    AVLTree *avl = new AVLTree();

    for (int i = 0; i < N; i++)
    {
        chave = registro[i].getCodigoCidade() + registro[i].getDataInt();
        id = hash->insere(chave, &registro[i]);
        avl->insere(id, hash);
    }

    if (N <= 20)
    {
        cout << "Saida no Console ===> Cidades Inseridas na Hash" << endl;
        avl->imprime(hash);
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("AvlTXT", ios::ate | ios::out | ios::in);
        avl->imprimeTXT(hash, arq);
        arq.close();
    }
    cout << endl;
    cout << "Teste finalizado" << endl;
    hash->~Hashing();
}
void testeAVB(Registro *registro, int N)
{
    Hashing *hash = new Hashing(N);
    int cont = 0;
    register int chave, id;
    ArvB *arvB = new ArvB(3);

    for (int i = 0; i < N; i++)
    {
        chave = registro[i].getCodigoCidade() + registro[i].getDataInt();
        id = hash->insere(chave, &registro[i]);
        arvB->insereArvB(id, hash);
    }

    if (N <= 20)
    {
        cout << "Saida no Console ===> Cidades Inseridas na Hash" << endl;
        arvB->imprimeArv(hash);
    }
    else
    {
        cout << "Arquivo TXT criado" << endl;
        ofstream arq; // ("a:lista.dat", ios::ate | ios::out | ios::in)
        arq.open("AvBTXT", ios::ate | ios::out | ios::in);
        arvB->imprimeArvTXT(hash, arq);
        arq.close();
    }
    cout << endl;
    cout << "Teste finalizado" << endl;
    hash->~Hashing();
}

void moduloTeste(Registro *registro, RegistroCoordinates *registroCidades)
{

    int menuTeste, n;
    cout << "===============Modulo de Teste===============" << endl;
    cout << "[1] Inserção de N cidades na quad tree" << endl;
    cout << "[2] Inserção de N registros na tabela hash " << endl;
    cout << "[3] Inserção de N chaves na árvore AVL" << endl;
    cout << "[4] Inserção de N chaves na árvore B" << endl;

    cin >> menuTeste;

    switch (menuTeste)
    {
    case 1:
        cout << "Digite N cidades que sera inseridas" << endl;
        cin >> n;
        criaArquivoSaidaTxt("QuadTreeTXT");
        testeQuadTree(registroCidades, n);
        moduloTeste(registro, registroCidades);

        break;
    case 2:
        cout << "Digite  N registro que sera inseridos" << endl;
        cin >> n;
        criaArquivoSaidaTxt("HashingTXT");
        testeHash(registro, n);
        moduloTeste(registro, registroCidades);

        break;
    case 3:
        cout << "Digite N chaves que sera inseridas na AVL" << endl;
        cin >> n;
        criaArquivoSaidaTxt("AvlTXT");
        testeAvl(registro, n);
        moduloTeste(registro, registroCidades);
        break;

    case 4:
        cout << "Digite N cidades que sera inseridas na ARV B" << endl;
        cin >> n;
        criaArquivoSaidaTxt("AvBTXT");
        testeAVB(registro, n);
        moduloTeste(registro, registroCidades);

        break;

    default:
        break;
    }
}
/*void menuPrincipal(RegistroCoordinates *registrosCoordinate, Registro *registros)
{
    int menu;
    cout << "====================MENU PRINCIPAL====================" << endl;
    cout << "Digite:" << endl;
    cout << "[1] Carregar o arquivo de cicades " << endl;
    cout << "[2] Carregamento do arquivo pré-processado de casos" << endl;
    cout << "[3] Módulo de testes" << endl;
    cout << "[4] Análise das estruturas balanceadas" << endl;
    cout << "[5] para encerrar o programa" << endl;
    cin >> menu;
    switch(menu)
    {
    case 1:
        registrosCoordinate->leArquivoCoordi(registrosCoordinate, QUANTCIDADES);
        QuadTree* quadPrincipal = new QuadTree();
        for (int i = 0; i < QUANTCIDADES; i++)
        {
            NoArvQuad *no = new NoArvQuad();
            no->setLatitude(registrosCoordinate[i].getLatitude());
            no->setLongitude(registrosCoordinate[i].getLongitude());
            no->setNome(registrosCoordinate[i].getcidade_nome());
            quadPrincipal->insere(no);
        }
        cout << "Etapa 1 concluida!" << endl;
        break;
    case 2:
        int tamanhoN[] = {10000, 50000, 100000, 500000, 1000000, TAMANHOMAX};
        registros->leArquivo(registros,tamanhoN [5]);
        registros->transformaCasosAcumuladosEmCasosDiarios(registros,tamanhoN [5]);
        Hashing* hashPrincipal = new Hashing(tamanhoN [5]);
        register int chave, id;
        for (int i = 0; i < tamanhoN [5]; i++)
        {
            chave = registros[i].getCodigoCidade() + registros[i].getDataInt();
            id = hashPrincipal->insere(chave, &registros[i]);
        }
        cout << "Etapa 2 concluida!" << endl;
        break;
    case 3:
        moduloTeste(registros, registrosCoordinate);
        cout << "Etapa 3 concluida!" << endl;

        break;
        case 4:
         break;
    case 5:
        break;
    default:
        cout << "valor invalido" << endl;
        break;
    }
    cout << "Fim" << endl;*/
}

int main(int argc, char *argv[])
{
    /*setlocale(LC_ALL, "UTF-8");
    RegistroCoordinates *registrosCoordinate = new RegistroCoordinates[QUANTCIDADES];
    Registro *registros = new Registro[TAMANHOMAX];
    menuPrincipal(registrosCoordinate, registros);*/

    /int tamanhoN[] = {10000, 50000, 100000, 500000, 1000000, TAMANHOMAX};
    Registro *registros = new Registro[tamanhoN[5]];
    registros->leArquivo(registros,tamanhoN[5]);
    //registros->transformaCasosAcumuladosEmCasosDiarios(registros,tamanhoN[5]);


    RegistroCoordinates *registrosCoordinate = new RegistroCoordinates[QUANTCIDADES];
    registrosCoordinate->leArquivoCoordi(registrosCoordinate,QUANTCIDADES);
    moduloTeste(registros,registrosCoordinate);

    return 0;
}
