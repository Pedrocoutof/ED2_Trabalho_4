#ifndef HASH_H
#define HASH_H
#define TAM_TABELA_HASH 150 // TAMANHO DA TABELA HASH
#include <iostream>
using namespace std;

#include "TiktokReviews.h"


// -- Estrutura usada para armazenar os Nós -- //
typedef struct no {
    TiktokReviews tiktokReviews;
    struct no *proximo;
} No;


// -- Estrutura usada para armazenar Lista -- //
typedef struct {
    No *inicio;
    int tam;
} Lista;

class Hash
{
    public:
        Lista * tabelaHash[TAM_TABELA_HASH];
        Hash();
        virtual ~Hash();
        Lista * criarLista();
        void inserirInicio(TiktokReviews p, Lista *lista);
        No* buscarNo(char chave[20], No *inicio);
        void imprimirLista(No *inicio);
        void inicializar();
        int funcaoHashString(char str[]);
        int funcaoHashInt(int chave);
        void insereTabela(TiktokReviews tiktokReviews);
        TiktokReviews * buscarAppVersionTabela(char chave [20]);
        void hashLista();

    private:
};

#endif // HASH_H
