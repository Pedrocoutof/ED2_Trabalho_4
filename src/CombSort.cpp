#include "CombSort.h"

CombSort::CombSort(TiktokReviews * v, int tam)
{
    comparacoes = 0;
    movimentacoes = 0;
	int i, j, intervalo, trocado = 1;
	TiktokReviews aux;
	intervalo = tam;
	while (intervalo > 1 || trocado == 1)
	{
		intervalo = intervalo * 10 / 13;
        comparacoes++;
		if (intervalo == 9 || intervalo == 10) intervalo = 11;

		comparacoes++;
		if (intervalo < 1) intervalo = 1;

		trocado = 0;
		for (i = 0, j = intervalo; j < tam; i++, j++)
		{
		    comparacoes++;
			if (v[i].upvotes > v[j].upvotes)
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				trocado = 1;
				movimentacoes++;
			}
		}
	}
}
