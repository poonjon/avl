#ifndef rotations_H
#define rotations_H

typedef struct Node{
  int rank;
  struct Node *leftChild;
  struct Node *rightChild;
  int data;
}Node;

int getHeight(Node *elem);
Node *rightRotate(Node *elem);
Node *leftRotate(Node *elem);
Node *doubleRightRotate(Node *elem);
Node *doubleLeftRotate(Node *elem);

#endif // rotations_H
