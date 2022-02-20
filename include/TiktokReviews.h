#ifndef TIKTOKREVIEWS_H
#define TIKTOKREVIEWS_H
#include "iostream"

class TiktokReviews
{
    public:
        char review_id [90];        //  string identificadora única
        char review_text[1502];     //  o review postado pelo usuário
        char app_version[20];       //  string indicando a versão do aplicativo a que o review se refere
        char posted_date[20];       //  data e hora de postagem
        int  upvotes;               //  número de votos favoráveis ao review

        TiktokReviews();
        ~TiktokReviews();

        void imprimeConteudoTiktokReviews();
        //void imprimeConteudoTiktokReviews(TiktokReviews tiktokReviews);

        //void gravaTiktokReviewEmTxt(FILE * arq_txt, TiktokReviews tiktokReviews);
        void gravaTiktokReviewEmTxt(FILE * arq_txt);

        void gravaTiktokReviewEmBinario(FILE * arq_bin, TiktokReviews tiktokReviews);


    private:

};

#endif // TIKTOKREVIEWS_H
