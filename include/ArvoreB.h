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
        int t; // Grau m�nimo do n�
        int m; // Grau m�ximo do n�
        int comparacaoBusca;
        int comparacaoInsercao;

        NoArvoreB * raiz; // N� raiz - array de ponteiros para os filhos do n�

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
