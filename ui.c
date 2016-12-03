     
#include <stdio.h>
#include <stdlib.h>
#include "trees.h"
#include "ui.h"

/*****************************************
 * Initialize
 * This section contains the definitions of the parameters and
 * initilaize(), the function that will initialize the parameters to
 * control the operation of execute().
 *****************************************/

void print_help(char command)
{
  if ('\0' != command) {
    printf("Unknown command %c\n", command);
  }
  printf("stack: parameters are\n");
  printf("\t-h: print this message\n");
  printf("\t-p: print the representation of the tree entered as a parameter\n");
  printf("\t-e: print preorder traversal of the tree entered as a parameter\n");
  printf("\t-o: print postorder traversal of the tree entered as a parameter\n");
  printf("\t-i: print inorder traversal of the tree entered as a parameter\n");
}

/*
 * initialize(argc, argv)
 * parses the parameters to the program
 * return TRUE if successful; FALSE if there is an error
 */
int initialize(int argc, char *argv[])
{
  int arg = 1;
  char *parameter = "";
  int counter = 0;
  tree t;

  while(arg < argc) {
    parameter = argv[arg];
    switch(parameter[1]) {
    case 'h':
      print_help('\0');
      arg += 1;
      break;
    case 'p':
      counter = 0;
      print_tree("Tree: ", make_tree(NULL, argv[arg + 1], &counter));
      arg+=2;
      break;
    case 'e':
      print_preorder(make_tree(NULL, argv[arg + 1], &counter));
      printf("\n");
      arg+=2;
      break;
    case 'o':
      print_postorder(make_tree(NULL, argv[arg + 1], &counter));
      printf("\n");
      arg+=2;
      break;
    case 'i':
      print_inorder(make_tree(NULL, argv[arg + 1], &counter));
      printf("\n");
      arg+=2;
      break;
    case 'b':
      parameter = argv[arg + 1];
      t = NULL;
      for (int i = 0; parameter[i] != '\0' && i < 40; ++i) {
        t = BST_insert(t, parameter[i]);
      }
      print_tree("BST: ", t);
      arg+=2;
      break;
    default:
      print_help(parameter[1]);
      return FALSE;
    }
  }
  return TRUE;
}

/*****************************************
 * Execute
 * This section contains the definitions of execute(), the function
 * calls the functions that do the work.
 *****************************************/

int execute()
{
  return 0;                        // execution terminated normally
}

/*****************************************
 * Get
 * This section contains the functions that
 * Get an integer: get_int
 * get a float: get float
 *****************************************/

int is_whitespace(char c) {
  return (' ' == c || '\t' == c || '\n' == c);
}

char get_first_non_white(char *s) {
  for (int i = 0; '\0' != s[i] && i < 80; i++) {
    if (!is_whitespace(s[i])) {
      return(s[i]);
    }
  }
  return('\0');
}

/*
  read numbers: float and int
*/
int consume_digits(char *s)
{
  int i = 0;
  while (i < 80 && ('0' == s[i] ||
                    '1' == s[i] ||
                    '2' == s[i] ||
                    '3' == s[i] ||
                    '4' == s[i] ||
                    '5' == s[i] ||
                    '6' == s[i] ||
                    '7' == s[i] ||
                    '8' == s[i] ||
                    '9' == s[i] )
         ) {
    i++;
  }
  return i;
}

int can_be_float(char *s)
{
  int i = 0;
  if (s[i] == '-') {
    i++;
  }
  i += consume_digits(&s[i]);
  if ('\0' == s[i]) {
    return TRUE;
  }
  if ('.' == s[i]) {
    i += consume_digits(&s[i+1]) + 1;
  }
  if ('\0' == s[i]) {
    return TRUE;
  }
  return FALSE;
}

float get_float(char *msg)
{
  char buf[80] = "x";
  float f = 0.0;

  printf("%s> ", msg);
  scanf("%80s", buf);
  while(!can_be_float(buf)) {
    printf("%s is not a float> ", buf);
    scanf("%80s", buf);
  }
  sscanf(buf, "%f", &f);
  return f;
}

int can_be_int(char *s)
{
  int i = 0;
  if (s[i] == '-') {
    i++;
  }
  i += consume_digits(&s[i]);
  if ('\0' == s[i]) {
    return TRUE;
  }
  return FALSE;
}

int get_int(char *msg)
{
  char buf[80] = "x";
  int i = 0;

  printf("%s> ", msg);
  scanf("%80s", buf);
  while(!can_be_int(buf)) {
    printf("%s is not an integer> ", buf);
    scanf("%80s", buf);
  }
  sscanf(buf, "%d", &i);
  return i;
}
