#include "NoArvB.h"

bool NoArvB::verificaArvCheia()
{
    // returns true if node is full
    return (this->keys.size() == 2 * t - 1);
}

NoArvB::NoArvB(int t, bool folha)
{
    // Constructor to set value of t and folha
    this->t = t;
    this->folha = folha;
}

// Function to print the nodes of B-Tree
void NoArvB::traverse(int tab)
{
    int i;
    string s;

    // Print 'tab' number of tabs
    for (int j = 0; j < tab; j++) {
        s += '\t';
    }
    for (i = 0; i < keys.size(); i++) {

        // If this is not folha, then before printing key[i]
        // traverse the subtree rooted with child C[i]
        if (folha == false)
            C[i]->traverse(tab + 1);
        cout << s << keys[i] << endl;
    }

    // Print the subtree rooted with last child
    if (folha == false) {
        C[i]->traverse(tab + 1);
    }
}

// Function to split the current node and store the new
// parent value is *val and new child pointer in &newEntry
// called only for splitting non-folha node
void NoArvB::cisao(int* val, NoArvB*& novoNo)
{

    // Create new non folha node
    novoNo = new NoArvB(t, false);

    //(t+1)th becomes parent
    *val = this->keys[t];

    // Last (t-1) entries will go to new node
    for (int i = t + 1; i < 2 * t; i++) {
        novoNo->keys.push_back(this->keys[i]);
    }

    // This node stores first t entries
    this->keys.resize(t);

    // Last t entries will go to new node
    for (int i = t + 1; i <= 2 * t; i++) {
        novoNo->C.push_back(this->C[i]);
    }

    // This node stores first (t+1) entries
    this->C.resize(t + 1);
}

// Function to insere a new key in given node.
// If child of this node is split, we have to insere *val
// into keys vector and newEntry pointer into C vector
void NoArvB::insere(int chaveNova, int* val, NoArvB*& novoNo)
{

    // Non folha node
    if (folha == false) {
        int i = 0;

        // Find first key greater than new_key
        while (i < keys.size() && chaveNova > keys[i])
            i++;

        // We have to insere new_key into left child of
        // Node with index i
        C[i]->insere(chaveNova, val, novoNo);

        // No split was done
        if (novoNo == NULL)
            return;
        if (keys.size() < 2 * t - 1) {

            // This node can accommodate a new key
            // and child pointer entry
            // Insert *val into key vector
            keys.insert(keys.begin() + i, *val);

            // Insert newEntry into C vector
            C.insert(C.begin() + i + 1, novoNo);

            // As this node was not split, set newEntry
            // to NULL
            novoNo = NULL;
        }
        else {

            // Insert *val and newEntry
            keys.insert(keys.begin() + i, *val);
            C.insert(C.begin() + i + 1, novoNo);

            // Current node has 2*t keys, so split it
            cisao(val, novoNo);
        }
    }
    else {

        // Insert new_key in this node
        vector<int>::iterator it;

        // Find correct position
        it = lower_bound(keys.begin(), keys.end(), chaveNova);

        // Insert in correct position
        keys.insert(it, chaveNova);

        // If node is full
        if (keys.size() == 2 * t) {

            // Create new node
            novoNo = new NoArvB(t, true);

            // Set (t+1)th key as parent
            *val = this->keys[t];

            // Insert last (t-1) keys into new node
            for (int i = t + 1; i < 2 * t; i++) {
                novoNo->keys.push_back(this->keys[i]);
            }

            // This node stores first t keys
            this->keys.resize(t);
        }
    }
}

// Function to create a new root
// setting current node as its child
NoArvB* NoArvB::criaNovaRaiz(int val, NoArvB* novoNo)
{
    // Create new root
    NoArvB* root = new NoArvB(t, false);

    // Stores keys value
    root->keys.push_back(val);

    // Push child pointers
    root->C.push_back(this);
    root->C.push_back(novoNo);
    return root;
}

NoArvB *NoArvB::busca(int k)
{
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < t && k > keys[i])
        i++;

    // If the found key is equal to k, return this node
    if (keys[i] == k)
        return this;

    // If the key is not found here and this is a folha node
    if (folha == true)
        return NULL;

    // Go to the appropriate child
    return C[i]->busca(k);
}
