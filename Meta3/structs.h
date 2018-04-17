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
    char* type;
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
table createSymbol(char* tagValue, char* tagType);
void insertInTable(table root, char* tagValue, char* tagType);
table startTable();
char* getParamList(node root);
void checkFuncDec(node root, table symTab, table auxSymTab);
void turnLowerCase(char* string);
int checkDeclaration(table symTab, char* dec);
char* removeId(char* id);
void startAuxTable(table root, char* tagValue, char* ret);
table insertInAuxTable(table root, char* tagValue, table node);
void checkSemantics(node root, table symTab, table auxSymTab);
void analiseFuncDec(node root, table symTab, table auxSymTab);

extern char flag;
extern char printFlag;
extern table symTab, auxSymTab;
extern node root;

#endif