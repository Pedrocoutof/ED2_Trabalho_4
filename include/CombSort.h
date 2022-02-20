#ifndef COMBSORT_H
#define COMBSORT_H

#include <iostream>
using namespace std;

#include "TiktokReviews.h"


class CombSort
{
    private:
        int movimentacoes = 0;
        int comparacoes = 0;
        double tempoGasto = 0;

    public:
        CombSort(TiktokReviews * v, int tam);

        int getMovimentacoes(){ return this->movimentacoes; };
        int getComparacoes() { return this->comparacoes; };
        double getTempoGasto() { return this->tempoGasto; };

};

#endif // COMBSORT_H
