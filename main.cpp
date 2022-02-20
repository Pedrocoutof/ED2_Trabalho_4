/// CONSTANTES
#define TAM_VINTE 20
#define TAM_CINQUENTA 50
#define TAM_CEM 100
#define TAM_QUINHENTOS 500
#define TAM_MIL 1000
#define TAM_CINCO_MIL 5000
#define TAM_DEZ_MIL 10000
#define TAM_QUINHENTOS_MIL 500000
#define RANGE 1000000
#define M 3

/// INCLUDES EXTRAS
#include <iostream>
using namespace std;
#include "Cronometro.h"

/// TRABALHO 1
#include "BIN.h"
#include "TiktokReviews.h"

/// TRABALHO 2
#include "HeapSort.h"
#include "QuickSort.h"
#include "CombSort.h"
#include "Hash.h"

/// TRABALHO 3
#include "ArvoreVP.h"
#include "ArvoreB.h"

/// TRABALHO 4
#include "Huffman.h"

void comprimirConjunto(){
    FILE * arq_compBin = fopen("reviewsComp.bin", "w+b");

    if(arq_compBin == nullptr){
        cout << endl << "Erro ao criar arquivo <reviewsComp.bin>" << endl;
        exit(1);
    }

    reiniciaHuffman();

    cout << endl << " -- Digite um valor N de reviews_texts: ";
    int n;
    cin >> n;

    string str_texts;

    for(int i = 0; i < n; i++){
        str_texts += retornaRegistroAleatorio(RANGE).review_text;
        str_texts += "\n";
    }

    // cout << str_texts;

    calculaFrequencia(str_texts, str_texts.length());
    geraCodigoHuffman(str_texts.length());

    string str_codificada;
    for (auto i: str_texts)
        str_codificada+=codigoHuffman[i];

    // cout << str_codificada;

    for(int unsigned i = 0; i < str_codificada.length(); i++){
        fwrite(&str_codificada[i], sizeof(char), 1, arq_compBin);
    }

    /// INICIO - TAXA DE COMPRESSAO

    cout << " -- Taxa de compressao: " << calculaTaxaDeCompressao(str_texts, str_codificada) * 100 << "%";
    cout << endl << " -- Numero de comparacoes na codificacao: " << comparacoesCodificacao;
    cout << endl << " -- Arquivo codificado <reviewsComp.bin> gerado com sucesso!" << endl;

    /// FIM - TAXA DE COMPRESSAO

    fclose(arq_compBin);
}

void descomprimirArquivo(){
    FILE * arq_txt = fopen("reviewsOrig.txt", "w");
    FILE * arq_bin = fopen("reviewsComp.bin", "rb");

    if(arq_txt == nullptr){
        cout << endl << "Erro ao criar arquivo <reviewsOrig.txt>" << endl;
        exit(1);
    }

    if(arq_bin == nullptr){
        cout << endl << "Erro ao abrir arquivo <reviewsComp.bin> para realizar a descompactacao" << endl;
        return;
    }

    if(minHeap.empty()){
        cout << endl << "Erro: Arvore vazia - Tente comprimir um conjunto antes de descoprimir" << endl;
        return;
    }

    string str_codificada;
    char aux;

    while(!feof(arq_bin)){
        fread(&aux, sizeof(char), 1, arq_bin);
        str_codificada += aux;
    }

    //cout << str_codificada;

    string str_decodificada = decodificaString(minHeap.top(), str_codificada);

    for(int unsigned i = 0; i < str_decodificada.length(); i++){
        aux = str_decodificada[i];
        fprintf(arq_txt, "%c", aux);
    }

    cout << endl << " -- Arquivo decodificado <reviewsOrig.txt> gerado com sucesso!" << endl;

    fclose(arq_bin);
    fclose(arq_txt);
}

void geraArqFrequencia(){

    FILE *  arq_freq = fopen("frequencia.txt", "a");

    fprintf(arq_freq, "\n------------------------------------------");
    fprintf(arq_freq, "\n| Caracter\t| Repeticoes\t| Codigo |\n");
    fprintf(arq_freq, "------------------------------------------\n");
    auto c = codigoHuffman.begin();
    for(auto f = freq.begin(); f!=freq.end() && c!=codigoHuffman.end(); f++){
        fprintf(arq_freq, "%c\t\t| %d\t\t|", f->first, f->second);
        for(int unsigned index = 0; index < c->second.length(); index++){
            fprintf(arq_freq, "%c", c->second[index]);
        }
        fprintf(arq_freq, "\n");
        c++;
    }
    fprintf(arq_freq, "\n------------------------------------------\n");

    fclose(arq_freq);
}

void executaSequenciaAux_2(int n, double * somaTaxaDeCompressao){

    FILE * arq_saida = fopen("saida.txt", "a");

    if(arq_saida == nullptr){
        cout << endl << "Erro! Nao foi possivel abrir o arquivo <saida.txt> para executar a sequencia aux" << endl;
        return;
    }

    reiniciaHuffman();
    string str_texts, str_codificada;

        for(int i = 0; i < n; i++){
            str_texts += retornaRegistroAleatorio(RANGE).review_text;
            str_texts += "\n";
        }

    calculaFrequencia(str_texts, str_texts.length());
    geraCodigoHuffman(str_texts.length());

    for (auto i: str_texts)
        str_codificada+=codigoHuffman[i];

    double taxaDeCompressao = calculaTaxaDeCompressao(str_texts, str_codificada) * 100;

    fprintf(arq_saida, " --- Calculo realizado com N = %d ---", n);
    fprintf(arq_saida, "\n - Numero de comparacoes na codificacao: %d", comparacoesCodificacao);
    fprintf(arq_saida, "\n - Taxa de compressao: %lf%%", taxaDeCompressao);
    fprintf(arq_saida, "\n-----------------------------------------\n\n");

    *somaTaxaDeCompressao += taxaDeCompressao;

    fclose(arq_saida);
}

void executaSequenciaAux_1(int n, bool geraArqFreq){
    FILE * arq_saida = fopen("saida.txt", "a");

    if(arq_saida == nullptr){
        cout << endl << "Erro! Nao foi possivel abrir o arquivo <saida.txt> para executar a sequencia" << endl;
        return;
    }

    string str_codificada, str_decodificada, str_texts;

    double somaComparacoesCodificacao = 0;
    double somaTaxaDeCompressao = 0;

    cout << endl << "Calculando com N = " << n;
    for(int contador = 0; contador < M; contador++){
        executaSequenciaAux_2(n, &somaTaxaDeCompressao);
        somaComparacoesCodificacao += comparacoesCodificacao;
        cout << ".";
    }


    fprintf(arq_saida, "\n\t\t ------------------------------------------------------------------------------");
    fprintf(arq_saida, "\n\t\t --------- Media da compressao com N = %d e M = %d", n, M);
    fprintf(arq_saida, "\n\t\t --------- Media das comparacoes: %.2lf", somaComparacoesCodificacao/M);
    fprintf(arq_saida, "\n\t\t --------- Media da Taxa de compressao: %lf%%", somaTaxaDeCompressao/M);
    fprintf(arq_saida, "\n\t\t ------------------------------------------------------------------------------\n\n");

    cout << endl << "Calculo com "<< n << " realizado." << endl;

    if(geraArqFreq){
        geraArqFrequencia();
    }


    fclose(arq_saida);
}

void executaSequencia(){
    FILE * arq_saida = fopen("saida.txt", "w"); // zera arquivo de saida

    if(arq_saida == nullptr){
        cout << endl << "Erro! Nao foi possivel criar o arquivo <saida.txt> para executar a sequencia" << endl;
        return;
    }

    bool geraArqFreq = false;

    cout << endl << "Voce deseja que seja montado uma tabela com a frequencia e o codigo de cada caracter em um arquivo <frequencia.txt>?";
    cout << endl << " 0 - Nao  |  1 - Sim" << endl;
    cin >> geraArqFreq;

    /// CALCULA COM 1K
    Cronometro cro;
    cro.IniciaCronometro();
    executaSequenciaAux_1(1000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s"  << endl;

    /// CALCULA COM 5K
    cro.IniciaCronometro();
    executaSequenciaAux_1(5000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s"  << endl;

    /// CALCULA COM 10K
    cro.IniciaCronometro();
    executaSequenciaAux_1(10000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s"  << endl;

    /// CALCULA COM 50K
    cro.IniciaCronometro();
    executaSequenciaAux_1(50000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s"  << endl;

    /// CALCULA COM 100K
    cro.IniciaCronometro();
    executaSequenciaAux_1(100000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s"  << endl;

    /// CALCULA COM 250K
    cro.IniciaCronometro();
    executaSequenciaAux_1(250000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s"  << endl;

    ///CALCULA COM 500K
    cro.IniciaCronometro();
    executaSequenciaAux_1(500000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s"  << endl;

    /// CALCULA COM 1M
    cro.IniciaCronometro();
    executaSequenciaAux_1(1000000, geraArqFreq);
    cro.FinalizaCronometro();
    cout << "Tempo gasto: " << cro.getTempoGasto() << "s" << endl;

}

int main(int argc, char * argv[])
{
    //geraArqBinario("tiktok_app_reviews.bin", "H:\\UFJF\\2021.3\\ED2\\Trabalhos\\ArquivosCSV\\tiktok_app_reviews_reduzido_milhao.csv");
    geraArqBinario("tiktok_app_reviews.bin", argv[1]);
    srand(time(nullptr));

    int opcao;

    do{
        cout << endl <<"==== MENU PRINCIPAL ====" << endl;
        cout << " 1 - Comprimir conjunto N" << endl;
        cout << " 2 - Descomprimir arquivo e salvar texto resultante" << endl;
        cout << " 3 - Executar sequencia de compressoes de N" << endl;
        cout << " 4 - Sair" << endl;
        cout << "   > ";
        cin >> opcao;

        if(opcao == 1){
            comprimirConjunto();
        }
        else if(opcao == 2){
            descomprimirArquivo();
        }
        else if(opcao == 3){
            executaSequencia();
        }


    }while(opcao != 4);

    return 0;
}
