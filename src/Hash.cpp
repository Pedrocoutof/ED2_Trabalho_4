#include "Hash.h"
#define TAM_TABELA_HASH 150 // TAMANHO DA TABELA HASH
#include <string.h>
#include "TiktokReviews.h"
#include <time.h>

//#include "BIN.h"

#include <iostream>
using namespace std;

Hash::Hash(){

    int i;
    for(i = 0; i < TAM_TABELA_HASH; i++)
        tabelaHash[i] = criarLista();

}

Hash::~Hash(){}

TiktokReviews retornaRegistroHash(int i){

    FILE * arq_bin = fopen("tiktok_app_reviews.bin", "rb");

    if(arq_bin == NULL){
        cout << "Erro! Arquivo não encontrado no diretorio : " << arq_bin;
        exit(404);
    }

    TiktokReviews tiktokReviews;

    fseek(arq_bin, i * sizeof(TiktokReviews), 1);

    fread(&tiktokReviews.review_id, sizeof(tiktokReviews.review_id), 1, arq_bin);
    fread(&tiktokReviews.review_text, sizeof(tiktokReviews.review_text), 1, arq_bin);
    fread(&tiktokReviews.upvotes,  sizeof(tiktokReviews.upvotes), 1, arq_bin);
    fread(&tiktokReviews.app_version, sizeof(tiktokReviews.app_version), 1, arq_bin);
    fread(&tiktokReviews.posted_date, sizeof(tiktokReviews.posted_date), 1, arq_bin);


    fclose(arq_bin);

    return tiktokReviews;
}


void Hash:: insereTabela(TiktokReviews tiktokReviews){
    int indice = funcaoHashString(tiktokReviews.app_version);
    inserirInicio(tiktokReviews, tabelaHash[indice]);
}


int Hash:: funcaoHashInt(int chave){
    return chave % TAM_TABELA_HASH;
}


int Hash:: funcaoHashString(char str[]){
    int i, tamS = strlen(str);
    unsigned int hash = 0;

    for(i = 0; i < tamS; i++)
        hash += str[i] * (i + 1); // somatório do código ASCII vezes a posição
    return hash % TAM_TABELA_HASH;
}

void Hash::inicializar(){
    int i;
    for(i = 0; i < TAM_TABELA_HASH; i++)
        tabelaHash[i] = criarLista();
}

void Hash::imprimirLista(No *inicio) {
    while(inicio != NULL) {
        inicio->tiktokReviews.imprimeConteudoTiktokReviews();
        inicio = inicio->proximo;
    }
}

No* Hash::buscarNo(char chave[20], No *inicio) {

    while(inicio != NULL) {
        if(inicio->tiktokReviews.app_version == chave)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL;
}

void Hash:: inserirInicio(TiktokReviews p, Lista *lista) {
    No *no = (No *) malloc(sizeof(No));
    no->tiktokReviews = p;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}
Lista * Hash:: criarLista() {

    Lista *l = (Lista *) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

TiktokReviews * Hash::buscarAppVersionTabela(char chave [20]){
    int indice = funcaoHashString(chave);
    No *no = buscarNo(chave, tabelaHash[indice]->inicio);
    if(no)
        return &no->tiktokReviews;
    else
        return NULL;
}

void Hash:: hashLista(){
    TiktokReviews vetor[80];

    for(int i = 0; i < 80; i++)
        vetor[i] = retornaRegistroHash(rand() % 1000);

    inicializar();

    for(int i = 0; i < 80; i++){
        cout << "============= " << i << " =============" << endl;
        vetor[i].imprimeConteudoTiktokReviews();
        insereTabela(vetor[i]);
    }

    cout << endl << endl << "Conteudo Tabela Hash" << endl;

    printf("\n---------------------TABELA-------------------------\n");
    for(int i = 0; i < TAM_TABELA_HASH; i++){
        printf("%d Lista tamanho: %d\n", i, tabelaHash[i]->tam);
        imprimirLista(tabelaHash[i]->inicio);
    }
    printf("---------------------FIM TABELA-----------------------\n");


    cout << "Digite qual versao deseja pesquisar na tabela: ";
    char respString[20];
    cin >> respString;

    imprimirLista(tabelaHash[funcaoHashString(respString)]->inicio);
}

