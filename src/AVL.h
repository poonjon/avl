#ifndef AVL_H
#define AVL_H

#include "Rotations.h"

Node *avlAdd(Node *root, Node *nodeToAdd, int (*compare)(void *, void *));
Node *avlRemove(Node **ptrToRoot, Node *nodeToRemove);
Node *avlRemoveRootNode(Node *root);
Node *avlGetReplacer(Node **ptrToRoot);

#endif // AVL_H
