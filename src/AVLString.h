#ifndef AVLString_H
#define AVLString_H

#include "AVL.h"
#define avlAddString(root, nodeToAdd) avlAdd((Node *)(root), (Node *)(nodeToAdd), compareString)

typedef struct NodeString NodeString;

struct NodeString{
  int balance;
  Node *leftChild;
  Node *rightChild;
  char *string;
};

int compareString(void *nodeInTree, void *nodeToCompare);

#endif // AVLString_H