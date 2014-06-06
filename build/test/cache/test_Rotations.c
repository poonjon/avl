#include "unity.h"
#include "Rotations.h"


void setUp(void){}

void tearDown(void){}

void test_leftRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 3, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 2, .rank = 1, .leftChild = ((void *)0), .rightChild = &Node3};

  Node Node1 = {.data = 1, .rank = 2, .leftChild = ((void *)0), .rightChild = &Node2};

  Node *root;



  root = leftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_HEX32);









}

void test_leftRotate_6_elem_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 200, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 150, .rank = 1, .leftChild = ((void *)0), .rightChild = &Node6};

  Node Node4 = {.data = 20, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node3 = {.data = 100, .rank = 2, .leftChild = &Node4, .rightChild = &Node5};

  Node Node2 = {.data = 10, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node3};

  Node *root;



  root = leftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)(((root->leftChild)->rightChild)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_HEX32);















}

void test_rightRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 3, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 2, .rank = 1, .leftChild = &Node3, .rightChild = ((void *)0)};

  Node Node1 = {.data = 1, .rank = 2, .leftChild = &Node2, .rightChild = ((void *)0)};

  Node *root;



  root = rightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)78, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_HEX32);









}

void test_rightRotate_6_elem_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 100, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 30, .rank = 1, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 1, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node3 = {.data = 5, .rank = 2, .leftChild = &Node4, .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .rank = 0, .leftChild = &Node3, .rightChild = &Node5};

  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node6};

  Node *root;



  root = rightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)106, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->rightChild)->leftChild)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_HEX32);















}

void test_doubleRightRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 15, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .rank = 1, .leftChild = ((void *)0), .rightChild = &Node3};

  Node Node1 = {.data = 20, .rank = 2, .leftChild = &Node2, .rightChild = ((void *)0)};

  Node *root;



  root = doubleRightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_HEX32);









}

void test_doubleRightRotate_6_elem_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 100, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 40, .rank = 1, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 30, .rank = 0, .leftChild = ((void *)0), .rightChild = &Node5};

  Node Node3 = {.data = 5, .rank = 2, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .rank = 0, .leftChild = &Node3, .rightChild = &Node4};

  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node6};

  Node *root;



  root = doubleRightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->rightChild)->leftChild)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_HEX32);















}

void test_doubleRightRotate_6_elem2_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 100, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 20, .rank = 1, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 30, .rank = 0, .leftChild = &Node5, .rightChild = ((void *)0)};

  Node Node3 = {.data = 5, .rank = 2, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .rank = 0, .leftChild = &Node3, .rightChild = &Node4};

  Node Node1 = {.data = 50, .rank = 2, .leftChild = &Node2, .rightChild = &Node6};

  Node *root;



  root = doubleRightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->leftChild)->rightChild)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_HEX32);





}

void test_doubleLeftRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 15, .rank = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 20, .rank = 1, .leftChild = &Node3, .rightChild = ((void *)0)};

  Node Node1 = {.data = 10, .rank = 2, .leftChild = ((void *)0), .rightChild = &Node2};

  Node *root;



  root = doubleLeftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)222, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)224, UNITY_DISPLAY_STYLE_HEX32);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.rank)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.rank)), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.rank)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_INT);

}
