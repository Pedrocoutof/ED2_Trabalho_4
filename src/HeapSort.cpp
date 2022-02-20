#include "HeapSort.h"
#include "TiktokReviews.h"
#include "Ordenacao.h"
#include <time.h>

#include <iostream>
using namespace std;

HeapSort:: HeapSort(TiktokReviews *tiktokReviews, int n) {
    movimentacoes = 0;
    comparacoes = 0;
	int i;
	TiktokReviews aux;
    clock_t inicio, fim;


    inicio = clock();
	for (i = (n / 2); i >= 0; i--) {
		peneira(tiktokReviews, i, n - 1);
	}

	for (i = n-1; i >= 1; i--) {
		aux = tiktokReviews[0];
		tiktokReviews[0] = tiktokReviews[i];
		tiktokReviews[i] = aux;
		peneira(tiktokReviews, 0, i-1);
	}
	fim = clock();
	tempoGasto = (double)(inicio - fim) / CLOCKS_PER_SEC;
}

void HeapSort::peneira(TiktokReviews *tiktokReviews, int raiz, int fundo)
{
    int pronto, filhoMax;
	TiktokReviews aux;

	pronto = 0;
	while ((raiz*2 <= fundo) && (!pronto)) {
        comparacoes++;
		if (raiz*2 == fundo) {
			filhoMax = raiz * 2;
		}
		else if (tiktokReviews[raiz * 2].upvotes > tiktokReviews[raiz * 2 + 1].upvotes) {
			filhoMax = raiz * 2;
		}
		else {
			filhoMax = raiz * 2 + 1;
		}

	if (tiktokReviews[raiz].upvotes < tiktokReviews[filhoMax].upvotes) {
        movimentacoes++;
		aux = tiktokReviews[raiz];
		tiktokReviews[raiz] = tiktokReviews[filhoMax];
		tiktokReviews[filhoMax] = aux;
		raiz = filhoMax;
    }
	else {
      pronto = 1;
	}
  }
}
