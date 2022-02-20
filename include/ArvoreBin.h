#ifndef ARVOREBIN_H
#define ARVOREBIN_H

class NoArvBin
{
    private:
        NoArvBin *esq; // ponteiro para o filho à esquerda
        int info; // informação do nó (int)
        NoArvBin *dir; // ponteiro para o filho à direita
    public:
        NoArvBin() {}; //construtor e destrutor
        ~NoArvBin() {};
        void setEsq(NoArvBin *p) { esq = p;}; //operações setter
        void setInfo(int val) { info = val;};
        void setDir(NoArvBin *p) { dir = p;};
        NoArvBin* getEsq() { return esq;}; //operações getter
        int getInfo() { return info;};
        NoArvBin* getDir() { return dir;};
};


class ArvoreBinaria
{
    private:
        NoArvBin *raiz; // ponteiro para o nó raiz da árvore
        void auxImprime(NoArvBin *p);
        bool auxBusca(NoArvBin *p, int val);
        NoArvBin* libera(NoArvBin *p);
    public:
        ArvoreBinaria();
        int getRaiz();
        // cria novo nó como raiz das sub-árvores à
        //esquerda (sae) e à direita (sad)
        void cria(int val, ArvoreBinaria *sae, ArvoreBinaria *sad);
        bool vazia(); // verifica se a árvore está vazia
        bool busca(int val);
        void imprime();
        ~ArvoreBinaria();

};

#endif // ARVOREBIN_H
