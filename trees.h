            
      
#ifndef arrays_h
#define arrays_h

#define TRUE 1
#define FALSE 0 
struct node {
  char value;
  struct node *left;
  struct node *right; 
};

typedef struct node *tree;

/*
  Trees
*/

/* Test code */
tree test_tree(); 
/* Story 1 */
int root_value(tree t);
tree left_child(tree t);
tree right_child(tree t);

/* Story 0 */
tree make_tree(tree t, char *c, int *index);

/* Story 1 */
void print_tree(char *msg, tree t); 
/* Story 2 */ 
void print_preorder(tree t);

/* Story 3 */
void print_postorder(tree t);

/* Story 4 */
void print_inorder(tree t);

/*
  Binary Search Trees
*/

/* Story 5 */
tree BST_insert(tree t, char value);

/* Story 6 */
char BST_find(tree t, char target);

/*
  Queues
*/

#endif
