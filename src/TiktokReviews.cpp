#include "TiktokReviews.h"
#include "iostream"

using namespace std;

TiktokReviews::TiktokReviews()
{
        char review_id [90] = "";        //  string identificadora única
        char review_text[1502] = "";     //  o review postado pelo usuário
        char app_version[20] = "";       //  string indicando a versão do aplicativo a que o review se refere
        char posted_date[20] = "";       //  data e hora de postagem
        int  upvotes = 0;                //  número de votos favoráveis ao review
}

TiktokReviews::~TiktokReviews()
{

}

void TiktokReviews::imprimeConteudoTiktokReviews(){

    cout << endl <<     "Review ID : "       <<      review_id      << endl;
    cout <<             "Review Text : "     <<      review_text    << endl;
    cout <<             "Up Votes : "        <<      upvotes        << endl;
    cout <<             "App Version : "     <<      app_version    << endl;
    cout <<             "Posted Date : "     <<      posted_date    << endl << endl;

}

void TiktokReviews :: gravaTiktokReviewEmBinario(FILE * arq_bin, TiktokReviews tiktokReviews){

    if(!fwrite(tiktokReviews.review_id,   sizeof(tiktokReviews.review_id),   1, arq_bin)){
        exit(10);
    };
    if(!fwrite(tiktokReviews.review_text, sizeof(tiktokReviews.review_text), 1, arq_bin)){
        exit(10);
    };
    if(!fwrite(&tiktokReviews.upvotes,    sizeof(tiktokReviews.upvotes),     1, arq_bin)){
        exit(10);
    };
    if(!fwrite(tiktokReviews.app_version, sizeof(tiktokReviews.app_version), 1, arq_bin)){
        exit(10);
    };
    if(!fwrite(tiktokReviews.posted_date, sizeof(tiktokReviews.posted_date), 1, arq_bin)){
        exit(10);
    };
}

void TiktokReviews:: gravaTiktokReviewEmTxt(FILE * arq_txt){
            fprintf(arq_txt, "%s", review_id);
            imprimeConteudoTiktokReviews();
            fprintf(arq_txt, "%c", 44);
            fprintf(arq_txt, "%s", review_text);
            fprintf(arq_txt, "%c", 44);
            fprintf(arq_txt, "%d", upvotes);
            fprintf(arq_txt, "%c", 44);
            fprintf(arq_txt, "%s", app_version);
            fprintf(arq_txt, "%c", 44);
            fprintf(arq_txt, "%s", posted_date);
            fprintf(arq_txt, "%c", '\n');
}

//TiktokReviews::

