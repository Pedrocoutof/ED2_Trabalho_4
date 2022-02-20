#ifndef HUFFMAN_H
#define HUFFMAN_H
#define MAX_TREE_HT 256

using namespace std;

// Mapeamento de um char para string com a sequencia de bits
map<char, string> codigoHuffman;

// "Liga" um char com um valor inteiro que referente a sua frequencia
map<char, int> freq;

int comparacoesCodificacao = 0;

// Nó da arvore de Huffman
struct NoMinHeap
{
    char info;             // Caracter do no
    int freq;             // Numero de frequencia do Caracter
    NoMinHeap *esq, *dir;
    NoMinHeap(char info, int freq)
    {
        esq = dir = nullptr;
        this->info = info;
        this->freq = freq;
    }
};

// funcao utilizada para organizar lista de prioridade
struct compare
{
    bool operator()(NoMinHeap* l, NoMinHeap* r)
    {
        return (l->freq > r->freq);
    }
};

void printcodigoHuffman(struct NoMinHeap* raiz, string str)
{
    if (!raiz)
        return;
    if (raiz->info != '$')
        cout << raiz->info << ": " << str << "\n";
    printcodigoHuffman(raiz->esq, str + "0");
    printcodigoHuffman(raiz->dir, str + "1");
}

// Funcao que salva os caracteres em map
void salvaCodigoHuffmanMap(struct NoMinHeap* raiz, string str)
{
    comparacoesCodificacao++;
    if (raiz==nullptr)
        return;

    comparacoesCodificacao++;
    if (raiz->info != '$')
        codigoHuffman[raiz->info]=str;

    salvaCodigoHuffmanMap(raiz->esq, str + "0");
    salvaCodigoHuffmanMap(raiz->dir, str + "1");
}

// Declaramos um fila de prioridade do tipo NoMinHeap, colocamos o container com os nos, e utilizamos a funcao para comparar e
// gerar a fila de prioridade minHeap.
priority_queue<NoMinHeap*, vector<NoMinHeap*>, compare> minHeap;

// Funcao que gera a arvore de huffman
void geraCodigoHuffman(int size)
{
    struct NoMinHeap *esq, *dir, *topo;
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++){
        minHeap.push(new NoMinHeap(v->first, v->second));
        comparacoesCodificacao++;
    }

    comparacoesCodificacao++;
    while (minHeap.size() != 1)
    {
        esq = minHeap.top();
        minHeap.pop();
        dir = minHeap.top();
        minHeap.pop();
        topo = new NoMinHeap('$', esq->freq + dir->freq);
        topo->esq = esq;
        topo->dir = dir;
        minHeap.push(topo);
        comparacoesCodificacao++;
    }
    salvaCodigoHuffmanMap(minHeap.top(), "");
}

// Funcao usada para guardar cada iteração no map
void calculaFrequencia(string str, int n)
{
    comparacoesCodificacao++;
    for (int unsigned i = 0; i < str.size(); i++){
        freq[str[i]]++;
        comparacoesCodificacao++;
    }
}

string decodificaString(struct NoMinHeap* raiz, string str)
{
    string resp = "";
    struct NoMinHeap* p = raiz;
    for (int unsigned i=0; i<str.size(); i++)
    {
        if (str[i] == '0')
            p = p->esq;
        else
            p = p->dir;

        if (p->esq == nullptr and p->dir == nullptr)
        {
            resp += p->info;
            p = raiz;
        }
    }
    return resp+'\0';
}

void imprimeFreqDeCadaCaracter(){
    cout << endl << "Caracter\t| Repeticoes\t| Codigo" << endl;
    auto c = codigoHuffman.begin();
    for(auto f = freq.begin(); f!=freq.end() && c!=codigoHuffman.end(); f++){

        cout << f->first <<"\t\t  " << f->second <<"\t\t  " << c->second << endl;
        c++;
    }

}

void imprimeCodeDeCadaCaracter(){
    for (auto v=codigoHuffman.begin(); v!=codigoHuffman.end(); v++)
        cout << v->first <<' ' << v->second <<' ' << endl;
}

double calculaTaxaDeCompressao(string str_entrada, string str_saida){

    double numeroBytesSaida = str_saida.length() / 8;
    //cout << endl << "str_entrada: " << str_entrada.length() << "B";
    //cout << endl << "str_saida: " << str_saida.length() / 8 << "B" << endl;
    //cout << endl << "((" << str_entrada.length() << " - " << numeroBytesSaida << "" << "/ " << str_entrada.length() << ")"<< endl;
    return ((str_entrada.length() - numeroBytesSaida)/str_entrada.length());

}

// Funcao usada para zerar todas variaveis em cada execucao
void reiniciaHuffman(){
    codigoHuffman.clear();
    freq.clear();
    minHeap = priority_queue<NoMinHeap*, vector<NoMinHeap*>, compare>();
    comparacoesCodificacao = 0;
}

#endif // HUFFMAN_H
