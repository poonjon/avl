#include "AVLInt.h"

int compareInt(void *nodeInTree, void *nodeToCompare){
  Node *node1 = (Node *)nodeInTree;
  Node *node2 = (Node *)nodeToCompare;
  if(node1->data < node2->data)
    return -1;
  else if(node1->data > node2->data)
    return 1;
  else if(node1->data == node2->data)  
    printf("nah");
  
}