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
    else if(root->balance == -2 && root->rightChild->balance == 1)
      root = rightRotate(root);
    else if(root->balance == -2 && root->rightChild->balance == -1)
      root = doubleRightRotate(root);
    return root;
  }  
}
  
Node *avlGetReplacer(Node **ptrToRoot){
  Node *replace, *temp;
  
  if((*ptrToRoot)->rightChild == NULL){
    replace = (*ptrToRoot);
    (*ptrToRoot) = (*ptrToRoot)->leftChild;  
    return replace;
  }
  
  else{
    
    replace = avlGetReplacer(&(*ptrToRoot)->rightChild);
    
    if((*ptrToRoot)->rightChild == NULL)
      (*ptrToRoot)->balance--;
    else if((*ptrToRoot)->rightChild->balance == 0)
      (*ptrToRoot)->balance--;
    
    if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == 1)
      (*ptrToRoot) = leftRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == -1)
      (*ptrToRoot) = doubleLeftRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == 0)
      (*ptrToRoot) = leftRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == 0)
      (*ptrToRoot) = rightRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == -1)
      (*ptrToRoot) = rightRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == 1)
      (*ptrToRoot) = doubleRightRotate((*ptrToRoot));
  }
  
  return replace;
}