#include "AVL.h"
#include <stdio.h>
#include "Rotations.h"

Node *avlAdd(Node *root, Node *nodeToAdd){
  Node *temp = root;
  int tempBalance;
  
  if(root == NULL ){  //ROOT NULL
    root = nodeToAdd;
    root->balance = 0;
    return root;
  }
  
  else if(root != NULL){ //ROOT NOT NULL

    if(nodeToAdd->data > root->data){  //LEVEL 2: RIGHT
        
      if(root->rightChild == NULL){
        root->rightChild = avlAdd(root->rightChild, nodeToAdd);
        root->balance++;
      }
      
      else if(root->rightChild != NULL){
        tempBalance = root->rightChild->balance;
        root->rightChild = avlAdd(root->rightChild, nodeToAdd);
        
        if((tempBalance == root->rightChild->balance) || root->rightChild->balance == 0){
        }
        else
          root->balance++;
      }
    }
     
    else if(nodeToAdd->data < root->data){  //LEVEL 2: LEFT
          
      if(root->leftChild == NULL){
        root->leftChild = avlAdd(root->leftChild, nodeToAdd);
        root->balance--;
      }
      
      else if(root->leftChild != NULL){
        tempBalance = root->leftChild->balance;
        root->leftChild = avlAdd(root->leftChild, nodeToAdd);
          
        if((tempBalance == root->leftChild->balance) || root->leftChild->balance == 0){
        }
        else
          root->balance--;
      }

    }

    if(root->balance == 2 && root->rightChild->balance == 1)
      root = leftRotate(root);
    else if(root->balance == 2 && root->rightChild->balance == -1)
      root = doubleLeftRotate(root);
    if(root->balance == -2 && root->rightChild->balance == 1)
      root = rightRotate(root);
    if(root->balance == -2 && root->rightChild->balance == -1)
      root = doubleRightRotate(root);
    return root;
  }  
}
  
Node *avlGetReplacer(Node **ptrToRoot){
  Node *temp = (*ptrToRoot)->rightChild;
  if((*ptrToRoot)->leftChild == NULL && (*ptrToRoot)->rightChild == NULL){
    (*ptrToRoot)->data = 0;
    (*ptrToRoot)->balance = 0;
    (*ptrToRoot)->leftChild = NULL;
    (*ptrToRoot)->rightChild = NULL;
  }  
  
  else if((*ptrToRoot)->leftChild != NULL){
    (*ptrToRoot) = (*ptrToRoot)->leftChild;
  }
   
  if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == 1)
    (*ptrToRoot) = leftRotate((*ptrToRoot));
  else if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == -1)
    (*ptrToRoot) = doubleLeftRotate((*ptrToRoot));
  if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->rightChild->balance == 1)
    (*ptrToRoot) = rightRotate((*ptrToRoot));
  if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->rightChild->balance == -1)
    (*ptrToRoot) = doubleRightRotate((*ptrToRoot));
  
  return (*ptrToRoot);
}