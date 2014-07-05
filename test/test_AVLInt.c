#include "unity.h"
#include "AVL.h"
#include "Rotations.h"
#include "AVLInt.h"

void setUp(void){}
void tearDown(void){}

/**
 *   (100)                    (100)
 *   /   \              =>    /   \
 * (50)  (150)              (50)  (150)
 *
 *
 *
 */
void test_avlAddInt_150_already_in_tree_should_display_error_pass(){
  NodeInt node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt *root = NULL;
  
  root = (NodeInt *)avlAddInt(root, &node1);
  root = (NodeInt *)avlAddInt(root, &node2);
  root = (NodeInt *)avlAddInt(root, &node3);
  root = (NodeInt *)avlAddInt(root, &node4);

  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
*     1
*      \
*       50
*/
void test_addavl_2_nodes__should_pass(){
  NodeInt Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt *root = NULL;
  
  root = (NodeInt *)avlAddInt(root, &Node1);
  root = (NodeInt *)avlAddInt(root, &Node2);
  
  TEST_ASSERT_EQUAL_PTR(&Node1, root);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->rightChild);
  
  TEST_ASSERT_EQUAL(1, root->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
}

/**
*     1                   50
*      \                 /  \
*       50       =>     1    100
*         \
*          100
*
*/
void test_addavl_3_nodes_should_pass(){
  NodeInt Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt *root = NULL;
  
  root = (NodeInt *)avlAddInt(root, &Node1);
  root = (NodeInt *)avlAddInt(root, &Node2);
  root = (NodeInt *)avlAddInt(root, &Node3);
  
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  
  TEST_ASSERT_EQUAL(0, root->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
}

/**
*       50     
*      /  \    
*     1    100        
*          /               
*        75               
*/
void test_addavl_4_nodes_should_pass(){
  NodeInt Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt *root = NULL;
  
  root = (NodeInt *)avlAddInt(root, &Node1);
  root = (NodeInt *)avlAddInt(root, &Node2);
  root = (NodeInt *)avlAddInt(root, &Node3);
  root = (NodeInt *)avlAddInt(root, &Node4);
  
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node4, root->rightChild->leftChild);
  
  TEST_ASSERT_EQUAL(1, root->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);
  TEST_ASSERT_EQUAL(-1, root->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->leftChild->balance);
  
}

/**
*       50     
*      /  \    
*     1    100        
*          /  \             
*        75    150           
*/
void test_addavl_5_nodes_should_pass(){
  NodeInt Node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt *root = NULL;
  
  root = (NodeInt *)avlAddInt(root, &Node1);
  root = (NodeInt *)avlAddInt(root, &Node2);
  root = (NodeInt *)avlAddInt(root, &Node3);
  root = (NodeInt *)avlAddInt(root, &Node4);
  root = (NodeInt *)avlAddInt(root, &Node5);
  
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node4, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->rightChild->rightChild);
  
  TEST_ASSERT_EQUAL(1, root->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->rightChild->balance);
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
void test_addavl_6_nodes_should_pass(){
  NodeInt Node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt *root = NULL;
  
  root = (NodeInt *)avlAddInt(root, &Node1);
  root = (NodeInt *)avlAddInt(root, &Node2);
  root = (NodeInt *)avlAddInt(root, &Node3);
  root = (NodeInt *)avlAddInt(root, &Node4);
  root = (NodeInt *)avlAddInt(root, &Node5);
  root = (NodeInt *)avlAddInt(root, &Node6);
  
  TEST_ASSERT_EQUAL_PTR(&Node3, root);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node4, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node6, root->rightChild->rightChild);
  
  TEST_ASSERT_EQUAL(0, root->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->leftChild->balance);
  TEST_ASSERT_EQUAL(1, root->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->rightChild->balance);
}

/**
*         100                      100
*        /    \                   /    \  
*      50     150       =>      50    150               
*     /  \       \            /   \   /   \
*    1    75      200        1    75 120  200                                     
*/
void test_addavl_7_nodes_should_pass(){
  NodeInt Node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt *root = NULL;
  
  root = (NodeInt *)avlAddInt(root, &Node1);
  root = (NodeInt *)avlAddInt(root, &Node2);
  root = (NodeInt *)avlAddInt(root, &Node3);
  root = (NodeInt *)avlAddInt(root, &Node4);
  root = (NodeInt *)avlAddInt(root, &Node5);
  root = (NodeInt *)avlAddInt(root, &Node6);
  root = (NodeInt *)avlAddInt(root, &Node7);
  
  TEST_ASSERT_EQUAL_PTR(&Node3, root);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node4, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node6, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node7, root->rightChild->leftChild);
  
  TEST_ASSERT_EQUAL(0, root->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->leftChild->balance);
}

 /**          
  *         (50)                  (30) 
  *         /  \                  /  \
  *      (10) (100)            (10)  (50)
  *       / \           =>     /     /  \
  *     (5) (30)            (5)   (40) (100)
  *           \        
  *           (40)
  */
void test_addavl_6_nodes_doubleRightRotate_should_pass(){
  NodeInt Node6 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node5 = {.data = 30, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node4 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node3 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node2 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeInt Node1 = {.data = 5, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  
  NodeInt *root = NULL;

  root = (NodeInt *)avlAddInt(root, &Node1);
  root = (NodeInt *)avlAddInt(root, &Node2);
  root = (NodeInt *)avlAddInt(root, &Node3);
  root = (NodeInt *)avlAddInt(root, &Node4);
  root = (NodeInt *)avlAddInt(root, &Node5);
  root = (NodeInt *)avlAddInt(root, &Node6);
  
  TEST_ASSERT_EQUAL_PTR(&Node5, root);
  TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node6, root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node4, root->rightChild->rightChild);

  TEST_ASSERT_EQUAL(0, root->balance);
  TEST_ASSERT_EQUAL(-1, root->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->leftChild->leftChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->rightChild->balance);
  TEST_ASSERT_EQUAL(0, root->rightChild->leftChild->balance);
}








