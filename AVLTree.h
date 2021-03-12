#ifndef AVLTree_H
#define AVLTree_H
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "NoArv.h"
#include "Hashing.h"

using namespace std;

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void imprime(Hashing *tabela);
    int comparaData(int x,NoArv *p,Hashing *tabela);
    int comparaCodigo(int x,NoArv *p,Hashing *tabela);
    int max(int, int);
    int getBalanceada(NoArv*);
    NoArv* veOBalanceio(NoArv* p);
    void insere(int x, Hashing *tabela);
    int impares();
    int soma();
    int maiorValor();
    int menorValor();
    int altura();
    int alturaNo(NoArv*);
    int numNos();
    bool eCheia();
    float media();
    int maiores(int val);
    void imprimeNivel(int k);
    float mediaNivel(int k);
    void imprimeFilhos(int x);
    void imprimeIntervalo(int x, int y);
    void imprimeCrescente();
    void imprimeDecrescente();
    void insereDoVetor1(int n, int *vet);
    void insereDoVetor2(int n, int *vet);
    void buscaCodigo(int codigo, int &cont, Hashing *tabela);
    int classificaNo(int val);
    void remove(int x);
    NoArv* rotacaoSimplesEsquerda(NoArv*);
    NoArv* rotacaoSimplesDireita(NoArv*);
    NoArv* rotacaoDuplaEsquerda(NoArv*);
    NoArv* rotacaoDuplaDireita(NoArv*);
    void imprimeTXT(Hashing *tabela,std::ofstream& myfile);

private:
    NoArv *raiz;

    // funcoes auxiliares
    NoArv* auxInsere(NoArv *p, int x,Hashing *tabela);
    void auxImprime(NoArv *p,Hashing *tabela);
    int auxAltura(NoArv* p);
    void auxImpares(NoArv *p, int *impa);
    void auxSoma(NoArv *p, int *soma);
    void auxMaiorValor(NoArv *p, int *maior);
    void auxMenorValor(NoArv *p, int *menor);
    void auxNumNos(NoArv *p, int *nos);
    void auxMedia(NoArv *p, int *cont, float *media);
    void auxMaiores(NoArv *p, int val, int *maior);
    void auxImprimeNivel(NoArv *p, int cont, int k);
    float auxMediaNivel(NoArv *p, int atual, int *cont, float *soma, int k);
    void auxImprimeIntervalo(NoArv *p, int x, int y);
    void auxImprimeCrescente(NoArv *p);
    void auxImprimeDecrescente(NoArv *p);
    NoArv* auxRemove(NoArv *p, int x);
    NoArv* removeFolha(NoArv *p);
    NoArv* removeNo1Filho(NoArv *p);
    NoArv* menorSubArvDireita(NoArv *p);
    void auxImprimeTXT(NoArv *p,Hashing *tabela,std::ofstream& myfile);
};

#endif //AVLTree_H