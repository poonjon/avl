#ifndef AVLInt_H
#define AVLInt_H

#include "AVL.h"
#define avlAddInt(root, nodeToAdd) avlAdd((Node *)(root), (Node *)(nodeToAdd), compareInt)
#define avlRemoveInt(root, nodeToAdd) avlRemove((Node **)(root), (Node *)(nodeToRemove), compareInt)

typedef struct NodeInt NodeInt;

struct NodeInt{
  int balance;
  NodeInt *leftChild;
  NodeInt *rightChild;
  int data;
};

int compareInt(void *nodeInTree, void *nodeToCompare);
#endif // AVLInt_H
