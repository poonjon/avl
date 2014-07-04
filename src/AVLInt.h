#ifndef AVLInt_H
#define AVLInt_H

#include "AVL.h"
#define avlAddInt(root, nodeToAdd) avlAdd(root, nodeToAdd, compareInt)
int compareInt(void *nodeInTree, void *nodeToCompare);
#endif // AVLInt_H
