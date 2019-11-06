/*test.cpp*/

//
// Lab week 07:
// 
// AVL unit tests based on Catch framework.  We are assuming the AVL class is now
// balancing the trees in these tests.
//

#include <iostream>
#include <vector>

#include "avl.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("(1) AVL tree with 4 nodes") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(100, -100);
  avl.insert(50, -50);
  avl.insert(150, -150);
  avl.insert(125, -125);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 4);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 50);
  REQUIRE(values[0] == -50);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 100);
  REQUIRE(values[1] == -100);
  REQUIRE(heights[1] == 2);

  REQUIRE(keys[2] == 125);
  REQUIRE(values[2] == -125);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 150);
  REQUIRE(values[3] == -150);
  REQUIRE(heights[3] == 1);
}

TEST_CASE("(2) empty tree") 
{
  avltree<int, int>  avl;

  REQUIRE(avl.size() == 0);
  REQUIRE(avl.height() == -1);
}

TEST_CASE("(3) just one node") 
{
  avltree<int, int>  avl;
	
	avl.insert(123, 88);

  REQUIRE(avl.size() == 1);
  REQUIRE(avl.height() == 0);
	
	vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

	REQUIRE(keys[0] == 123);
	REQUIRE(values[0] == 88);
  REQUIRE(heights[0] == 0);
}


TEST_CASE("(4) AVL tree test CASE I, insertion to the left") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(90, -100);
  avl.insert(199, -50);
  avl.insert(60, -150);
  avl.insert(75, -125);
  avl.insert(40, -150);
  avl.insert(20, -125);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 20);
  REQUIRE(values[0] == -125);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 40);
  REQUIRE(values[1] == -150);
  REQUIRE(heights[1] == 1);

  REQUIRE(keys[2] == 60);
  REQUIRE(values[2] == -150);
  REQUIRE(heights[2] == 2);

  REQUIRE(keys[3] == 75);
  REQUIRE(values[3] == -125);
  REQUIRE(heights[3] == 0);
	
  REQUIRE(keys[4] == 90);
  REQUIRE(values[4] == -100);
  REQUIRE(heights[4] == 1);
	  
  REQUIRE(keys[5] == 199);
  REQUIRE(values[5] == -50);
  REQUIRE(heights[5] == 0);
}

TEST_CASE("(5) AVL tree test CASE II, insertion to the left/middle") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(100, -100);
  avl.insert(80, -50);
  avl.insert(150, -150);
  avl.insert(70, -125);
  avl.insert(90, -150);
  avl.insert(85, -125);
  avl.insert(95, -155);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 7);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 70);
  REQUIRE(values[0] == -125);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 80);
  REQUIRE(values[1] == -50);
  REQUIRE(heights[1] == 1);

  REQUIRE(keys[2] == 85);
  REQUIRE(values[2] == -125);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 90);
  REQUIRE(values[3] == -150);
  REQUIRE(heights[3] == 2);
	
  REQUIRE(keys[4] == 95);
  REQUIRE(values[4] == -155);
  REQUIRE(heights[4] == 0);
  
  REQUIRE(keys[5] == 100);
  REQUIRE(values[5] == -100);
  REQUIRE(heights[5] == 1);
	  
  REQUIRE(keys[6] == 150);
  REQUIRE(values[6] == -150);
  REQUIRE(heights[6] == 0);
}


TEST_CASE("(6) AVL tree test CASE III, insertion to the right/middle") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(90, -100);
  avl.insert(80, -50);
  avl.insert(150, -150);
  avl.insert(120, -125);
  avl.insert(180, -150);
  avl.insert(100, -125);
  avl.insert(140, -155);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 7);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 80);
  REQUIRE(values[0] == -50);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 90);
  REQUIRE(values[1] == -100);
  REQUIRE(heights[1] == 1);

  REQUIRE(keys[2] == 100);
  REQUIRE(values[2] == -125);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 120);
  REQUIRE(values[3] == -125);
  REQUIRE(heights[3] == 2);
	
  REQUIRE(keys[4] == 140);
  REQUIRE(values[4] == -155);
  REQUIRE(heights[4] == 0);
  
  REQUIRE(keys[5] == 150);
  REQUIRE(values[5] == -150);
  REQUIRE(heights[5] == 1);
	  
  REQUIRE(keys[6] == 180);
  REQUIRE(values[6] == -150);
  REQUIRE(heights[6] == 0);
}

TEST_CASE("(7) AVL tree test CASE I, insertion to the right") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(100, -100);
  avl.insert(80, -50);
  avl.insert(150, -150);
  avl.insert(130, -125);
  avl.insert(170, -150);
  avl.insert(180, -125);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 6);
  REQUIRE(avl.height() == 2);

  REQUIRE(keys[0] == 80);
  REQUIRE(values[0] == -50);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 100);
  REQUIRE(values[1] == -100);
  REQUIRE(heights[1] == 1);

  REQUIRE(keys[2] == 130);
  REQUIRE(values[2] == -125);
  REQUIRE(heights[2] == 0);

  REQUIRE(keys[3] == 150);
  REQUIRE(values[3] == -150);
  REQUIRE(heights[3] == 2);
	
  REQUIRE(keys[4] == 170);
  REQUIRE(values[4] == -150);
  REQUIRE(heights[4] == 1);
	  
  REQUIRE(keys[5] == 180);
  REQUIRE(values[5] == -125);
  REQUIRE(heights[5] == 0);
}

TEST_CASE("(8) AVL tree test CASE IV, insertion to the right insode the tree") 
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(50, -100);
  avl.insert(30, -100);
  avl.insert(15, -100);
  avl.insert(45, -100);
  avl.insert(100, -100);
  avl.insert(80, -50);
  avl.insert(150, -150);
  avl.insert(130, -125);
  avl.insert(170, -150);
  avl.insert(180, -125);

  // 
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 10);
  REQUIRE(avl.height() == 3);

  REQUIRE(keys[0] == 15);
  REQUIRE(values[0] == -100);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 30);
  REQUIRE(values[1] == -100);
  REQUIRE(heights[1] == 1);

  REQUIRE(keys[2] == 45);
  REQUIRE(values[2] == -100);
  REQUIRE(heights[2] == 0);
  
  REQUIRE(keys[3] == 50);
  REQUIRE(values[3] == -100);
  REQUIRE(heights[3] == 3);
  
  REQUIRE(keys[4] == 80);
  REQUIRE(values[4] == -50);
  REQUIRE(heights[4] == 0);

  REQUIRE(keys[5] == 100);
  REQUIRE(values[5] == -100);
  REQUIRE(heights[5] == 1);

  REQUIRE(keys[6] == 130);
  REQUIRE(values[6] == -125);
  REQUIRE(heights[6] == 0);

  REQUIRE(keys[7] == 150);
  REQUIRE(values[7] == -150);
  REQUIRE(heights[7] == 2);
  
  REQUIRE(keys[8] == 170);
  REQUIRE(values[8] == -150);
  REQUIRE(heights[8] == 1);
    
  REQUIRE(keys[9] == 180);
  REQUIRE(values[9] == -125);
  REQUIRE(heights[9] == 0);
}

TEST_CASE("(9) AVL tree test, insertion to the left insode the tree")
{
  avltree<int, int>  avl;

  //
  // build a simple BST tree with 4 nodes:
  //
  avl.insert(120, -120);
  avl.insert(90, -90);
  avl.insert(130, -130);
  avl.insert(80, -80);
  avl.insert(100, -100);
  avl.insert(125, -125);
  avl.insert(150, -150);
  avl.insert(60, -60);
  avl.insert(85, -85);
  avl.insert(20, -20);

  //
  // Tests:
  //
  vector<int>  keys, values, heights;

  keys = avl.inorder_keys();
  values = avl.inorder_values();
  heights = avl.inorder_heights();

  REQUIRE(avl.size() == 10);
  REQUIRE(avl.height() == 3);

  REQUIRE(keys[0] == 20);
  REQUIRE(values[0] == -20);
  REQUIRE(heights[0] == 0);

  REQUIRE(keys[1] == 60);
  REQUIRE(values[1] == -60);
  REQUIRE(heights[1] == 1);

  REQUIRE(keys[2] == 80);
  REQUIRE(values[2] == -80);
  REQUIRE(heights[2] == 2);
    
  REQUIRE(keys[4] == 90);
  REQUIRE(values[4] == -90);
  REQUIRE(heights[4] == 1);
    
  REQUIRE(keys[3] == 85);
  REQUIRE(values[3] == -85);
  REQUIRE(heights[3] == 0);

  REQUIRE(keys[5] == 100);
  REQUIRE(values[5] == -100);
  REQUIRE(heights[5] == 0);

  REQUIRE(keys[6] == 120);
  REQUIRE(values[6] == -120);
  REQUIRE(heights[6] == 3);

  REQUIRE(keys[7] == 125);
  REQUIRE(values[7] == -125);
  REQUIRE(heights[7] == 0);
    
  REQUIRE(keys[8] == 130);
  REQUIRE(values[8] == -130);
  REQUIRE(heights[8] == 1);
      
  REQUIRE(keys[9] == 150);
  REQUIRE(values[9] == -150);
  REQUIRE(heights[9] == 0);
}
