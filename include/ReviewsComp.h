#ifndef REVIEWSCOMP_H
#define REVIEWSCOMP_H

#endif // REVIEWSCOMP_H

#include "iostream"
using namespace std;


FILE * arqCompBin(char dir_compBin[])
{
     return FILE * arq_compBin = fopen("compBin.txt", "a");

};

FILE * arqReviewsOrig(char dir_reviewsOrig[])
{
     return FILE * reviewsOrig = fopen("reviewsOrig.txt", "a");
};

void adicionaStringCompBin(string chave){

    FILE * compBin = fopen("compBin.txt", "a+b");
    fprintf(compBin, "%s", chave);

}

void adicionaStringReviewsOrig(string chave){

    FILE * reviewsOrig = fopen("reviewsOrig.txt", "a");
    fprintf(reviewsOrig, "%s", chave);

}
