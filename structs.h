#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _tree_node* node;
typedef struct _tree_node{
    char* tag;
    node child;
    node sibling;
}tree_node;

int yylex(void);
void yyerror (char *s);
node createNode(char* tagValue);
void addChild(node father, node son);
void addSibling(node sibling1, node sibling2);
void printTree(node root);
void freeTree(node root);
extern char flag;