#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct NoArvBinario {
    int data;
    NoArvBinario* left;
    NoArvBinario* right;
};

/* Function to create a new node */

class ArvoreBinaria2{
    public:
        NoArvBinario* CreateNode(int data);
        NoArvBinario* InsertNode(NoArvBinario* root, int data);
        void inorder(NoArvBinario* temp);

};
#endif // ARVOREBINARIA_H
