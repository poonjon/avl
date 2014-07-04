#include "AVL.h"
#include "AVLInt.h"
#include "unity.h"
#include "Rotations.h"

void setUp(){}
void tearDown(){}

/**
*     1
*/
void test_addavl_node1_should_pass(){
  Node Node1 = {.data = 1, .balance = 2, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &Node1);
  
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
  
  root = avlAddInt(root, &Node1);
  root = avlAddInt(root, &Node2);
  
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
  
  root = avlAddInt(root, &Node1);
  root = avlAddInt(root, &Node2);
  root = avlAddInt(root, &Node3);
  
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
  
  root = avlAddInt(root, &Node1);
  root = avlAddInt(root, &Node2);
  root = avlAddInt(root, &Node3);
  root = avlAddInt(root, &Node4);
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
  
  root = avlAddInt(root, &Node1);
  root = avlAddInt(root, &Node2);
  root = avlAddInt(root, &Node3);
  root = avlAddInt(root, &Node4);
  root = avlAddInt(root, &Node5);
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
  
  root = avlAddInt(root, &Node1);
  root = avlAddInt(root, &Node2);
  root = avlAddInt(root, &Node3);
  root = avlAddInt(root, &Node4);
  root = avlAddInt(root, &Node5);
  root = avlAddInt(root, &Node6);
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
  
  root = avlAddInt(root, &Node1);
  root = avlAddInt(root, &Node2);
  root = avlAddInt(root, &Node3);
  root = avlAddInt(root, &Node4);
  root = avlAddInt(root, &Node5);
  root = avlAddInt(root, &Node6);
  root = avlAddInt(root, &Node7);
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
void test_getReplacer_should_get_NULL_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlGetReplacer(&root);
  
  TEST_ASSERT_NULL(result->leftChild);  
  TEST_ASSERT_NULL(result->rightChild);  
  TEST_ASSERT_EQUAL(1, result->data);  
  TEST_ASSERT_EQUAL(0, result->balance);  

}

/**
*     (50)
*    / 
*   20
*
*/
void test_getReplacer_should_get_50_pass(){
  Node Node2 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = NULL};
  
  Node *root = &Node1;
  Node *result;

  result = avlGetReplacer(&root);

  TEST_ASSERT_EQUAL_PTR(&Node1, result);  
  TEST_ASSERT_EQUAL(50, result->data);  
  TEST_ASSERT_EQUAL(0, root->balance);  
}

/**
*     50
*       \ 
*       (80)
*
*/
void test_getReplacer_should_get_80_case_pass(){
  Node Node2 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = NULL, .rightChild = &Node2};
  
  Node *root = &Node1;
  Node *result;

  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node2, result);  
  TEST_ASSERT_EQUAL(80, result->data);  
  TEST_ASSERT_NULL(Node1.rightChild);  
  TEST_ASSERT_EQUAL(0, root->balance);  
}

/**
*     50
*    /   \ 
*   20    (80)
*
*/
void test_getReplacer_should_get_80_case2_pass(){
  Node Node3 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 0, .leftChild = &Node2, .rightChild = &Node3};
  
  Node *root = &Node1;
  Node *result;

  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node3, result);  
  TEST_ASSERT_EQUAL(80, result->data);  
  TEST_ASSERT_NULL(Node1.rightChild);  
  TEST_ASSERT_EQUAL_PTR(&Node2, Node1.leftChild);  
  TEST_ASSERT_EQUAL(-1, root->balance);  
}

/**
*     50
*    /   \ 
*   20    (80)
*         /
*       70
*
*/
void test_getReplacer_should_get_80_case3_pass(){
  Node Node4 = {.data = 70, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 80, .balance = -1, .leftChild = &Node4, .rightChild = NULL};
  Node Node2 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = &Node3};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node3, result);  
  TEST_ASSERT_EQUAL(80, result->data);    
  TEST_ASSERT_EQUAL_PTR(&Node4, Node1.rightChild);  
  TEST_ASSERT_EQUAL(0, root->balance);  
}

/**
*     50                   50 
*    /   \                /   \   
*   25    200   =>     25    200 
*         /  \               / 
*       150  (220)          150 
*
*/
void test_getReplacer_should_get_220_pass(){
  Node Node5 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 200, .balance = 0, .leftChild = &Node4, .rightChild = &Node5};
  Node Node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = &Node3};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node5, result);  
  TEST_ASSERT_EQUAL(220, result->data);    
  TEST_ASSERT_EQUAL(1, root->balance);  
}

/**
*     50                     50 
*    /   \                  /   \   
*   25    200      =>     25    200 
*  /      /  \           /     /   \
* 1     150  (250)      1    150   220
*             /
*           220
*/
void test_getReplacer_should_get_250_pass(){
  Node Node7 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 250, .balance = -1, .leftChild = &Node7, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 200, .balance = 1, .leftChild = &Node5, .rightChild = &Node6};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = &Node4};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node6, result);  
  TEST_ASSERT_EQUAL(250, result->data);    
  TEST_ASSERT_EQUAL(0, root->balance);  
}

/**
*     50                     50              25  
*    /   \                  /               /  \
*   25   (150)      =>     25         =>   1    50 
*  /                      /       
* 1                      1 
*        
*        
*/
void test_getReplacer_should_get_150_pass(){
  Node Node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = -1, .leftChild = &Node2, .rightChild = &Node4};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node4, result);  
  TEST_ASSERT_EQUAL(150, result->data);    
  TEST_ASSERT_EQUAL(0, root->balance);  
}

/**
*     100                    100                 50  
*    /   \                  /  \               /   \
*   25    150      =>      25  150      =>    25    100 
*  / \      \             / \                /  \   /   \
* 1  50     (200)        1   50             1   40 75  150
*   /  \                    /  \ 
*  40   75                40    75 
*/
void test_getReplacer_should_get_200_pass(){
  Node Node8 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node7 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node8};
  Node Node6 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 50, .balance = 0, .leftChild = &Node5, .rightChild = &Node6};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node8, result);  
  TEST_ASSERT_EQUAL(200, result->data);    
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(50, root->data);  
}

/**
*     100                   100                 50  
*    /   \                  /  \               /   \
*   25    150      =>      25  150      =>    25    100 
*  / \      \             / \                /      /   \
* 1  50     (200)        1   50             1      75  150
*      \                       \ 
*       75                      75 
*/
void test_getReplacer_should_get_200_case2_pass(){
  Node Node7 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node7};
  Node Node5 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 50, .balance = 1, .leftChild = NULL, .rightChild = &Node5};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node6};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node7, result);  
  TEST_ASSERT_EQUAL(200, result->data);    
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(50, root->data);  
}

/**
*     100                   100                 50  
*    /   \                  /  \               /   \
*   25    150      =>      25  150      =>    25    100 
*  / \      \             / \                /  \      \
* 1  50     (200)        1   50             1   40     150
*    /                      /
*   40                     40 
*/
void test_getReplacer_should_get_200_case3_pass(){
  Node Node7 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node7};
  Node Node5 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 50, .balance = -1, .leftChild = NULL, .rightChild = &Node5};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node6};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node7, result);  
  TEST_ASSERT_EQUAL(200, result->data);    
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(50, root->data);  
}

/**
*      100                   100                 40  
*     /   \                  /  \               /   \
*    40    150      =>      40  150      =>    25    100 
*   / \      \             / \                /  \      \
*  25  75     (200)       25  75             1   75     150
* /   /                  /    /             /
*1   50                 1    50           50
*/
void test_getReplacer_should_get_200_case4_pass(){
  Node Node8 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node7 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node8};
  Node Node6 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 75, .balance = -1, .leftChild = &Node6, .rightChild = NULL};
  Node Node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 25, .balance = -1, .leftChild = &Node4, .rightChild = NULL};
  Node Node2 = {.data = 40, .balance = 0, .leftChild = &Node3, .rightChild = &Node5};
  Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  
  Node *root = &Node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node8, result);  
  TEST_ASSERT_EQUAL(200, result->data);    
  TEST_ASSERT_EQUAL(1, root->balance);  
  TEST_ASSERT_EQUAL(40, root->data);  
}

/**
*     (1)
*/
void test_avlRemove_left_tree_should_get_NULL_pass(){
  Node Node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node nodeToRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);
  
  TEST_ASSERT_NULL(root);  
  TEST_ASSERT_NULL(result->leftChild);  
  TEST_ASSERT_NULL(result->rightChild);  
  TEST_ASSERT_EQUAL(1, result->data);  
  TEST_ASSERT_EQUAL(0, result->balance);  

}

/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   150
 *             \                  \
 *             200                200
 *
 */
void test_avlRemove_left_tree_cannot_be_found_should_get_NULL_pass(){
  Node Node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node4};
  Node Node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = &Node3};
  Node nodeToRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);
  
  TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  TEST_ASSERT_EQUAL(150, root->rightChild->data);  
  TEST_ASSERT_NULL(result);
  TEST_ASSERT_EQUAL(50, root->data);  
  
}

/**
*      50           50
*     /  \     =>     \
* (25)    150          150
*/
void test_avlRemove_left_tree_should_get_25_pass(){
  Node Node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 0, .leftChild = &Node2, .rightChild = &Node3};
  Node nodeToRemove = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);
  
  TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  TEST_ASSERT_EQUAL(25, result->data);  
  TEST_ASSERT_EQUAL(150, root->rightChild->data);  
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);  
  TEST_ASSERT_EQUAL(1, root->balance);  
  TEST_ASSERT_EQUAL(50, root->data);  
  
}

/**
*      50           150
*     /  \     =>   /  \
*   (25) 150      50   200
*          \
*          200 
*/
void test_avlRemove_left_tree_should_get_25_case2_pass(){
  Node Node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node4};
  Node Node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = &Node3};
  Node nodeToRemove = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);
  
  TEST_ASSERT_EQUAL_PTR(&Node3, root);  
  TEST_ASSERT_EQUAL(25, result->data);  
  TEST_ASSERT_EQUAL(50, root->leftChild->data);  
  TEST_ASSERT_EQUAL(200, root->rightChild->data);   
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);  
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(150, root->data);  
  
}

/**
*      50               50
*     /  \     =>      /  \
*   (25) 150         1    150
*   /      \                \ 
*  1       200              200 
*/
void test_avlRemove_left_tree_should_get_25_case3_pass(){
  Node Node5 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node5};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 50, .balance = 0, .leftChild = &Node2, .rightChild = &Node4};
  Node nodeToRemove = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);
  printf("%d", root->leftChild->leftChild->data);
  TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  TEST_ASSERT_EQUAL(25, result->data); 
  TEST_ASSERT_EQUAL(1, root->leftChild->data);  
  TEST_ASSERT_EQUAL(150, root->rightChild->data);    
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  TEST_ASSERT_EQUAL(1, root->rightChild->balance);    
  TEST_ASSERT_EQUAL(1, root->balance);  
  TEST_ASSERT_EQUAL(50, root->data);  
  
}

/** 
*     100                    100                150
*    /   \                  /   \               /  \
*   25    200      =>     25    200     =>    100   200
*  /      /  \                 /   \         / \    /   \
*(1)    150  220             150   220     25 120 175  220
*      /  \                  /  \                       
*    120  175               120 175         
*/
void test_avlRemove_left_tree_should_get_1_pass(){
  Node Node8 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node7 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = 0, .leftChild = &Node6, .rightChild = &Node7};
  Node Node4 = {.data = 200, .balance = -1, .leftChild = &Node5, .rightChild = &Node8};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 100, .balance = 1, .leftChild = &Node2, .rightChild = &Node4};
  Node nodeToRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;


  result = avlRemove(&root, &nodeToRemove);

  TEST_ASSERT_EQUAL_PTR(&Node5, root);  
  TEST_ASSERT_EQUAL(1, result->data);  
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(100, root->leftChild->data);  
  TEST_ASSERT_EQUAL(200, root->rightChild->data);    
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  TEST_ASSERT_EQUAL(0, root->rightChild->balance);  
  TEST_ASSERT_EQUAL(150, root->data);  
  TEST_ASSERT_EQUAL(220, root->rightChild->rightChild->data);  
}

/**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /  \       \
 *   1    150  220              150  220        25  120     220
 *       /                     /
 *     120                   120
*/
void test_avlRemove_left_tree_should_get_1_case2_pass(){
  Node Node7 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = -1, .leftChild = &Node6, .rightChild = NULL};
  Node Node4 = {.data = 200, .balance = -1, .leftChild = &Node5, .rightChild = &Node7};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 100, .balance = 1, .leftChild = &Node2, .rightChild = &Node4};
  Node nodeToRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);

  TEST_ASSERT_EQUAL_PTR(&Node5, root);  
  TEST_ASSERT_EQUAL(1, result->data);  
  TEST_ASSERT_EQUAL(100, root->leftChild->data);  
  TEST_ASSERT_EQUAL(200, root->rightChild->data);    
  TEST_ASSERT_EQUAL(0, root->leftChild->balance);  
  TEST_ASSERT_EQUAL(1, root->rightChild->balance);  
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(150, root->data);  
   
}

/**
*     100                    100                150  
*    /   \                  /  \               /   \
*   25    200      =>      25  200      =>    100  200
*  /      /  \                 /  \          /    /   \
* (1)   150  220            150   220       25   175  220
*         \                    \ 
*          175                  175 
*/
void test_avlRemove_left_tree_should_get_1_case3_pass(){
  Node Node7 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node6 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node6};
  Node Node4 = {.data = 200, .balance = -1, .leftChild = &Node5, .rightChild = &Node7};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 100, .balance = 1, .leftChild = &Node2, .rightChild = &Node4};
  Node nodeToRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);
  
  TEST_ASSERT_EQUAL_PTR(&Node5, root);  
  TEST_ASSERT_EQUAL(1, result->data);  
  TEST_ASSERT_EQUAL(100, root->leftChild->data);  
  TEST_ASSERT_EQUAL(200, root->rightChild->data);  
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(150, root->data);  
   
}

/**
*     100                   100                 200  
*    /   \                  /  \               /   \
*   25    200      =>      25  200      =>   100    220
*  /      /   \                / \          /   \     \
* (1)   150   220           150  220       25   150   250
*        \     \               \     \            \
*        175    250             175  250          175
*/
void test_avlRemove_left_tree_should_get_1_case4_pass(){
  Node Node8 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node7 = {.data = 220, .balance = 1, .leftChild = NULL, .rightChild = &Node8};
  Node Node6 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node5 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node6};
  Node Node4 = {.data = 200, .balance = 0, .leftChild = &Node5, .rightChild = &Node7};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  Node Node1 = {.data = 100, .balance = 1, .leftChild = &Node2, .rightChild = &Node4};
  Node nodeToRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &Node1;
  Node *result;

  result = avlRemove(&root, &nodeToRemove);

  TEST_ASSERT_EQUAL_PTR(&Node4, root);  
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);  
  TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild->leftChild);  
  TEST_ASSERT_EQUAL(100, root->leftChild->data);  
  TEST_ASSERT_EQUAL(220, root->rightChild->data);  
  TEST_ASSERT_EQUAL(1, result->data);  
  TEST_ASSERT_EQUAL(200, root->data);  
  TEST_ASSERT_EQUAL(-1, root->balance);  
   
}

/**
*     50                    50        
*    /  \                  /  \       
*  (25)   200      =>     40  200     
*    \
*     40
*/
void test_avlRemove_left_tree_should_get_25_case5_pass(){
  Node Node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = 1, .leftChild = NULL, .rightChild = &Node3};
  Node Node1 = {.data = 50, .balance = -1, .leftChild = &Node2, .rightChild = &Node4};
  Node nodeToRemove = {.data = 25, .balance = 1, .leftChild = NULL, .rightChild = &Node3};
  Node *root = &Node1;
  Node *result;
  result = avlRemove(&root, &nodeToRemove);

  TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  TEST_ASSERT_EQUAL_PTR(&Node3, root->leftChild);  
  TEST_ASSERT_EQUAL(25, result->data);  
  TEST_ASSERT_EQUAL(40, root->leftChild->data);  
  TEST_ASSERT_EQUAL(200, root->rightChild->data);  
  TEST_ASSERT_EQUAL(0, root->balance);  
  TEST_ASSERT_EQUAL(50, root->data);  
   
}

/**
*     50                    50        
*    /  \                  /  \       
*  (25)   200      =>     1  200     
*   / \                   \
*  1  40                   40
*/
void test_avlRemove_left_tree_should_get_25_case6_pass(){
  Node Node5 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node4 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node Node2 = {.data = 25, .balance = 0, .leftChild = &Node3, .rightChild = &Node4};
  Node Node1 = {.data = 50, .balance = -1, .leftChild = &Node2, .rightChild = &Node5};
  Node nodeToRemove = {.data = 25, .balance = 0, .leftChild = &Node3, .rightChild = &Node4};
  Node *root = &Node1;
  Node *result;
  result = avlRemove(&root, &nodeToRemove);
  printf("%d", root->leftChild->leftChild->data);
  TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  TEST_ASSERT_EQUAL_PTR(&Node3, root->leftChild);  
  TEST_ASSERT_EQUAL(25, result->data);  
  TEST_ASSERT_EQUAL(1, root->leftChild->data);  
  TEST_ASSERT_EQUAL(200, root->rightChild->data);  
  TEST_ASSERT_EQUAL(-1, root->balance);  
  TEST_ASSERT_EQUAL(50, root->data);  
   
}

// /**
// *   (150)                   90       
// *    /  \                  /  \       
// *  25   200      =>      25     200     
// *  / \     \             / \      \
// * 1  40     250        1   40     250
// *      \           
// *      90           
// */
// void test_avlRemove_left_tree_should_get_150_pass(){
  // Node Node7 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node6 = {.data = 200, .balance = 1, .leftChild = NULL, .rightChild = &Node7};
  // Node Node5 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node4 = {.data = 40, .balance = 1, .leftChild = NULL, .rightChild = &Node5};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  // Node Node1 = {.data = 150, .balance = -1, .leftChild = &Node2, .rightChild = &Node6};
  // Node nodeToRemove = {.data = 150, .balance = -1, .leftChild = &Node2, .rightChild = &Node6};
  // Node *root = &Node1;
  // Node *result;
  
  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node5, root);  
  // TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);  
  // TEST_ASSERT_EQUAL(150, result->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(200, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(0, root->balance);  
  // TEST_ASSERT_EQUAL(90, root->data);  
   
// }

// /**
// *   (150)                   90       
// *    /  \                  /  \       
// *  25   200      =>      25     200     
// *  / \     \             / \      \
// * 1  50     250        1   50     250
// *   /  \                   /
// *  40   90                40
// */
// void test_avlRemove_left_tree_should_get_150_case2_pass(){
  // Node Node8 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node7 = {.data = 200, .balance = 1, .leftChild = NULL, .rightChild = &Node8};
  // Node Node6 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node5 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node4 = {.data = 50, .balance = 0, .leftChild = &Node4, .rightChild = &Node6};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  // Node Node1 = {.data = 150, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  // Node nodeToRemove = {.data = 150, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  // Node *root = &Node1;
  // Node *result;
  
  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node6, root);  
  // TEST_ASSERT_EQUAL_PTR(&Node2, root->leftChild);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(200, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(150, result->data);  
  // TEST_ASSERT_EQUAL(-1, root->balance);  
  // TEST_ASSERT_EQUAL(90, root->data);  
   
// }

// /**
 // *        50                 50
 // *      /   \               /  \
 // *     25   150    =>     25   150
 // *    /                  /
 // *   1                  1
 // */
// void test_avlRemove_right_tree_cannot_be_found_should_get_NULL_pass(){
  // Node Node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  // Node Node1 = {.data = 50, .balance = -1, .leftChild = &Node2, .rightChild = &Node4};
  // Node nodeToRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;

  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(150, root->rightChild->data);  
  // TEST_ASSERT_NULL(result);
  // TEST_ASSERT_EQUAL(50, root->data);  
  
// }

// /**
 // *      50             50
 // *     /  \     =>    /
 // *   25   150       25
 // */
// void test_avlRemove_right_tree_should_get_150_pass(){
  // Node Node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node1 = {.data = 50, .balance = 0, .leftChild = &Node2, .rightChild = &Node3};
  // Node nodeToRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;

  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  // TEST_ASSERT_EQUAL(150, result->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);   
  // TEST_ASSERT_EQUAL(50, root->data);  
  // TEST_ASSERT_EQUAL(-1, root->balance);  
  
// }

// /**
 // *        50                 50            25
 // *      /   \               /            /   \
 // *     25   150    =>     25       =>   1    50
 // *    /                  /
 // *   1                  1
 // */
// void test_avlRemove_right_tree_should_get_150_case2_pass(){
  // Node Node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  // Node Node1 = {.data = 50, .balance = -1, .leftChild = &Node2, .rightChild = &Node4};
  // Node nodeToRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;

  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node2, root);  
  // TEST_ASSERT_EQUAL(150, result->data);  
  // TEST_ASSERT_EQUAL(25, root->data);  
  // TEST_ASSERT_EQUAL(1, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(50, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(0, root->balance);  
  
// }

// /**
 // *        50                 50
 // *      /   \               /  \
 // *     25   150    =>     25   200
 // *    /       \          /
 // *   1       200        1
 // */
// void test_avlRemove_right_tree_should_get_200_pass(){
  // Node Node5 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node4 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node5};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = -1, .leftChild = &Node3, .rightChild = NULL};
  // Node Node1 = {.data = 50, .balance = 0, .leftChild = &Node2, .rightChild = &Node4};
  // Node nodeToRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = &Node5};
  // Node *root = &Node1;
  // Node *result;

  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  // TEST_ASSERT_EQUAL(150, result->data);  
  // TEST_ASSERT_EQUAL(50, root->data); 
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(200, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(-1, root->balance);  
  
// }

// /**
 // *        100                  100                50
 // *      /    \               /    \             /    \
 // *     25    150           25     150         25     100
 // *    /  \     \    =>    /  \          =>   /  \    /  \
 // *   1   50    200       1   50             1   40  75  150
 // *      /  \                /  \
 // *     40  75              40  75
 // */
// void test_avlRemove_right_tree_should_get_200_case2_pass(){
  // Node Node8 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node7 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node8};
  // Node Node6 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node5 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node4 = {.data = 50, .balance = 0, .leftChild = &Node5, .rightChild = &Node6};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  // Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  // Node nodeToRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;

  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node4, root);  
  // TEST_ASSERT_EQUAL(200, result->data);  
  // TEST_ASSERT_EQUAL(50, root->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(100, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(0, root->balance);  
  
// }

// /**
 // *        100                  100                50
 // *      /    \               /    \             /    \
 // *     25    150           25     150         25     100
 // *    /  \     \    =>    /  \          =>   /       /  \
 // *   1   50    200       1   50             1      75  150
 // *         \                   \
 // *         75                  75
 // */
// void test_avlRemove_right_tree_should_get_200_case3_pass(){
  // Node Node7 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node6 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node7};
  // Node Node5 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node4 = {.data = 50, .balance = 1, .leftChild = NULL, .rightChild = &Node6};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  // Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  // Node nodeToRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;

  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node4, root);  
  // TEST_ASSERT_EQUAL(200, result->data);  
  // TEST_ASSERT_EQUAL(50, root->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(100, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(0, root->balance);  
  
// }

// /**
 // *        100                  100                50
 // *      /    \               /    \             /    \
 // *     25    150           25     150         25     100
 // *    /  \     \    =>    /  \          =>   /  \       \
 // *   1   50    200       1   50             1   40      150
 // *      /                   /
 // *     40                  40
 // */
// void test_avlRemove_right_tree_should_get_200_case4_pass(){
  // Node Node7 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node6 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node7};
  // Node Node5 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node4 = {.data = 50, .balance = -1, .leftChild = &Node5, .rightChild = NULL};
  // Node Node3 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};
  // Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  // Node nodeToRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;

  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node4, root);  
  // TEST_ASSERT_EQUAL(200, result->data);  
  // TEST_ASSERT_EQUAL(50, root->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(100, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(0, root->balance);  
  
// }

// /**
 // *        100                  100                40
 // *      /    \               /    \             /    \
 // *     40    150           40     150         25     100
 // *    /  \     \    =>    /  \          =>   /       /  \
 // *   25  75   200        25  75             1      75   150
 // *  /    /              /    /                    /
 // * 1    50             1    50                  50
 // */
// void test_avlRemove_right_tree_should_get_200_case5_pass(){
  // Node Node8 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node7 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &Node8};
  // Node Node6 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node5 = {.data = 75, .balance = -1, .leftChild = &Node6, .rightChild = NULL};
  // Node Node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node3 = {.data = 25, .balance = -1, .leftChild = &Node4, .rightChild = NULL};
  // Node Node2 = {.data = 40, .balance = 0, .leftChild = &Node3, .rightChild = &Node5};
  // Node Node1 = {.data = 100, .balance = -1, .leftChild = &Node2, .rightChild = &Node7};
  // Node nodeToRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;
  
  // result = avlRemove(&root, &nodeToRemove);

  // TEST_ASSERT_EQUAL_PTR(&Node2, root);  
  // TEST_ASSERT_EQUAL(200, result->data); 
  // TEST_ASSERT_EQUAL(40, root->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(100, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(1, root->balance);  
  
// }

// /**
 // *      50             50
 // *     /  \     =>    /  \
 // *   25   200       25   150
 // *        /
 // *      150
 // */
// void test_avlRemove_right_tree_should_get_200_case6_pass(){
  // Node Node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node3 = {.data = 200, .balance = -1, .leftChild = &Node4, .rightChild = NULL};
  // Node Node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = &Node3};
  // Node nodeToRemove = {.data = 200, .balance = -1, .leftChild = &Node4, .rightChild = NULL};
  // Node *root = &Node1;
  // Node *result;
  
  // result = avlRemove(&root, &nodeToRemove);
  
  // TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  // TEST_ASSERT_EQUAL(200, result->data); 
  // TEST_ASSERT_EQUAL(50, root->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(150, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(0, root->balance);  
  
// }

// /**
 // *      50             50
 // *     /  \     =>    /  \
 // *   25   200       25   150
 // *        / \              \
 // *      150 220            220
 // *
 // * where 200 is being removed
 // */
// void test_avlRemove_right_tree_should_get_200_case7_pass(){
  // Node Node5 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node3 = {.data = 200, .balance = 0, .leftChild = &Node4, .rightChild = &Node5};
  // Node Node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node Node1 = {.data = 50, .balance = 1, .leftChild = &Node2, .rightChild = &Node3};
  // Node nodeToRemove = {.data = 200, .balance = 0, .leftChild = &Node4, .rightChild = &Node5};
  // Node *root = &Node1;
  // Node *result;
  // result = avlRemove(&root, &nodeToRemove);


  // TEST_ASSERT_EQUAL_PTR(&Node1, root);  
  // TEST_ASSERT_EQUAL(200, result->data); 
  // TEST_ASSERT_EQUAL(50, root->data);  
  // TEST_ASSERT_EQUAL(25, root->leftChild->data);  
  // TEST_ASSERT_EQUAL(150, root->rightChild->data);  
  // TEST_ASSERT_EQUAL(220, root->rightChild->rightChild->data);  
  // TEST_ASSERT_EQUAL(1, root->balance);  
  
// }













