#include "NoArvoreB.h"


// Construtor da Classe BTreeNode
NoArvoreB::NoArvoreB(int t, bool folha)
{
    this->m = t * 2;

    this->t = t;
    this->folha = folha;
    this->n = 0;

    this->chaves = new InfoNo[m - 1];     // Número máximo possível de chaves em um nó
    this->no = new NoArvoreB *[m]; // Tamanho do ponteiro de filhos
}

/**
 * Busca a chave k recursivamente
*/
NoArvoreB *NoArvoreB::busca(string k, int * comparacaoBusca)
{
    int index = 0;

    /* Encontra qual o possível indice igual a k */
    while (k > chaves[index].review_id && index < n)
    {
        *comparacaoBusca = *comparacaoBusca + 1;
        index++;
    }

    if (chaves[index].review_id == k){
        //cout << "Chave encontrada !" << endl;
        //cout << "Posicao do ID : " << chaves[index].posID << " : " << chaves[index].review_id;
        return this;
    }

    else if (folha)
        return NULL;

    else
        return no[index]->busca(k, comparacaoBusca);
}


NoArvoreB *NoArvoreB::buscaRetornaID(string k, int * comparacaoBusca, int * posID)
{
    int index = 0;

    /* Encontra qual o possível indice igual a k */
    while (k > chaves[index].review_id && index < n)
    {
        *comparacaoBusca = *comparacaoBusca + 1;
        index++;
    }

    if (chaves[index].review_id == k){
        cout << endl << endl << "Chave encontrada !" << endl;
        cout << "Posicao do ID : " << chaves[index].posID << " : " << chaves[index].review_id << endl;
        *posID = chaves[index].posID;
        return this;
    }

    else if (folha){
            *posID = -1;
            return NULL;
        }

    else{

        *posID = -1;
        return no[index]->buscaRetornaID(k, comparacaoBusca, posID);
    }
}


/**
 * @param k, chave a ser inserida
 * Inserção quando o nó tem espaço
 * Se o nó for folha, então coloca as chaves uma posição a frente
 * Caso contrario procura a posição de inserção podendo chamar a inserção com divisão
 * ou a recursão normal
*/
void NoArvoreB::insertEmpty(InfoNo k, int * comparacaoInsercao)
{
    int index = n - 1;

    /* verifica se o nó é folha */
    *comparacaoInsercao++;
    if (folha)
    {
        for (int j = n - 1; j >= 0; j--, *comparacaoInsercao++)
        {
            *comparacaoInsercao++;
            if (chaves[j].review_id < k.review_id)
                break;

            chaves[j + 1] = chaves[j];
            index = j - 1;
        }

        chaves[index + 1].review_id = k.review_id;
        chaves[index + 1].posID = k.posID;
        n++;
    }
    else
    {
        for (int i = n - 1; i >= 0; i--, *comparacaoInsercao++)
        {
            *comparacaoInsercao++;
            if (chaves[i].review_id < k.review_id)
            {
                break;
            }
            index = i - 1;
        }

        if (no[index + 1]->n == m - 1)
        {
            insertSplitChild(index + 1, no[index + 1], comparacaoInsercao++);

            if (chaves[index + 1].review_id < k.review_id)
                index++;
        }
        no[index + 1]->insertEmpty(k, comparacaoInsercao);
    }
}


void NoArvoreB::insertSplitChild(int index, NoArvoreB *overflow, int *comparacaoInsercao)
{
    NoArvoreB *child = new NoArvoreB(overflow->t, overflow->folha);
    child->n = t - 1;

    *comparacaoInsercao++;
    if (!overflow->folha)
    {
        /* copia os filhos */
        for (int i = 0; i < t; i++, *comparacaoInsercao++)
        {
            child->no[i] = overflow->no[i + t];
        }
    }

    /* copia as chaves */
    for (int i = 0; i < t - 1; i++, *comparacaoInsercao++)
    {
        child->chaves[i] = overflow->chaves[i + t];
    }

    /* reduz número de chaves do nó em overflow */
    overflow->n = t - 1;

    /* inicializa os novos filhos */
    for (int i = n; i >= index + 1; i--, *comparacaoInsercao++)
    {
        no[i + 1] = no[i];
    }

    /*  recebe novo filho */
    no[index + 1] = child;

    /* move as chaves um espaço à frente */
    for (int j = n - 1; j >= index; j--, *comparacaoInsercao++)
    {
        chaves[j + 1] = chaves[j];
    }

    /* seta a chave do meio */
    chaves[index] = overflow->chaves[t - 1];

    /* incrementa número de chaves do novo nó */
    n += 1;
}

/**
 * Percorre o nó imprimindo seus filhos
*/
void NoArvoreB::imprimeNo()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!folha)
        {
            no[i]->imprimeNo();
        }
        cout << "Posicao ID : " << chaves[i].posID << " : " << chaves[i].review_id << endl;
    }

    if (!folha)
    {
        no[i]->imprimeNo();
    }
}


/**
 * gets e sets para os valores privates
*/
InfoNo NoArvoreB::getChaves(int n)
{
    return chaves[n];
}

void NoArvoreB::setChaves(InfoNo k)
{
    chaves[0].review_id = k.review_id;
}

int NoArvoreB::getN()
{
    return n;
}

void NoArvoreB::setN(int n)
{
    this->n = n;
}

NoArvoreB *NoArvoreB::getNo(int i)
{
    return no[i];
}

void NoArvoreB::setNo(int n, NoArvoreB *root)
{
    no[n] = root;
}
