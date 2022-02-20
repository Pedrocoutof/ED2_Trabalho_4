#ifndef BTREENODE_H
#define BTREENODE_H

#include <iostream>

using namespace std;

#include <vector>

struct infoNo{
    int key;
    int posID;

    int getKey(){return key;};
    void setKey(int k){key = k;};

    int getPosID(){return posID;};
    void setPosID(int pos){posID = pos;};
};

class BTreeNode {

    // Vector of keys
    vector<int> keys;

    // Minimum degree
    int t;

    // Vector of child pointers
    vector<BTreeNode*> C;

    // Is true when node is leaf, else false
    bool leaf;


public:
    // Constructor
    BTreeNode(int t, bool leaf);

    // Traversing the node and print its content
    // with tab number of tabs before
    void traverse(int tab);

    // Insert key into given node. If child is split, we
    // have to insert *val entry into keys vector and
    // newEntry pointer into C vector of this node
    void insert(int key, int* val, BTreeNode*& newEntry);

    // Split this node and store the new parent value in
    // *val and new node pointer in newEntry
    void split(int* val, BTreeNode*& newEntry);

    // Returns true if node is full
    bool isFull();

    // Makes new root, setting current root as its child
    BTreeNode* makeNewRoot(int val, BTreeNode* newEntry);


    BTreeNode * search(int k);
};

#endif // BTREENODE_H
