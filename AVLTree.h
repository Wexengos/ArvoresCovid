#ifndef AVLTree_H
#define AVLTree_H
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "NoArv.h"

using namespace std;

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void imprime();
    void insere(int x);
    // Questao 1  -------------------------------------------------------------
    int numNosAltura(int a);
    // Questao 2  -------------------------------------------------------------
    int caminho(int ch);
    // Questao 3  -------------------------------------------------------------
    float mediaIntervalo(int a, int b);

    int impares();
    int soma();
    int maiorValor();
    int menorValor();
    int altura();
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
    NoArv* buscaValor(int val);
    int classificaNo(int val);
    void remove(int x);

private:
    NoArv *raiz;

    // funcoes auxiliares
    NoArv* auxInsere(NoArv *p, int x);
    void auxImprime(NoArv *p);
    void auxImpares(NoArv *p, int *impa);
    void auxSoma(NoArv *p, int *soma);
    void auxMaiorValor(NoArv *p, int *maior);
    void auxMenorValor(NoArv *p, int *menor);
    int auxAltura(NoArv *p);
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
};

#endif //AVLTree_H