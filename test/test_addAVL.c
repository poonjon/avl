#include "addAVL.h"
#include "unity.h"


void setUp(void){}
void tearDown(void){}

void test_addavl_node1_should_pass(){
  Node Node1 = {.data = 1, .balance = 2, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &Node1);
  
  TEST_ASSERT_EQUAL(0, root->balance);
}

void test_addavl_node2_50_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &Node1);
  
  avlAdd(root, &Node2);
  
  TEST_ASSERT_EQUAL(1, root->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
  TEST_ASSERT_EQUAL(50, root->rightChild->data);
}

void xtest_addavl_node3_100_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &Node1);
  
  avlAdd(root, &Node2);
  avlAdd(root, &Node3);
  
  TEST_ASSERT_EQUAL(2, root->balance);
  TEST_ASSERT_EQUAL(1, root->rightChild->balance);
  // TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  // TEST_ASSERT_EQUAL(100, root->rightChild->data);
  // TEST_ASSERT_EQUAL(1, root->leftChild->data);
  // TEST_ASSERT_EQUAL(50, root->data);
  
}
