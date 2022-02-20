#include "ArvoreBin.h"
#include "iostream"

using namespace std;

ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}

int ArvoreBinaria::getRaiz()
{
if(raiz != NULL) //ou if(!vazia())
return raiz->getInfo();
else
{
cout << "Árvora vazia!" << endl;
exit(1);
}
}
bool ArvoreBinaria::vazia()
{
return raiz == NULL;
}

void ArvoreBinaria::cria(int val, ArvoreBinaria *sae, ArvoreBinaria *sad)
{
NoArvBin *p = new NoArvBin();
p->setInfo(val);
p->setEsq(sae->raiz);
p->setDir(sad->raiz);
raiz = p;
}

void ArvoreBinaria::imprime()
{
auxImprime(raiz);
}

void ArvoreBinaria:: auxImprime(NoArvBin *p)
{
if(p != NULL)
{
cout << p->getInfo() << endl; // PRE ORDEM
auxImprime(p->getEsq());
auxImprime(p->getDir());
}
}

bool ArvoreBinaria::busca(int val)
{
return auxBusca(raiz, val);
}

bool ArvoreBinaria::auxBusca(NoArvBin *p, int ch)
{
if (p == NULL)
return false;
else if (p->getInfo() == ch)
return true;
else if (auxBusca(p->getEsq(), ch))
return true;
else

return auxBusca(p->getDir(), ch);

}

ArvoreBinaria::~ArvoreBinaria(){

raiz = libera(raiz);
}

NoArvBin* ArvoreBinaria::libera(NoArvBin *p)
{
if (p != NULL)
{
p->setEsq( libera(p->getEsq()));
p->setDir( libera(p->getDir()));
delete p;
p = NULL;
}
return NULL;
}
