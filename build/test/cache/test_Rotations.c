#include "unity.h"
#include "Rotations.h"




void setUp(void){}

void tearDown(void){}

void test_leftRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 3, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 2, .balance = 1, .leftChild = ((void *)0), .rightChild = &Node3};

  Node Node1 = {.data = 1, .balance = 2, .leftChild = ((void *)0), .rightChild = &Node2};

  Node *root;



  root = leftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_HEX32);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

}

void test_leftRotate_6_elem_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 200, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 150, .balance = 1, .leftChild = ((void *)0), .rightChild = &Node6};

  Node Node4 = {.data = 20, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node3 = {.data = 100, .balance = 1, .leftChild = &Node4, .rightChild = &Node5};

  Node Node2 = {.data = 10, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node1 = {.data = 50, .balance = 2, .leftChild = &Node2, .rightChild = &Node3};

  Node *root;



  root = leftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)50, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)52, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)(((root->leftChild)->rightChild)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_HEX32);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node6.balance)), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((Node5.balance)), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node4.balance)), (((void *)0)), (_U_UINT)59, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

}

void test_rightRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 3, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 2, .balance = -1, .leftChild = &Node3, .rightChild = ((void *)0)};

  Node Node1 = {.data = 1, .balance = -2, .leftChild = &Node2, .rightChild = ((void *)0)};

  Node *root;



  root = rightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)80, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)81, UNITY_DISPLAY_STYLE_HEX32);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

}

void test_rightRotate_6_elem_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 100, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 30, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 1, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node3 = {.data = 5, .balance = -1, .leftChild = &Node4, .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .balance = -1, .leftChild = &Node3, .rightChild = &Node5};

  Node Node1 = {.data = 50, .balance = -2, .leftChild = &Node2, .rightChild = &Node6};

  Node *root;



  root = rightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)107, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)109, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)110, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->rightChild)->leftChild)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_HEX32);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node6.balance)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node5.balance)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node4.balance)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)118, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

}

void test_doubleRightRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 15, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .balance = 1, .leftChild = ((void *)0), .rightChild = &Node3};

  Node Node1 = {.data = 20, .balance = -2, .leftChild = &Node2, .rightChild = ((void *)0)};

  Node *root;



  root = doubleRightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_HEX32);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

}

void test_doubleRightRotate_6_elem_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 100, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 40, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 30, .balance = 1, .leftChild = ((void *)0), .rightChild = &Node5};

  Node Node3 = {.data = 5, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};

  Node Node1 = {.data = 50, .balance = -2, .leftChild = &Node2, .rightChild = &Node6};

  Node *root;



  root = doubleRightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)167, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->rightChild)->leftChild)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_HEX32);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node6.balance)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node5.balance)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node4.balance)), (((void *)0)), (_U_UINT)173, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_INT);

}

void test_doubleRightRotate_6_elem2_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 100, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 20, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 30, .balance = -1, .leftChild = &Node5, .rightChild = ((void *)0)};

  Node Node3 = {.data = 5, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 10, .balance = 1, .leftChild = &Node3, .rightChild = &Node4};

  Node Node1 = {.data = 50, .balance = -2, .leftChild = &Node2, .rightChild = &Node6};

  Node *root;



  root = doubleRightRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->leftChild)->rightChild)), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_HEX32);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node6.balance)), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node5.balance)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node4.balance)), (((void *)0)), (_U_UINT)207, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLeftRotate_should_rotate_to_balance_tree(){

  Node Node3 = {.data = 15, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 20, .balance = -1, .leftChild = &Node3, .rightChild = ((void *)0)};

  Node Node1 = {.data = 10, .balance = 2, .leftChild = ((void *)0), .rightChild = &Node2};

  Node *root;



  root = doubleLeftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)227, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)228, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)229, UNITY_DISPLAY_STYLE_HEX32);



   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)233, UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLeftRotate_6_elem_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 110, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 70, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 80, .balance = -1, .leftChild = &Node5, .rightChild = ((void *)0)};

  Node Node3 = {.data = 100, .balance = -1, .leftChild = &Node4, .rightChild = &Node6};

  Node Node2 = {.data = 10, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node1 = {.data = 50, .balance = 2, .leftChild = &Node2, .rightChild = &Node3};

  Node *root;



  root = doubleLeftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)256, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)257, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->leftChild)->rightChild)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)260, UNITY_DISPLAY_STYLE_HEX32);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node6.balance)), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node5.balance)), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node4.balance)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLeftRotate_6_elem2_should_rotate_to_balance_tree(){

  Node Node6 = {.data = 110, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 70, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 80, .balance = 1, .leftChild = ((void *)0), .rightChild = &Node5};

  Node Node3 = {.data = 100, .balance = -1, .leftChild = &Node4, .rightChild = &Node6};

  Node Node2 = {.data = 10, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node1 = {.data = 50, .balance = 2, .leftChild = &Node2, .rightChild = &Node3};

  Node *root;



  root = doubleLeftRotate(&Node1);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node4)), (_U_SINT)(_UP)((root)), (((void *)0)), (_U_UINT)289, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node3)), (_U_SINT)(_UP)((root->rightChild)), (((void *)0)), (_U_UINT)290, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node1)), (_U_SINT)(_UP)((root->leftChild)), (((void *)0)), (_U_UINT)291, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node2)), (_U_SINT)(_UP)(((root->leftChild)->leftChild)), (((void *)0)), (_U_UINT)292, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node5)), (_U_SINT)(_UP)(((root->rightChild)->leftChild)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_HEX32);

  UnityAssertEqualNumber((_U_SINT)(_UP)((&Node6)), (_U_SINT)(_UP)(((root->rightChild)->rightChild)), (((void *)0)), (_U_UINT)294, UNITY_DISPLAY_STYLE_HEX32);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node6.balance)), (((void *)0)), (_U_UINT)296, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node5.balance)), (((void *)0)), (_U_UINT)297, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node4.balance)), (((void *)0)), (_U_UINT)298, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node3.balance)), (((void *)0)), (_U_UINT)299, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((Node2.balance)), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((Node1.balance)), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT);

}

void test_getheight_3_should_pass(){

  Node Node3 = {.data = 1, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node2 = {.data = 2, .balance = -1, .leftChild = &Node3, .rightChild = ((void *)0)};

  Node Node1 = {.data = 3, .balance = -2, .leftChild = &Node2, .rightChild = ((void *)0)};





  UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((getHeight(&Node1))), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT);

 }

void test_getheight_4_should_pass(){

  Node Node6 = {.data = 110, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node5 = {.data = 70, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node4 = {.data = 80, .balance = 1, .leftChild = ((void *)0), .rightChild = &Node5};

  Node Node3 = {.data = 100, .balance = -1, .leftChild = &Node4, .rightChild = &Node6};

  Node Node2 = {.data = 10, .balance = 0, .leftChild = ((void *)0), .rightChild = ((void *)0)};

  Node Node1 = {.data = 50, .balance = 2, .leftChild = &Node2, .rightChild = &Node3};

  Node *root;



   UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((getHeight(&Node1))), (((void *)0)), (_U_UINT)338, UNITY_DISPLAY_STYLE_INT);



}
