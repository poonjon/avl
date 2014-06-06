#include "unity.h"
#include "Rotations.h"

void setUp(void){}
void tearDown(void){}

/**
*  (1)           (2)
*    \          /   \ 
*    (2)  ->  (1)   (3)
*      \
*      (3)
*/
void test_leftRotate_should_rotate_to_balance_tree(){
  Node Node3 = {.data = 3, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 2, .rank = 1, .leftChild = NULL, .rightChild = &Node3};
  Node Node1 = {.data = 1, .rank = 2, .leftChild = NULL, .rightChild = &Node2};
  Node *root;

  root = leftRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  // TEST_ASSERT_EQUAL(0, Node2.rank);
  // TEST_ASSERT_EQUAL(0, Node1.rank);
  // TEST_ASSERT_EQUAL(0, Node3.rank);
}

/**
*   (50)                    (100)
*   /  \                    /   \ 
*(10)  (100)       =>    (50)   (150)
*      /   \            /    \       \ 
*  (20)    (150)     (10)     (20)    (200)
*              \
*              (200)
*/
void test_leftRotate_6_elem_should_rotate_to_balance_tree(){
  Node Node6 = {.data = 200, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .rank = 1, .leftChild = NULL, .rightChild = &Node6};
  Node Node4 = {.data = 20, .rank = 0, .leftChild = NULL, .rightChild = NULL};  
  Node Node3 = {.data = 100, .rank = 2, .leftChild = &Node4, .rightChild = &Node5};
  Node Node2 = {.data = 10, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node3};
  Node *root;

  root = leftRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node3, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node2, (root->leftChild)->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node4, (root->leftChild)->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node6, (root->rightChild)->rightChild);
    
  // TEST_ASSERT_EQUAL(0, Node6.rank);
  // TEST_ASSERT_EQUAL(1, Node5.rank);  
  // TEST_ASSERT_EQUAL(0, Node4.rank);
  // TEST_ASSERT_EQUAL(1, Node3.rank);
  // TEST_ASSERT_EQUAL(0, Node2.rank);
  // TEST_ASSERT_EQUAL(0, Node1.rank);
}

/**
*     (3)      (2)
*     /       /   \ 
*   (2)  -> (1)   (3)
*   /
* (1)
*/
void test_rightRotate_should_rotate_to_balance_tree(){
  Node Node3 = {.data = 3, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 2, .rank = 1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 1, .rank = 2, .leftChild = &Node2, .rightChild = NULL};
  Node *root;

  root = rightRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->leftChild);
  
  // TEST_ASSERT_EQUAL(0, Node2.rank);
  // TEST_ASSERT_EQUAL(0, Node1.rank);
  // TEST_ASSERT_EQUAL(0, Node3.rank);
}

/**
*       (50)              (10)
*       /  \              /   \ 
*    (10)  (100) =>    (5)   (50)
*    /   \            /     /     \ 
*  (5)   (30)      (1)   (30)     (100)
*  /
*(1)
*/
void test_rightRotate_6_elem_should_rotate_to_balance_tree(){
  Node Node6 = {.data = 100, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 30, .rank = 1, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 1, .rank = 0, .leftChild = NULL, .rightChild = NULL};  
  Node Node3 = {.data = 5, .rank = 2, .leftChild = &Node4, .rightChild = NULL};
  Node Node2 = {.data = 10, .rank = 0, .leftChild = &Node3, .rightChild = &Node5};
  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node6};
  Node *root;

  root = rightRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node4, (root->leftChild)->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, (root->rightChild)->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node6, (root->rightChild)->rightChild);
    
  // TEST_ASSERT_EQUAL(0, Node6.rank);
  // TEST_ASSERT_EQUAL(1, Node5.rank);  
  // TEST_ASSERT_EQUAL(0, Node4.rank);
  // TEST_ASSERT_EQUAL(1, Node3.rank);
  // TEST_ASSERT_EQUAL(0, Node2.rank);
  // TEST_ASSERT_EQUAL(0, Node1.rank);
}

/**
*     (20)         (20)       (15)
*     /            /          /  \
*   (10)  ->    (15)    -> (10)  (20) 
*      \        /           
*      (15)  (10)             
*/
void test_doubleRightRotate_should_rotate_to_balance_tree(){
  Node Node3 = {.data = 15, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 10, .rank = 1, .leftChild = NULL, .rightChild = &Node3};
  Node Node1 = {.data = 20, .rank = 2, .leftChild = &Node2, .rightChild = NULL};
  Node *root;
  
  root = doubleRightRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node3, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);
  
  // TEST_ASSERT_EQUAL(0, Node2.rank);
  // TEST_ASSERT_EQUAL(0, Node1.rank);
  // TEST_ASSERT_EQUAL(0, Node3.rank);
}

/**
*      (50)                 (30)
*      /  \                 /   \ 
*   (10)  (100)    =>    (10)   (50)
*   /   \                /      /  \ 
*(5)    (30)           (5)    (40) (100)
*          \
*          (40)
*/
void test_doubleRightRotate_6_elem_should_rotate_to_balance_tree(){
  Node Node6 = {.data = 100, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 40, .rank = 1, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 30, .rank = 0, .leftChild = NULL, .rightChild = &Node5};  
  Node Node3 = {.data = 5, .rank = 2, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 10, .rank = 0, .leftChild = &Node3, .rightChild = &Node4};
  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node6};
  Node *root;

  root = doubleRightRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node4, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, (root->leftChild)->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, (root->rightChild)->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node6, (root->rightChild)->rightChild);
    
  // TEST_ASSERT_EQUAL(0, Node6.rank);
  // TEST_ASSERT_EQUAL(1, Node5.rank);  
  // TEST_ASSERT_EQUAL(0, Node4.rank);
  // TEST_ASSERT_EQUAL(1, Node3.rank);
  // TEST_ASSERT_EQUAL(0, Node2.rank);
  // TEST_ASSERT_EQUAL(0, Node1.rank);
}

/**
*      (50)                 (30)
*      /  \                 /   \ 
*   (10)  (100)    =>    (10)   (50)
*   /   \                /  \       \ 
*(5)    (30)           (5)   (20)   (100)
*      / 
*   (20)
*/
void test_doubleRightRotate_6_elem2_should_rotate_to_balance_tree(){
  Node Node6 = {.data = 100, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 20, .rank = 1, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 30, .rank = 0, .leftChild = &Node5, .rightChild = NULL};  
  Node Node3 = {.data = 5, .rank = 2, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 10, .rank = 0, .leftChild = &Node3, .rightChild = &Node4};
  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node6};
  Node *root;

  root = doubleRightRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node4, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, (root->leftChild)->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, (root->leftChild)->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node6, (root->rightChild)->rightChild);
    

}


/**
*   (10)      (10)            (15)
*      \         \            /   \
*      (20)  ->  (15)   -> (10)   (20) 
*      /            \           
*   (15)            (20)             
*/
void test_doubleLeftRotate_should_rotate_to_balance_tree(){
  Node Node3 = {.data = 15, .rank = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 20, .rank = 1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 10, .rank = 2, .leftChild = NULL, .rightChild = &Node2};
  Node *root;
  
  root = doubleLeftRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node3, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}
