#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
using namespace std;

#include "TiktokReviews.h"

class QuickSort
{
    private:
        void troca(TiktokReviews &a, TiktokReviews &b);
        int movimentacoes = 0;
        int comparacoes = 0;
        double tempoGasto = 0;

    public:
        QuickSort(TiktokReviews *v, int n);
        void quickSortRec(TiktokReviews *v, int ini, int fim);
        TiktokReviews medianaDeTres(TiktokReviews *v, int ini, int fim);
        int particiona(TiktokReviews *v, int ini, int fim);

        int getMovimentacoes(){ return this->movimentacoes; };
        int getComparacoes() { return this->comparacoes; };
        double getTempoGasto() { return this->tempoGasto; };

};

#endif // QUICKSORT_H
