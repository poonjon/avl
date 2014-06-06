#include "rotations.h"
#include <stdio.h>

int leftHeight = 0, rightHeight = 0;

Node *leftRotate(Node *elem){
  Node *root, *temp;
  
  root = elem;
  temp = elem->rightChild->leftChild;
  root = elem->rightChild;
  root->leftChild = elem;
  (root->leftChild)->rightChild = temp; 

  return root;
}

Node *rightRotate(Node *elem){
  Node *root, *temp;
  
  root = elem;
  temp = elem->leftChild->rightChild;
  root = elem->leftChild;
  root->rightChild = elem;
  (root->rightChild)->leftChild = temp; 
  

  return root;
}

Node *doubleRightRotate(Node *elem){
  Node *pivot, *temp, *temp2;
  
  
  temp = elem->leftChild->rightChild;
  temp2 = temp->rightChild;
  
  pivot = elem->leftChild->rightChild;
  pivot->leftChild = elem->leftChild;
  pivot->rightChild = elem;
  pivot->rightChild->leftChild = temp2;
  
  return pivot;
}

Node *doubleLeftRotate(Node *elem){
  Node *pivot, *temp, *temp2;
  
  temp = elem->leftChild->rightChild;
  temp2 = temp->leftChild;
  
  pivot = elem->leftChild->rightChild;
  pivot->leftChild = elem->leftChild;
  pivot->rightChild = elem;
  pivot->leftChild->rightChild = temp2;
 
  return pivot;
}




