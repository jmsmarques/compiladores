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
node createNodeTerminal(char* tagValue, char* value);
void addChild(node father, node son);
void addNullChild(node father);
void addSibling(node sibling1, node sibling2);
void printTree(node root, int level);
void freeTree(node root);

extern char flag;