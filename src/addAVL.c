#include "addAVL.h"
#include <stdio.h>

Node *avlAdd(Node *root, Node *nodeToAdd){
  Node *temp = root;
  if(root == NULL ){
    root = nodeToAdd;
    root->balance = 0;
    return root;
  }
  
  else if(root != NULL){
   
   if(root->leftChild == NULL && root->rightChild == NULL && ((nodeToAdd->data) > (root->data))){
      root->balance = +1;
      root->rightChild = nodeToAdd;
      return root;
    }
    
    else if((nodeToAdd->data) > (root->data)){
      temp = root->rightChild;
      
      if(temp->rightChild == NULL){
        temp->rightChild = nodeToAdd;
        temp->balance = 1;
        root = temp;
        root->balance = 2;
        
        return root;
      }
    }  
  }  
}
  
