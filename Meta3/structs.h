#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _tree_node* node;
typedef struct _tree_node{
    char* tag;
    char* type;
    int pos[2];
    node child;
    node sibling;
}tree_node;

typedef struct _sym_table* table;
typedef struct _sym_table{
    char* tag;
    char* type;
    char* param;
    table next;
}sym_table;

typedef struct _g_sym_table* gTable;
typedef struct _g_sym_table{
    char* tag;
    char* type;
    table params;
    gTable next;
}g_sym_table;

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
void printGTable(gTable root);
void printParams(table param);
gTable createSymbolGTable(char* tagValue, char* tagType, table fParams);
table createSymbolTable(char* tagValue, char* tagType);
void insertInTable(gTable root, char* tagValue, char* tagType, table param);
int searchFuncDec(gTable root, char* tagValue);
int searchFuncDef(table root, char* tagValue);
gTable startTable();
table getParamList(node root);
int checkFuncDec(node root, gTable symTab, table auxSymTab);
char* lowerCase(char* string);
int checkDeclaration(gTable symTab, char* dec);
int checkFuncVarDec(table symTab, char* dec);
char* removeId(char* id);
table startAuxTable(node tree, table root, char* tagValue, char* ret);
void insertInAuxTable(table root, table node);
void checkSemantics(node root, gTable symTab, table auxSymTab);
void analiseFuncDec(node root, gTable symTab, table auxSymTable);
table createFuncTable(node root, table auxSymTab);
void analiseFuncBody(node root, gTable symTab, table auxSymTab);
void analiseDec(node root, gTable symTab);
void analiseDecF(node root, table symTab);

char* checkVarType(char* string);
void annoteTree(node root, gTable symTab, table auxSymTab);
char* annoteFuncParams(gTable symTab);
int analiseFuncId(node root, char* id, gTable symTab);
void analiseVarId(node root, gTable symTab, table auxSymTab);
int checkIfOperation(char* string);
int checkIfId(char* string);
void annotedDecOp(node root, gTable symTab, table auxSymTab);
void printAnnotedTree(node root, int level);

extern char flag;
extern char printFlag;
extern table auxSymTab;
extern gTable symTab;
extern node root;

#endif