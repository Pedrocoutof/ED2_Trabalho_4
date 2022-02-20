#include "ArvoreVP.h"
#include "iostream"
#include "cstring" // Para utilizar a funcao 'strcasecmp(str1, str2)'
                   // -1 se str1 for primeiro do que str2 ,
                   // 0 se forem iguais,
                   // 1 se str2 for primeiro do que str1,

#include <time.h>
using namespace std;


ArvoreVP::ArvoreVP(){

    comparacaoInsercao = 0;
    comparacaoBusca = 0;
    sentinela = new NoVP("", -1);
    sentinela->setCor(PRETO);
    raiz = sentinela;
}

ArvoreVP::~ArvoreVP(){
    raiz = libera(raiz);
    int comparacaoBusca = 0;
    int comparacaoInsercao = 0;
    //delete sentinela;
}

NoVP * ArvoreVP::libera(NoVP * p){
    if(p != sentinela){
        p->setEsq( libera(p->getEsq() ));
        p->setDir( libera(p->getDir() ));
        //delete p;
    }
    return sentinela;
}

bool ArvoreVP::busca(char chave[90]){
    return buscaAux(raiz, chave);
}

bool ArvoreVP::buscaAux(NoVP * p, char chave[90]){

    comparacaoBusca++;
    if(p == sentinela){
        return false;
    }

    comparacaoBusca++;
    if(strcasecmp(p->getInfo(), chave) == 0){
        return true;
    }
    //esq
    comparacaoBusca++;
    if(strcasecmp(chave , p->getInfo()) == -1){
        return buscaAux(p->getEsq(), chave);
    }
    //dir
    comparacaoBusca++;
    if(strcasecmp(chave , p->getInfo()) == +1 ){
        return buscaAux(p->getDir(), chave);
    }
}


int ArvoreVP::buscaRetornaPosID(char chave[90]){
    int posID;
    if(buscaRetornaPosIDAux(raiz, chave, &posID) != NULL)
        return posID;

    return -1;
}
bool ArvoreVP::buscaRetornaPosIDAux(NoVP * p, char chave[90], int * posID){

    comparacaoBusca++;
    if(p == sentinela){
        return false;
    }

    comparacaoBusca++;
    if(strcasecmp(p->getInfo(), chave) == 0){
        *posID = p->getPosicaoRegistro();
        return true;
    }
    //esq
    comparacaoBusca++;
    if(strcasecmp(chave , p->getInfo()) == -1){
        return buscaRetornaPosIDAux(p->getEsq(), chave, posID);
    }
    //dir
    comparacaoBusca++;
    if(strcasecmp(chave , p->getInfo()) == +1 ){
        return buscaRetornaPosIDAux(p->getDir(), chave, posID);
    }
}

void ArvoreVP::insere(char chave[90], int pos){
    balanceado = false;
    raiz = insereAux(raiz, chave, pos);
}

NoVP * ArvoreVP::insereAux(NoVP * p, char chave[90], int pos){

    comparacaoInsercao++;
    if(p == sentinela){
        NoVP * novo = new NoVP(chave, pos);
        novo->setEsq(sentinela);
        novo->setDir(sentinela);
        novo->setPai(sentinela);
        return novo;
    }
    else{
        //if(chave < p->getInfo())
        comparacaoInsercao++;
        if(strcasecmp(chave, p->getInfo()) == -1){
            p->setEsq(insereAux(p->getEsq(), chave, pos));
        }
        else{
            p->setDir(insereAux(p->getDir(), chave, pos));
        }
        p = balancear(p);
        return p;
    }
}

void ArvoreVP::imprime(){
    imprimeAux(raiz);
    cout << endl;
}

void ArvoreVP::imprimeAux(NoVP * p){

    if(p != sentinela){
        imprimeAux(p->getEsq());
        p->imprime();
        imprimeAux(p->getDir());
    }
}

void ArvoreVP::imprimePorNivel(){
    imprimePorNivelAux(raiz, 0);
}

void ArvoreVP::imprimePorNivelAux(NoVP * p, int k){
    if(p != sentinela){
        imprimePorNivelAux(p->getDir(), k+1);
        for(int i = 0; i < k; i++){
            cout << "\t";
        }
        p->imprime();
        imprimePorNivelAux(p->getEsq(), k+1);
    }
}

NoVP * ArvoreVP::balancear(NoVP * p){

    if(p->getCor() == VERMELHO){
        NoVP *pai = p->getPai();
        //cout << "Imprime : " << p << ", " << pai << ", " << sentinela << endl;

        if(pai == sentinela){
            p->setCor(PRETO);
        }

        else if(pai->getCor() == VERMELHO){
            NoVP * avo = pai->getPai();
            if(avo == sentinela){
                pai->setCor(PRETO);
            }else{
                NoVP * tio = (avo->getDir() == pai) ? avo->getEsq() : avo->getDir();

                if(tio->getCor() == VERMELHO){
                    pai->setCor(PRETO);
                    tio->setCor(PRETO);
                    avo->setCor(VERMELHO);
                }

                else if(avo->getDir() == pai){
                    if(pai->getEsq() == p){
                        rotSimplesDir(p);
                        p->setCor(PRETO);
                    }
                    else
                        pai->setCor(PRETO);

                    rotSimplesEsq(p);
                    avo->setCor(VERMELHO);
                }

                else{

                    if(pai->getDir() == p){
                        rotSimplesEsq(p);
                        p->setCor(PRETO);
                    }
                    else
                        pai->setCor(PRETO);

                    rotSimplesDir(p);
                    avo->setCor(VERMELHO);

                }

            }
        }
    }
    return p;
}

void ArvoreVP::rotSimplesEsq(NoVP * p){

    NoVP * pai = p->getPai();
    pai->setDir( p->getEsq() );
    p->setEsq(pai);


    NoVP * avo = pai->getPai();

    if(avo != sentinela){
        if(pai == avo->getEsq())
            avo->setEsq(p);

        else
            avo->setDir(p);
    }
    p->setPai(avo);
    pai->setPai(p);
}

void ArvoreVP::rotSimplesDir(NoVP * p){

    NoVP * pai = p->getPai();
    pai->setEsq( p->getDir() );
    p->setDir(pai);


    NoVP * avo = pai->getPai();

    if(avo != sentinela){
        if(pai == avo->getEsq())
            avo->setEsq(p);

        else
            avo->setDir(p);
    }
    p->setPai(avo);
    pai->setPai(p);
}

void ArvoreVP::zeraComparacoes(){
    this->comparacaoBusca = 0;
    this->comparacaoInsercao = 0;
}
