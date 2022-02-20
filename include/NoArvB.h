#ifndef NOARVB_H
#define NOARVB_H

#include <iostream>
using namespace std;
#include <vector>


class NoArvB {

    // Vector of keys
    vector<int> keys;

    // Minimum degree
    int t;

    // Vector of child pointers
    vector<NoArvB*> C;

    // Is true when node is folha, else false
    bool folha;


public:
    // Constructor
    NoArvB(int t, bool folha);

    // Traversing the node and print its content
    // with tab number of tabs before
    void traverse(int tab);

    // Insert key into given node. If child is split, we
    // have to insert *val entry into keys vector and
    // newEntry pointer into C vector of this node
    void insere(int key, int* val, NoArvB*& novoNo);

    // Split this node and store the new parent value in
    // *val and new node pointer in newEntry
    void cisao(int* val, NoArvB*& novoNo);

    // Returns true if node is full
    bool verificaArvCheia();

    // Makes new root, setting current root as its child
    NoArvB* criaNovaRaiz(int val, NoArvB* novoNo);


    NoArvB * busca(int k);
};


#endif // NOARVB_H
