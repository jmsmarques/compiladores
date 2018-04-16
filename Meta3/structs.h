#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _tree_node* node;
typedef struct _tree_node{
    char* tag;
    node child;
    node sibling;
}tree_node;

typedef struct _sym_table* table;
typedef struct _sym_table{
    char* tag;
    table next;
}sym_table;

int yylex(void);
void yyerror (char *s);
node createNode(char* tagValue);
node createNodeEmpty();
node createNodeTerminal(char* tagValue, char* value);
void addChild(node father, node son);
void addNullChild(node father);
void addSibling(node sibling1, node sibling2);
void typeSpecDef(node up, char* newTag);
void printTree(node root, int level);
void freeTree(node root);
node checkNull(node no);

void printTable(table root);
table createSymbol(char* tagValue);
void insertInTable(table root, char* tagValue);
table startTable();
char* getParamList(node root);
void checkFuncDec(node root, table symTab);
void turnLowerCase(char* string);

extern char flag;
extern char printFlag;
extern table symTab;
extern node root;

#endif