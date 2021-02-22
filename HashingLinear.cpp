#include <iostream>
#include<vector>
#include<math.h>
#include "Balde.h"
#include "HashingLinear.h"

using namespace std;

HashingLinear::HashingLinear(int n)
{
    nivel = 0;
    numBaldeNivel = n;
    numBaldeTotal = 0;
    chavesArmazenadas = 0;
    for(int i =0; i < numBaldeNivel; i++)
    {
        adicionaBalde();
    }
    split = 0;
}
HashingLinear::~HashingLinear()
{
    vet.clear();
}
void HashingLinear::adicionaBalde()
{
    Balde b(10,5);
    vet.push_back(b);
    numBaldeTotal ++;
}
int HashingLinear::funcaoHGK(int val,int niv)
{


    int aux = 3*(pow(2,niv));
    int res = val%aux;
    return res;


}
float HashingLinear::fatorCarga(int nChaves, int tam, int nBaldes, int o)
{
    float b = nChaves;
    float c = (tam*nBaldes)+o;
    b = b/c;
    b = b*100;
    return b;
}
void HashingLinear::insere(int val)
{
    int h = funcaoHGK(val,nivel);
    if(h < split)
    {

        h = funcaoHGK(val,nivel+1);

    }
    int aux = vet[h].indiceDsponivel();
    if(aux == -1)
    {
        cout<<"Chave "<<val<<endl;
        cout<<"o balde esta cheio"<<endl;
        aumentaHash();
    }
    else
    {
        vet[h].setChave(aux,val);
    }
    chavesArmazenadas ++;
    if ((fatorCarga(chavesArmazenadas,vet[h].getTamBalde(),vet.size(),vet[h].getTamOverflow()) > 75.00))
    {
        aumentaHash();
    }

}
void HashingLinear::imprime()
{
    for(int i =0; i < vet.size(); i++)
    {
        cout<<"Balde "<<i<<":"<<endl;
        vet[i].imprime();
    }
}
void HashingLinear::resdribui()
{

    for(int i = 0; i < vet[split-1].getTamBalde(); i++)
    {
        if(funcaoHGK(vet[split-1].getChave(i),nivel+1 ) == vet.size()-1)
        {
            if(vet[split-1].getChave(i) != -1)
            {
                int temp = vet[split-1].getChave(i);
                vet[split-1].setChave(i,-1);
                chavesArmazenadas --;
                insere(temp);
            }


        }
    }

    for(int i = vet[split-1].getTamBalde(); i < vet[split-1].getTamBalde() + vet[split-1].getTamOverflow(); i++ )
    {

        if(vet[split-1].getChave(i) != -1)
        {
            int temp2 = vet[split-1].getChave(i);
            if(funcaoHGK(vet[split-1].getChave(i),nivel+1 ) == vet.size()-1)
            {

                vet[split-1].excluiElemento(i);
                chavesArmazenadas --;
                insere(temp2);
            }
            else
            {
                vet[split-1].excluiElemento(i);
                chavesArmazenadas --;
                insere(temp2);
            }
        }

    }

}
void HashingLinear::aumentaHash()
{
    adicionaBalde();
    split++;
    resdribui();
    if(split >= numBaldeNivel)
    {
        nivel++;
        split = 0;
        numBaldeNivel = numBaldeNivel*2;
    }
}
void HashingLinear::busca(int val)
{
    int h = funcaoHGK(val,nivel);
    if(h < split)
    {

        h = funcaoHGK(val,nivel+1);

    }
    vet[h].busca(val);

}
