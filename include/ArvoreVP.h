#ifndef ARVOREVP_H
#define ARVOREVP_H
#include <bits/stdc++.h>

using namespace std;

const bool VERMELHO = true;
const bool PRETO = false;

class NoVP
{
    private:
        char * info;
        int posRegistro;
        bool cor;
        NoVP *dir, *esq, *pai;

    public:
        NoVP(char info[90], int posRegistro){
            this->info = info;
            this->posRegistro = posRegistro;
        };
        ~NoVP();

        int getPosicaoRegistro () {return this->posRegistro;};
        char * getInfo() {return info;};
        NoVP * getEsq() {return esq;};
        NoVP * getDir() {return dir;};
        NoVP * getPai() {return pai;};
        bool getCor() {return cor;};

        void setPosRegistro(int posRegistro) {this->posRegistro = posRegistro;};
        void setInfo(char val[90]) {info = val;};
        void setEsq(NoVP * e) {esq = e;};
        void setDir(NoVP * d) {dir = d;};
        void setPai(NoVP * p) {pai = p;};
        void setCor(bool c) {cor = c;};

        void imprime(){cout << endl << "Registro n : " << this->posRegistro << " : " << info;};
};

class ArvoreVP
{
    private:
        int comparacaoInsercao;
        int comparacaoBusca;
        NoVP * sentinela;
        NoVP * raiz;
        bool balanceado;

    public:
        ArvoreVP();
        ~ArvoreVP();
        NoVP * libera(NoVP * p);

        bool busca(char chave[90]);
        bool buscaAux(NoVP * p, char chave[90]);

        int buscaRetornaPosID(char chave[90]);
        bool buscaRetornaPosIDAux(NoVP * p, char chave[90], int * posID);

        void insere(char chave[90], int pos);
        NoVP * insereAux(NoVP * p, char chave[90], int pos);

        void imprime();
        void imprimeAux(NoVP * p);

        void imprimePorNivel();
        void imprimePorNivelAux(NoVP * p, int k);

        NoVP * balancear(NoVP * p);

        void rotSimplesEsq(NoVP * p);
        void rotSimplesDir(NoVP * p);

        int getComparacaoInsercao() {return this->comparacaoInsercao;};
        int getComparacaoBusca() {return this->comparacaoBusca;};

        void zeraComparacoes();
};
#endif // ARVOREVP_H
