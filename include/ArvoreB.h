#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "TiktokReviews.h"
#include "NoArvoreB.h"

class ArvoreB
{
    private:
        int t; // Grau mínimo do nó
        int m; // Grau máximo do nó
        int comparacaoBusca;
        int comparacaoInsercao;

        NoArvoreB * raiz; // Nó raiz - array de ponteiros para os filhos do nó

        //string LastNameInsert;

    public:
        ArvoreB(int t);
        NoArvoreB * busca(string k);
        int buscaRetornaPosicaoID(string k);

        void insere(string k, int posID);
        void imprimeArvore();

        int getComparacaoBusca() {return this->comparacaoBusca;};
        int getComparacaoInsercao() {return this->comparacaoInsercao;};

        int getOrdem();

        void zeraComparacoes();
};

#endif // BTREE_H_INCLUDED
