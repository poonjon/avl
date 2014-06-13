#ifndef Rotations_H
#define Rotations_H

typedef struct Node{
  int balance;
  struct Node *leftChild;
  struct Node *rightChild;
  int data;
}Node;

int getHeight(Node *elem);
Node *rightRotate(Node *elem);
Node *leftRotate(Node *elem);
Node *doubleRightRotate(Node *elem);
Node *doubleLeftRotate(Node *elem);
Node *checkDoubleRightRightExchange(Node *elem);
Node *checkDoubleRightLeftExchange(Node *elem);
Node *checkDoubleLeftLeftExchange(Node *elem);
Node *checkDoubleLeftRightExchange(Node *elem);

#endif // Rotations_H
