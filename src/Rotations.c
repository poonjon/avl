#include "Rotations.h"
#include <stdio.h>

Node *leftRotate(Node *elem){
  Node *root, *temp;
  
  if((elem->balance == 2) && ((elem->rightChild)->balance == 1)){
    elem->balance = 0;
    elem->rightChild->balance = 0;
  }
  
  else if(elem->balance == 1 && elem->rightChild->balance == 1){
    elem->rightChild->balance = -1;
    elem->balance = -1;
  }
  
  else if(elem->balance == 2 && elem->rightChild->balance == 0){
    elem->rightChild->balance = -1;
    elem->balance = 1;
  }
  
  else if(elem->balance == 1 && elem->rightChild->balance == -1){
    elem->rightChild->balance = -2;
    elem->balance = 0;
  }
  
  else if(elem->balance == 2 && elem->rightChild->balance == 2){
    elem->balance = -1;
    elem->rightChild->balance = 0;
  }
  
  else if(elem->balance == 1 && elem->rightChild->balance == 0){
    elem->balance = 0;
    elem->rightChild->balance = -1;
  }
  
  root = elem;
  temp = elem->rightChild->leftChild;
  root = elem->rightChild;
  root->leftChild = elem;
  root->leftChild->rightChild = temp; 
  
  return root;
}

Node *rightRotate(Node *elem){
  Node *root, *temp;
  
  if(elem->balance == -2 && elem->leftChild->balance == -1){
    elem->balance = 0;
    elem->leftChild->balance = 0;
  }
  
  else if(elem->balance == -2 && elem->leftChild->balance == -2){
    elem->balance = 1;
    elem->leftChild->balance = 0;
  }
  
  else if(elem->balance == -2 && elem->leftChild->balance == 0){
    elem->balance = -1;
    elem->leftChild->balance = 1;
  }
  
  else if(elem->balance == -1 && elem->leftChild->balance == -1){
    elem->balance = 1;
    elem->leftChild->balance = 1;
  }
   
  else if(elem->balance == -1 && elem->leftChild->balance == 1){
    elem->balance = 0;
    elem->leftChild->balance = 2;
  
  }
  
  else if(elem->balance == -1 && elem->leftChild->balance == 0){
    elem->balance = 0;
    elem->leftChild->balance = 1;
  }
  
  root = elem;
  temp = elem->leftChild->rightChild;
  root = elem->leftChild;
  root->rightChild = elem;
  root->rightChild->leftChild = temp; 
  

  return root;
}

Node *doubleRightRotate(Node *elem){
  Node *pivot, *temp, *temp2;
  
  temp = checkDoubleRightRightExchange(elem);
  temp2 = checkDoubleRightLeftExchange(elem);
  
  pivot = leftRotate(elem->leftChild);
  elem->leftChild = pivot;
  pivot = rightRotate(elem);

  if(temp != NULL)
    pivot->rightChild->leftChild = temp;
  
  if(temp2 != NULL)
    pivot->leftChild->rightChild = temp2;

  return pivot;
}

Node *checkDoubleRightRightExchange(Node *elem){
  Node *temp, *temp2;
  
  temp = (elem->leftChild)->rightChild;
  temp2 = temp->rightChild;
  
  if(temp2 != NULL)
    return temp2;

}

Node *checkDoubleRightLeftExchange(Node *elem){
  Node *temp, *temp2;
  
  temp = (elem->leftChild)->rightChild;
  temp2 = temp->leftChild;
  
  if(temp2 != NULL)
    return temp2;
}

Node *doubleLeftRotate(Node *elem){
  Node *pivot, *temp, *temp2;
  
  temp = checkDoubleLeftRightExchange(elem);
  temp2 = checkDoubleLeftLeftExchange(elem);
  
  pivot = rightRotate(elem->rightChild);
  elem->rightChild = pivot;
  pivot = leftRotate(elem);
  
  if(temp != NULL){
    pivot->rightChild->leftChild = temp;
  }
  
  if(temp2 != NULL){
    pivot->leftChild->rightChild = temp2;
  }
 
  return pivot;
}

Node *checkDoubleLeftRightExchange(Node *elem){
  Node *temp, *temp2;
  
  temp = (elem->rightChild)->leftChild;
  temp2 = temp->rightChild;
  
  if(temp2 != NULL)
    return temp2;

}

Node *checkDoubleLeftLeftExchange(Node *elem){
  Node *temp, *temp2;
  
  temp = (elem->rightChild)->leftChild;
  temp2 = temp->leftChild;
  
  if(temp2 != NULL)
    return temp2;
}

int getHeight(Node *elem){
  int left = 0, right = 0;
  
  if(elem->leftChild != NULL){
    left = getHeight(elem->leftChild);
  }
    left++;
  
  if(elem->rightChild != NULL){
    right = getHeight(elem->rightChild);
  }
    right++;
  
  if(left >= right)
    return left;
   
  else if(right >= left)
    return right;
}
