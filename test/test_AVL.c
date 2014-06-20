#include "AVL.h"
#include "unity.h"
#include "Rotations.h"

void setUp(void){}
void tearDown(void){}

/**
*     1
*/
void test_addavl_node1_should_pass(){
  Node Node1 = {.data = 1, .balance = 2, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &Node1);
  
  TEST_ASSERT_EQUAL(0, root->balance);
}

/**
*     1
*      \
*       50
*/
void test_addavl_node2_50_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node2);
  
  TEST_ASSERT_EQUAL(1, root->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
  TEST_ASSERT_EQUAL(50, root->rightChild->data);
}

/**
*     1                   50
*      \                 /  \
*       50       =>     1    100
*         \
*          100
*
*/
void test_addavl_node3_100_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node2);
  root = avlAdd(root, &Node3);
  
  TEST_ASSERT_EQUAL(100, root->rightChild->data);
  TEST_ASSERT_EQUAL(1, root->leftChild->data);
  TEST_ASSERT_EQUAL(50, root->data);
  TEST_ASSERT_EQUAL(0, root->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  
}

/**
*       50     
*      /  \    
*     1    100        
*          /               
*        75               
*/
void test_addavl_node4_75_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  Node *temp = root;
  
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node2);
  root = avlAdd(root, &Node3);
  root = avlAdd(root, &Node4);
  temp = root->rightChild;
  
  TEST_ASSERT_EQUAL(50, root->data);
  TEST_ASSERT_EQUAL(1, root->leftChild->data);
  TEST_ASSERT_EQUAL(100, root->rightChild->data);  
  TEST_ASSERT_EQUAL(75, temp->leftChild->data);
  
  TEST_ASSERT_EQUAL(-1, root->rightChild->balance);
  TEST_ASSERT_EQUAL(1, root->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  TEST_ASSERT_EQUAL(0, temp->leftChild->balance);   
}

/**
*       50     
*      /  \    
*     1    100        
*          /  \             
*        75    150           
*/
void test_addavl_node4_150_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  Node *temp = root;
  
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node2);
  root = avlAdd(root, &Node3);
  root = avlAdd(root, &Node4);
  root = avlAdd(root, &Node5);
  temp = root->rightChild;
  
  TEST_ASSERT_EQUAL(50, root->data);
  TEST_ASSERT_EQUAL(1, root->leftChild->data);
  TEST_ASSERT_EQUAL(100, root->rightChild->data);  
  TEST_ASSERT_EQUAL(75, temp->leftChild->data);
  TEST_ASSERT_EQUAL(150, temp->rightChild->data);
  
  TEST_ASSERT_EQUAL(1, root->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  TEST_ASSERT_EQUAL(0, temp->leftChild->balance);   
  TEST_ASSERT_EQUAL(0, temp->rightChild->balance);   
}

/**
*       50                         100               
*      /  \                       /    \           
*     1    100                  50      150                        
*          /  \           =>   /  \       \    
*        75    150            1    75      200        
*                 \
*                 200                             
*/
void test_addavl_node4_200_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  Node *tempLeft = root;
  Node *tempRight = root;
  
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node2);
  root = avlAdd(root, &Node3);
  root = avlAdd(root, &Node4);
  root = avlAdd(root, &Node5);
  root = avlAdd(root, &Node6);
  tempRight = root->rightChild;
  tempLeft = root->leftChild;
 
   TEST_ASSERT_EQUAL(150, root->rightChild->data);  
   TEST_ASSERT_EQUAL(50, root->leftChild->data);
   TEST_ASSERT_EQUAL(100, root->data);
   TEST_ASSERT_EQUAL(200, tempRight->rightChild->data);
   TEST_ASSERT_EQUAL(75, tempLeft->rightChild->data);
   TEST_ASSERT_EQUAL(1, tempLeft->leftChild->data);
  
   TEST_ASSERT_EQUAL(0, root->balance);
   TEST_ASSERT_EQUAL(0, root->leftChild->balance);
   TEST_ASSERT_EQUAL(1, root->rightChild->balance);  
   TEST_ASSERT_EQUAL(0, tempRight->rightChild->balance);
   TEST_ASSERT_EQUAL(0, tempLeft->rightChild->balance);
   TEST_ASSERT_EQUAL(0, tempLeft->leftChild->balance);
  
}

/**
*         100                      100
*        /    \                   /    \  
*      50     150       =>      50    150               
*     /  \       \            /   \   /   \
*    1    75      200        1    75 120  200                                     
*/
void test_addavl_node4_120_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  Node *tempLeft = root;
  Node *tempRight = root;
  
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node2);
  root = avlAdd(root, &Node3);
  root = avlAdd(root, &Node4);
  root = avlAdd(root, &Node5);
  root = avlAdd(root, &Node6);
  root = avlAdd(root, &Node7);
  tempRight = root->rightChild;
  tempLeft = root->leftChild;
 
   TEST_ASSERT_EQUAL(150, root->rightChild->data);  
   TEST_ASSERT_EQUAL(50, root->leftChild->data);
   TEST_ASSERT_EQUAL(100, root->data);
   TEST_ASSERT_EQUAL(200, tempRight->rightChild->data);
   TEST_ASSERT_EQUAL(75, tempLeft->rightChild->data);
   TEST_ASSERT_EQUAL(120, tempRight->leftChild->data);
   TEST_ASSERT_EQUAL(1, tempLeft->leftChild->data);
  
   TEST_ASSERT_EQUAL(0, root->balance);
   TEST_ASSERT_EQUAL(0, root->leftChild->balance);
   TEST_ASSERT_EQUAL(0, root->rightChild->balance);  
   TEST_ASSERT_EQUAL(0, tempRight->rightChild->balance);
   TEST_ASSERT_EQUAL(0, tempRight->leftChild->balance);
   TEST_ASSERT_EQUAL(0, tempLeft->rightChild->balance);
   TEST_ASSERT_EQUAL(0, tempLeft->leftChild->balance);
  
}

/**
*     (1)
*/
void test_getReplacer_node1_should_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlGetReplacer(&root);
  
  TEST_ASSERT_NULL(result->leftChild);  
  TEST_ASSERT_NULL(result->rightChild);  
  TEST_ASSERT_EQUAL(0, result->data);  
  TEST_ASSERT_EQUAL(0, result->balance);  

}

/**
*     (50)
*    / 
*   20
*
*/
void test_getReplacer_node2_should_pass(){
  Node Node2 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = NULL};
  
  Node *root = &Node1;
  Node *result;

  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node2, result);  
  TEST_ASSERT_NULL(result->rightChild);  
  TEST_ASSERT_NULL(result->leftChild);  
  TEST_ASSERT_EQUAL(20, result->data);  
  TEST_ASSERT_EQUAL(0, result->balance);  

}

/**
*     50
*       \ 
*       (80)
*
*/
void test_getReplacer_node3_should_pass(){
  Node Node2 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = NULL, .rightChild = &Node2};
  
  Node *root = &Node2;
  Node *result;

  result = avlGetReplacer(&root);
  
  TEST_ASSERT_NULL(result->rightChild);  

}

/**
*     50
*    /   \ 
*   20    (80)
*
*/
void test_getReplacer_node4_should_pass(){
  Node Node3 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 0, .leftChild = &Node2, .rightChild = &Node3};
  
  Node *root = &Node3;
  Node *result;

  result = avlGetReplacer(&root);
  
  TEST_ASSERT_NULL(result->rightChild);  

}

/**
*     50
*    /   \ 
*   20    (80)
*         /
*       70
*
*/
void test_getReplacer_node5_should_pass(){
  Node Node4 = {.data = 70, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 80, .balance = 0, .leftChild = &Node4, .rightChild = NULL};
  Node Node2 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 0, .leftChild = &Node2, .rightChild = &Node3};
  
  Node *root = &Node3;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node4, result);  

}

/**
*     50
*    /   \ 
*   20    80
*        /   \
*       70   (90)
*            /           
*          85
*/
void test_getReplacer_node6_should_pass(){
  Node Node6 = {.data = 85, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 90, .balance = -1, .leftChild = &Node6, .rightChild = NULL};
  Node Node4 = {.data = 70, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 80, .balance = 1, .leftChild = &Node4, .rightChild = &Node5};
  Node Node2 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 2, .leftChild = &Node2, .rightChild = &Node3};
  
  Node *root = &Node5;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node6, result);  

}

/**   
*         50                   50            30
*        /   \                 / \          /  \
*       20    80             30  80        20   50
*      /   \    \      =>   / \       =>  /    /  \
*    15    30   (90)      20   40        15   40   80
*         /   \           /                 
*        25    40       15              
*/    
void test_getReplacer_node7_should_pass(){
  Node Node8 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node7 = {.data = 80, .balance = 1, .leftChild = NULL, .rightChild = &Node8};
  Node Node6 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 30, .balance = 0, .leftChild = &Node5, .rightChild = &Node6};
  Node Node3 = {.data = 15, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 20, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  Node Node1 = {.data = 50, .balance = -1, .leftChild = &Node2, .rightChild = &Node3};
  
  Node *root = &Node8;
  Node *result;
  
  result = avlGetReplacer(&root);
  root = &Node1;
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node4, result);  
  TEST_ASSERT_EQUAL_PTR(&Node2, result->leftChild);  
  TEST_ASSERT_EQUAL_PTR(&Node1, result->rightChild);  
  TEST_ASSERT_EQUAL_PTR(&Node3, result->leftChild->leftChild);  
  TEST_ASSERT_EQUAL_PTR(&Node6, result->rightChild->leftChild);  
  TEST_ASSERT_EQUAL_PTR(&Node7, result->rightChild->rightChild);  

}

