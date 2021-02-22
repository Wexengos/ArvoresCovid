#include "Balde.h"
#ifndef HASHINGLINEAR_H_INCLUDED
#define HASHINGLINEAR_H_INCLUDED

using namespace std;

class HashingLinear
    {
        private:
        vector<Balde>vet;
        int nivel;
        int numBaldeTotal;
        int numBaldeNivel;
        int chavesArmazenadas;
        int split;

        public:
            HashingLinear(int n);
            ~HashingLinear();
            int funcaoHGK(int val,int niv);
            float fatorCarga(int nChaves, int tam, int nbalde, int o);
            void adicionaBalde();
            void insere(int n);
            void imprime();
            void resdribui();
            void aumentaHash();
            void busca(int val); //tabela hash


    };


#endif // HASHINGLINEAR_H_INCLUDED
