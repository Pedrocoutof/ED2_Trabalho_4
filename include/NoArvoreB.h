#ifndef NOARVOREB_H_INCLUDED
#define NOARVOREB_H_INCLUDED

#include <iostream>
using namespace std;
#include <string>
#include "InfoNo.h"

using namespace std;
class NoArvoreB
{
    private:
        int t; // Grau m�nimo do n�
        int m; // Grau m�ximo do n�

        InfoNo* chaves; // Array com as chaves do N�
        NoArvoreB ** no; // Array de ponteiros para os filhos do n�
        int n; // N�mero de Chaves atuais (n�s dentro de um n�)
        bool folha; // Define se o N� � uma folha ou n�o

    public:
        NoArvoreB(int t, bool folha);
        void insertEmpty(InfoNo k, int * comparacaoInsercao);
        void insertSplitChild(int index, NoArvoreB* overflow, int * comparacaoInsercao);
        NoArvoreB* busca(string k, int * comparacaoBusca);
        NoArvoreB* buscaRetornaID(string k, int * comparacaoBusca, int * posID);
        void imprimeNo();

        InfoNo getChaves(int n);
        void setChaves(InfoNo k);
        int getN();
        void setN(int n);
        NoArvoreB * getNo(int i);
        void setNo(int i, NoArvoreB *raiz);
};

#endif // NOARVOREB_H_INCLUDED
