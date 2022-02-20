#ifndef ARVOREBIN_H
#define ARVOREBIN_H

class NoArvBin
{
    private:
        NoArvBin *esq; // ponteiro para o filho � esquerda
        int info; // informa��o do n� (int)
        NoArvBin *dir; // ponteiro para o filho � direita
    public:
        NoArvBin() {}; //construtor e destrutor
        ~NoArvBin() {};
        void setEsq(NoArvBin *p) { esq = p;}; //opera��es setter
        void setInfo(int val) { info = val;};
        void setDir(NoArvBin *p) { dir = p;};
        NoArvBin* getEsq() { return esq;}; //opera��es getter
        int getInfo() { return info;};
        NoArvBin* getDir() { return dir;};
};


class ArvoreBinaria
{
    private:
        NoArvBin *raiz; // ponteiro para o n� raiz da �rvore
        void auxImprime(NoArvBin *p);
        bool auxBusca(NoArvBin *p, int val);
        NoArvBin* libera(NoArvBin *p);
    public:
        ArvoreBinaria();
        int getRaiz();
        // cria novo n� como raiz das sub-�rvores �
        //esquerda (sae) e � direita (sad)
        void cria(int val, ArvoreBinaria *sae, ArvoreBinaria *sad);
        bool vazia(); // verifica se a �rvore est� vazia
        bool busca(int val);
        void imprime();
        ~ArvoreBinaria();

};

#endif // ARVOREBIN_H
