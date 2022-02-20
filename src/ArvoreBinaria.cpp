#include "ArvoreBinaria.h"

NoArvBinario* ArvoreBinaria2::CreateNode(int data)
{
    NoArvBinario* newNode = new NoArvBinario();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Function to insert element in binary tree */

NoArvBinario* ArvoreBinaria2::InsertNode(NoArvBinario* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<NoArvBinario*> q;
    q.push(root);

    while (!q.empty()) {
        NoArvBinario* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */

void ArvoreBinaria2::inorder(NoArvBinario* temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
