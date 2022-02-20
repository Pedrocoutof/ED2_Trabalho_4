#include "QuickSort.h"
#include <iostream>
using namespace std;

#include "TiktokReviews.h"

QuickSort::QuickSort(TiktokReviews *v, int n)
{
    movimentacoes = 0;
    comparacoes = 0;
    quickSortRec(v, 0, n-1);
}

void QuickSort::quickSortRec(TiktokReviews *v, int ini, int fim)
{
    if(ini < fim)
    {
        int p = particiona(v, ini, fim);
        quickSortRec(v, ini, p-1);
        quickSortRec(v, p+1, fim);
        return;
    }
}

int QuickSort::particiona(TiktokReviews *v, int ini, int fim)
{
    TiktokReviews pivo = medianaDeTres(v, ini, fim);

    int i = ini, j = fim-1;
    while(true)
    {

        comparacoes++;
        while(i < fim && v[i].upvotes < pivo.upvotes)
            i++;

        comparacoes++;
        while(j >= ini && v[j].upvotes > pivo.upvotes)
            j--;
        comparacoes++;
        if(i < j)
        {
        movimentacoes++;
            troca(v[i], v[j]);
            i++;
            j--;
        }
        else
            break;
    }
    movimentacoes++;
    troca(v[i], v[fim]);
    return i;
}

TiktokReviews QuickSort::medianaDeTres(TiktokReviews *v, int ini, int fim)
{
    int meio = (ini+fim)/2;

    comparacoes++;
    if(v[ini].upvotes > v[fim].upvotes){
        movimentacoes++;
        troca(v[ini], v[fim]);
    }

    comparacoes++;
    if(v[meio].upvotes > v[fim].upvotes){
        movimentacoes++;
        troca(v[meio], v[fim]);
    }


    comparacoes++;
    if(v[ini].upvotes > v[meio].upvotes){
        movimentacoes++;
        troca(v[ini], v[meio]);
    }

    movimentacoes++;
    troca(v[meio], v[fim]);
    return v[fim];
}

void QuickSort::troca(TiktokReviews &a, TiktokReviews &b)
{
    TiktokReviews aux = a;
    a = b;
    b = aux;
}
