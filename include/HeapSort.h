#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "TiktokReviews.h"

#include <iostream>
using namespace std;



class HeapSort
{
    private:
        int movimentacoes = 0;
        int comparacoes = 0;
        double tempoGasto = 0;

    public:
        HeapSort(TiktokReviews *tiktokReviews, int n);
        void peneira(TiktokReviews *tiktokReviews, int raiz, int fundo);

        int getMovimentacoes(){ return this->movimentacoes; };
        int getComparacoes() { return this->comparacoes; };
        double getTempoGasto() { return this->tempoGasto; };
};

#endif // HEAPSORT_H
