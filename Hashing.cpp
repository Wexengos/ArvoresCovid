#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <math.h>

#include "Tabela.h"
#include "Hashing.h"
#include "Registro.h"

using namespace std;

Hashing::Hashing(int n)
{
    tam = n;
    tamPorao = n / 3;
    tamMax = tam + tamPorao;
    vet = new Tabela[tamMax];
    poraoLivre = tamMax - 1;
    chavesArmazenadas = 0;
    contaColisoes = 0;
}
Hashing::~Hashing()
{
    //delete vet;
};

int Hashing::funcaoHash(int val)
{
    double a = (sqrt(5) - 1) / 2;
    return floor(((val * a) - floor(val * a)) * tam);
}
int Hashing::insere(int codigo, Registro r)
{

    int h = funcaoHash(codigo);
    if (vet[h].getNext() == -2)
    {
        vet[h].setInfo(r);
        vet[h].setNext(-1);
        chavesArmazenadas++;
        return h;
    }
    else
    {
        contaColisoes++;
        if (poraoLivre >= tam)
        {

            vet[poraoLivre].setInfo(r);
            vet[poraoLivre].setNext(-1);
            vet[h].setNext(poraoLivre);
            int temp = poraoLivre;
            poraoLivre--;
            chavesArmazenadas++;
            return temp;
        }
        else
        {

            if (vet[tamMax - 1].getNext() == -1)
                for (int i = tam - 1; i >= 0; i--)
                {
                    if (vet[i].getNext() == -2)
                    {
                        vet[i].setInfo(r);
                        vet[i].setNext(-1);
                        vet[tamMax - 1].setNext(i);
                        chavesArmazenadas++;
                        return i;
                    }
                }
            else
            {
                int aux = vet[tamMax - 1].getNext();
                int res = 0;
                while (res != -1)
                {
                    if (vet[aux].getNext() == -1)
                    {
                        res = -1;
                    }
                    else
                    {
                        aux = vet[aux].getNext();
                    }
                }
                for (int i = aux; i >= 0; i--)
                {

                    if (vet[i].getNext() == -2)
                    {
                        vet[i].setInfo(r);
                        vet[i].setNext(-1);
                        vet[aux].setNext(i);
                        chavesArmazenadas++;
                        return i;
                    }
                }
            }
        }
    }
    return -1;
}
int Hashing::getCodigo(int i)
{
    return vet[i].getInfo().getCodigoCidade();
}
int Hashing::getData(int i)
{
    string str1 = vet[i].getInfo().getDataCompleta();
    string str2;

    for (int contador = 0; contador < str1.size(); contador++)
    {

        if (str1[contador] != '-')
        {
            str2 += str1[contador];
        }
    }
    int data = stoi(str2);

    return data;
}

void Hashing::imprime()
{
    cout << endl;
    for (int i = 0; i < tamMax; i++)
    {
        if (i == tam)
        {
            cout << "Porao: " << endl;
        }
           if(vet[i].getInfo().getCasos() != -1)
            {
                cout<< vet[i].getInfo().getCidade() << " ";
            }
        
    }
}
int Hashing::getChavesArmazenadas()
{
    return chavesArmazenadas;
}
int Hashing::getContaColisoes()
{
    return contaColisoes;
}
