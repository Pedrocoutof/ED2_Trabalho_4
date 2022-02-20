#ifndef BIN_H
#define BIN_H
#endif // BIN_H
#include <iostream>
#include <time.h>

#include "TiktokReviews.h"

using namespace std;

valorAleatorio(int range){
    return rand() % range;
}

void geraArqBinario(char dir_bin[], char dir_csv[])
{

    FILE * arq_bin = fopen(dir_bin, "r");
    FILE * arq_csv = fopen(dir_csv, "r");

    if(!arq_csv)
    {
        cout << "Erro! Arquivo <.csv> nao encontrado no diretorio" << endl;
        exit(404);
    }

    if(!arq_bin)
    {

        arq_bin = fopen(dir_bin, "wb");

        rewind(arq_csv);
        rewind(arq_bin);
        char ch;

        for(ch = fgetc(arq_csv); ch != '\n'; ch = fgetc(arq_csv)) {}   // PULA A PRIMEIRA LINHA DO '.csv' JÁ QUE A PRIMEIRA LINHA TEM INFORMAÇÕES DE COMO O ARQUIVO É SEPARADO //


        while(ch!=EOF)
        {
            TiktokReviews tiktokReviews;
            tiktokReviews.review_text[0] = '\0';
            tiktokReviews.app_version[0] = '\0';


            /// LEITURA REVIEW_ID
            fscanf(arq_csv, "%[^,]", tiktokReviews.review_id);
            ch = fgetc(arq_csv);
            ch = fgetc(arq_csv);

            /// LEITURA REVIEW_TEXT
            if(ch == '"') // VERIFICA SE POSSUI ASPAS
            {
                bool verificaPrimeiroCaractereNumero = true;
                int i = 0;
                ch = fgetc(arq_csv);
                while(!(ch >= 48 && ch <= 57) || verificaPrimeiroCaractereNumero)
                {
                    verificaPrimeiroCaractereNumero = false;
                    while(ch != ',')
                    {
                        while(ch != '"')
                        {
                            tiktokReviews.review_text[i] = ch;
                            i++;
                            ch = fgetc(arq_csv);

                        }
                        ch = fgetc(arq_csv);
                    }
                    ch = fgetc(arq_csv);
                }
                fseek(arq_csv, -1, SEEK_CUR);

                tiktokReviews.review_text[i] = '\0';
            }
            // SE NAO POSSUIR LE ATÉ A VIRGULA
            else
            {
                fseek(arq_csv, -1, SEEK_CUR);
                fscanf(arq_csv, "%[^,]", tiktokReviews.review_text);
                fseek(arq_csv, +1, SEEK_CUR);
            }


            /// LEITURA UPVOTES
            fscanf(arq_csv, "%d[^,]", &tiktokReviews.upvotes);
            ch = fgetc(arq_csv);

            /// LEITURA APP_VERSION
            fscanf(arq_csv, "%[^,]", tiktokReviews.app_version);
            ch = fgetc(arq_csv);

            /// LEITURA POSTED_DATE
            fscanf(arq_csv, "%[^\n]", tiktokReviews.posted_date);
            ch = fgetc(arq_csv);

            tiktokReviews.imprimeConteudoTiktokReviews();
            tiktokReviews.gravaTiktokReviewEmBinario(arq_bin, tiktokReviews);


        }

        fclose(arq_bin);
        fclose(arq_csv);
    }
    else
    {
        cout << "Arquivo < .bin > encontrado" << endl;
    }

}

void acessaRegistro(int i)
{
    FILE * arq_bin = fopen("tiktok_app_reviews.bin", "r+b");

    if(arq_bin == NULL)
    {
        cout << "Erro! Arquivo não encontrado no diretorio : " << arq_bin;
        exit(404);
    }
    rewind(arq_bin);
    TiktokReviews tiktokReviews;

    fseek(arq_bin, i * sizeof(TiktokReviews), SEEK_CUR);

    fread(&tiktokReviews.review_id, sizeof(tiktokReviews.review_id), 1, arq_bin);
    fread(&tiktokReviews.review_text, sizeof(tiktokReviews.review_text), 1, arq_bin);
    fread(&tiktokReviews.upvotes, sizeof(tiktokReviews.upvotes), 1, arq_bin);
    fread(&tiktokReviews.app_version, sizeof(tiktokReviews.app_version), 1, arq_bin);
    fread(&tiktokReviews.posted_date, sizeof(tiktokReviews.posted_date), 1, arq_bin);

    for(int i = 0; i < 14; i ++)
    {
        printf("%c", 461);
    }
    cout << "  ACESSANDO REGISTRO : " << i << "  ";

    for(int i = 0; i < 14; i ++)
    {
        printf("%c", 461);
    }
    cout << endl;
    tiktokReviews.imprimeConteudoTiktokReviews();
    fclose(arq_bin);
}

TiktokReviews retornaRegistro(int i){

    FILE * arq_bin = fopen("tiktok_app_reviews.bin", "rb");

    if(arq_bin == NULL){
        cout << "Erro! Arquivo não encontrado no diretorio : " << arq_bin;
        exit(404);
    }

    TiktokReviews tiktokReviews;

    //cout << endl << "Registro BIN : " << i;

    fseek(arq_bin, i * sizeof(TiktokReviews), 1);

    fread(&tiktokReviews.review_id, sizeof(tiktokReviews.review_id), 1, arq_bin);
    fread(&tiktokReviews.review_text, sizeof(tiktokReviews.review_text), 1, arq_bin);
    fread(&tiktokReviews.upvotes,  sizeof(tiktokReviews.upvotes), 1, arq_bin);
    fread(&tiktokReviews.app_version, sizeof(tiktokReviews.app_version), 1, arq_bin);
    fread(&tiktokReviews.posted_date, sizeof(tiktokReviews.posted_date), 1, arq_bin);


    fclose(arq_bin);

    return tiktokReviews;
}

TiktokReviews retornaRegistroAleatorio(int range){

    FILE * arq_bin = fopen("tiktok_app_reviews.bin", "r+b");

    if(arq_bin == NULL)
    {
        cout << "Erro! Arquivo não encontrado no diretorio : " << arq_bin;
        exit(404);
    }
    rewind(arq_bin);
    TiktokReviews tiktokReviews;

    int valorAleatorio = rand() % range;

    fseek(arq_bin, valorAleatorio * sizeof(TiktokReviews), SEEK_CUR);

    fread(&tiktokReviews.review_id, sizeof(tiktokReviews.review_id), 1, arq_bin);
    fread(&tiktokReviews.review_text, sizeof(tiktokReviews.review_text), 1, arq_bin);
    fread(&tiktokReviews.upvotes, sizeof(tiktokReviews.upvotes), 1, arq_bin);
    fread(&tiktokReviews.app_version, sizeof(tiktokReviews.app_version), 1, arq_bin);
    fread(&tiktokReviews.posted_date, sizeof(tiktokReviews.posted_date), 1, arq_bin);

    fclose(arq_bin);
    return tiktokReviews;
}

