#include "rotations.h"
#include <stdio.h>

Node *leftRotate(Node *elem){
  Node *root;
  
  root = elem;
  root = elem->rightChild;
  root->leftChild = elem; //left = node1
  root->rightChild = (elem->rightChild)->rightChild; // right = node3
  
  root->rightChild->rank = 0;
  root->leftChild->rank = 0;
  root->rank = 0;
  return root;
}

Node *rightRotate(Node *elem){
  Node *root;
  
  root = elem;
  root = elem->leftChild;
  root->rightChild = elem; //left = node1
  root->leftChild = (elem->leftChild)->leftChild; // right = node3
  
  root->rightChild->rank = 0;
  root->leftChild->rank = 0;
  root->rank = 0;
  return root;
}
