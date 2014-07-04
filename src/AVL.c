#include "AVL.h"
#include <stdio.h>
#include "Rotations.h"

Node *avlAdd(Node *root, Node *nodeToAdd, int(*compare)(void *, void *)){
  Node *temp = root;
  int tempBalance;
  int compareResult;
  
  if(root == NULL ){  //ROOT NULL
    root = nodeToAdd;
    root->balance = 0;
    return root;
  }
  
  compareResult = compare(root, nodeToAdd);
  
  if(root != NULL){ //ROOT NOT NULL
    
    //if(root->data = nodeToAdd->data){
    if(compareResult == 0){
      printf("nah");
    }
    
    //else if(root->data < nodeToAdd->data){  //LEVEL 2: RIGHT
    else if(compareResult == -1){
      if(root->rightChild == NULL){ //if right child is null, +1 balance
        root->rightChild = avlAdd(root->rightChild, nodeToAdd, compare);
        root->balance++;
      }
      
      else if(root->rightChild != NULL){ //if right child is not null, +1 balance if right child is not 0 and previous balance is not equal to current balance
        tempBalance = root->rightChild->balance;
        root->rightChild = avlAdd(root->rightChild, nodeToAdd, compare);
        
        if((tempBalance != root->rightChild->balance) && root->rightChild->balance != 0)
          root->balance++;


      }
    }
    
    //else if(root->data > nodeToAdd->data){  //LEVEL 2: LEFT
    else if(compareResult == 1){
      if(root->leftChild == NULL){ //if left child is null, -1 balance
        root->leftChild = avlAdd(root->leftChild, nodeToAdd, compare);
        root->balance--;
      }
      
      else if(root->leftChild != NULL){ //if right child is not null, -1 balance if left child is not 0 and previous balance is not equal to current balance
        tempBalance = root->leftChild->balance;
        root->leftChild = avlAdd(root->leftChild, nodeToAdd, compare);
          
        if((tempBalance != root->leftChild->balance) && root->leftChild->balance != 0)
          root->balance--;
      }
    }

    /**
    * to check rotation 
    * if balance root = 2 right = 1, left rotate
    * if balance root = 2 right = -1, double left rotate
    * if balance root = -2 right = 1, right rotate
    * if balance root = -2 right = -1, double right rotate 
    */
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
  Node *replace;
  
  if((*ptrToRoot)->rightChild == NULL){ //if root right child is null, replace root with left child
    replace = (*ptrToRoot);
    (*ptrToRoot) = (*ptrToRoot)->leftChild;  
    return replace;
  }
  
  else{
    
    //recourse down the right side of the tree
    replace = avlGetReplacer(&(*ptrToRoot)->rightChild); 
    
    if((*ptrToRoot)->rightChild == NULL)
      (*ptrToRoot)->balance--;
    else if((*ptrToRoot)->rightChild->balance == 0)
      (*ptrToRoot)->balance--;
    
    /**
    * to check rotation 
    * if balance root = 2 right = 1, left rotate
    * if balance root = 2 right = 0, left rotate
    * if balance root = 2 right = -1, double left rotate
    * if balance root = -2 right = 1, right rotate
    * if balance root = -2 right = 0, right rotate
    * if balance root = -2 right = -1, double right rotate 
    */
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

Node *avlRemove(Node **ptrToRoot, Node *nodeToRemove){
  Node *remove;
  Node *tempLeft, *tempRight;
    
    if((*ptrToRoot) == NULL){
      remove = NULL;
      return remove;
    
    }
    
    else if(nodeToRemove->data == (*ptrToRoot)->data){
    
      if(nodeToRemove->leftChild != NULL){
      
        tempLeft = (*ptrToRoot)->leftChild;
        tempRight = (*ptrToRoot)->rightChild;
        (*ptrToRoot) = avlGetReplacer(&nodeToRemove->leftChild);
        
        
        (*ptrToRoot)->leftChild = tempLeft;
        
        
        // if((*ptrToRoot)->data == (*ptrToRoot)->leftChild->data)
          // (*ptrToRoot)->leftChild = NULL;
          
        remove = nodeToRemove;
        nodeToRemove = NULL;
        
        if((*ptrToRoot)->leftChild->balance == 1)
          (*ptrToRoot)->balance--;
        
        return remove;
      }     
      
      else if(nodeToRemove->rightChild != NULL){

        (*ptrToRoot) = avlGetReplacer(&nodeToRemove->rightChild);          
        remove = nodeToRemove;
        nodeToRemove = NULL;
        
        return remove;
      }
      
      remove = (*ptrToRoot);
      nodeToRemove = NULL;
      (*ptrToRoot) = nodeToRemove;
      
      return remove;
    } 
    
    else if(nodeToRemove->data < (*ptrToRoot)->data){
      
      remove = avlRemove(&(*ptrToRoot)->leftChild, nodeToRemove);
      
      if((*ptrToRoot)->leftChild == NULL)
        (*ptrToRoot)->balance++;
        
      else if((*ptrToRoot)->leftChild->balance == 0){
        
        if((*ptrToRoot)->leftChild->balance == 0 && (*ptrToRoot)->leftChild->rightChild != NULL){}
        
        else if((*ptrToRoot)->leftChild->rightChild == NULL && (*ptrToRoot)->leftChild->balance ==0)
          (*ptrToRoot)->balance++;
        
        else if((*ptrToRoot)->leftChild->rightChild != NULL)
          (*ptrToRoot)->balance++;
       
      }
      
      
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
      return remove;
    }
    
    else if(nodeToRemove->data > (*ptrToRoot)->data){
           
      remove = avlRemove(&(*ptrToRoot)->rightChild, nodeToRemove);
      
      if((*ptrToRoot)->rightChild == NULL)
        (*ptrToRoot)->balance--;
      
      else if((*ptrToRoot)->rightChild->balance == 0){
        
        if((*ptrToRoot)->rightChild->balance == 0 && (*ptrToRoot)->rightChild->leftChild != NULL){        }
        
        else if((*ptrToRoot)->rightChild->leftChild == NULL && (*ptrToRoot)->rightChild->balance ==0)
          (*ptrToRoot)->balance--;
        
        else if((*ptrToRoot)->rightChild->leftChild != NULL)
          (*ptrToRoot)->balance--;
         
        else if((*ptrToRoot)->rightChild->balance == 0)
          (*ptrToRoot)->balance--;
          
      } 
    
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
      return remove;
    }
    
    else{
      remove = NULL;
      return remove;
    }
}


