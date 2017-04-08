        
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "trees.h"                                                                 
                                                                                                                            
/* Story 0
 * As a teacher, I want to be able to create a binary tree from a
 * string so my students can create trees for my students to operate
 * on.
 */

void show_tree(char *t)
{
  int counter = 0; 
  printf("show_tree:%s\n", t);
  fflush(stdout);
  print_tree("\nProduces", make_tree(NULL, t, &counter));
}

void test0(void)
{
  printf("Test 0: make_tree\n");
  fflush(stdout);

  show_tree("(a)");
  show_tree("(a(b) ())");
  show_tree("(a(b)(c))");
  show_tree("(a(b(c(d)(e))())())");  
  show_tree("(a(b(c)(d))e)");
  show_tree("(a(()(b)))");
}

/* Story 1
 * As a programmer, I want to print a tree, so I can see it.
 */

void test1(void)
{
  tree test = NULL;

  printf("Test 1: print_tree\n");
  fflush(stdout);

  print_tree("Empty test tree", test);
  test = test_tree();
  print_tree("Test tree (a(b)(c))", test);
}

/*
 * Story 2
 * As a Programmer, I want a function to print a pre-order traversal
 * of a complete binary tree, to see how it is done.
 */

void test_preorder(char *t)
{
  int counter = 0;

  printf("print_preorder:%s\n", t);
  fflush(stdout);
  print_preorder(make_tree(NULL, t, &counter));
  printf("\n");
}

void test2(void)
{
  printf("Test 2: preorder traversal\n");
  fflush(stdout);

  test_preorder("(a)");
  test_preorder("(a(b)())");
  test_preorder("(a(b)(c))");
  test_preorder("(a(b(c(d)(e))())())");
  test_preorder("(a(b(c)(d))e)");
  test_preorder("(a(()(b)))");
}

/*
 * Story 3
 * As a Programmer, I want a function to print a post-order traversal
 * of a complete binary tree, to see how it is done.
 */

void test_postorder(char *t)
{
  int counter = 0;

  printf("print_postorder:%s\n", t);
  fflush(stdout);
  print_postorder(make_tree(NULL, t, &counter));
  printf("\n");
}

void test3(void)
{
  printf("Test 3: postorder traversal\n");
  fflush(stdout);

  test_postorder("(a)");
  test_postorder("(a(b)())");
  test_postorder("(a(b)(c))");
  test_postorder("(a(b(c(d)(e))())())");
  test_postorder("(a(b(c)(d))e)");
  test_postorder("(a(()(b)))");
}

/*
 * Story 4
 * As a Programmer, I want a function to print a in-order traversal
 * of a complete binary tree, to see how it is done.
 */

void test_inorder(char *t)
{
  int counter = 0;

  printf("print_inorder:%s\n", t);
  fflush(stdout);
  print_inorder(make_tree(NULL, t, &counter));
  printf("\n");
}

void test4(void)
{
  printf("Test 4: inorder traversal\n");
  fflush(stdout);

  test_inorder("(a)");
  test_inorder("(a(b)())");
  test_inorder("(a(b)(c))");
  test_inorder("(a(b(c(d)(e))())())");
  test_inorder("(a(b(c)(d))e)");
  test_inorder("(a(()(b)))");
}

/* test 5
 * As a Programmer, I want to create a binary search tree, to see how
 * it is done.
 */

void test_bst(char *items)
{
  tree bst = NULL;

  for (int i = 0; items[i] != '\0' && i < 40; i++) {
    bst = BST_insert(bst, items[i]);
  }
  printf("Added items %s to binary search tree\n", items);
  print_tree("Result: ", bst);
}

void test5(void)
{
  printf("Test 5: Binary Search Trees\n");
  fflush(stdout);

  test_bst("a");
  test_bst("ab");
  test_bst("abc");
  test_bst("cba");
  test_bst("bca");
}

int main(void)
{
  initialize(0, NULL);
  char * stars = "*****************************************************\n";

  printf("%s*\n* Trees\n*\n%s", stars, stars);
  test0();
  test1();
  test2();
  test3();
  test4();
  test5();
}
