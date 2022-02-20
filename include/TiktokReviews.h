#ifndef TIKTOKREVIEWS_H
#define TIKTOKREVIEWS_H
#include "iostream"

class TiktokReviews
{
    public:
        char review_id [90];        //  string identificadora �nica
        char review_text[1502];     //  o review postado pelo usu�rio
        char app_version[20];       //  string indicando a vers�o do aplicativo a que o review se refere
        char posted_date[20];       //  data e hora de postagem
        int  upvotes;               //  n�mero de votos favor�veis ao review

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
