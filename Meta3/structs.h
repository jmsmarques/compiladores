#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//estrutura para passar toda a informacao necessaria do lex
typedef struct _info_node* idInfo;
typedef struct _info_node{
    char* id;
    int line;
    int col;
}info_node;

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
idInfo sendInfo(char* info);

node createNode(char* tagValue);
node createNodeEmpty();
node createNodeTerminal(char* tagValue, char* value);
void addChild(node father, node son);
void addNullChild(node father);
void addSibling(node sibling1, node sibling2);
void typeSpecDef(node up, node newTag);
void printTree(node root, int level);
void freeTree(node root);
node checkNull(node no);
void addLinesAndCols(node root, int line, int col);

void printTable(table root);
void printGTable(gTable root);
void printParams(table param);
gTable createSymbolGTable(char* tagValue, char* tagType, table fParams);
table createSymbolTable(char* tagValue, char* tagType);
void insertInTable(gTable root, char* tagValue, char* tagType, table param);
int searchFuncDec(gTable symTab, char* tagValue, node root);
table searchFuncDef(table root, char* tagValue);
gTable startTable();
table getParamList(node root);
int checkFuncDec(node root, gTable symTab, table auxSymTab);
char* lowerCase(char* string);
int checkDecAtribution(node root, gTable symTab, table auxSymTab);
int checkDeclaration(gTable symTab, char* dec, node root);
int checkFuncVarDec(table symTab, char* dec, node root);
char* removeId(char* id);
table startAuxTable(node tree, table root, char* tagValue, char* ret);
void insertInAuxTable(table root, table node);
void checkSemantics(node root, gTable symTab, table auxSymTab);
void analiseFuncDec(node root, gTable symTab, table auxSymTable);
table createFuncTable(node root, table auxSymTab);
void analiseFuncBody(node root, gTable symTab, table auxSymTab);
void analiseDec(node root, gTable symTab);
void analiseDecF(node root, table symTab);
int checkIfVoid(node root);
int checkIfParamVoid(node root);
void checkIfRepeatedParams(node root);
table removeRepeatedParams(table root);
char* getFunctionType(char* type, table symTab);
void annoteFuncBody(node root, gTable symTab, table auxSymTab);

char* checkVarType(char* string);
void checkOperationType(node root, gTable symTab, table auxSymTable);
void annoteTree(node root, gTable symTab, table auxSymTab);
char* annoteFuncParams(gTable symTab);
void analiseStore(node root);
void analiseFuncCall(node root, char* id, gTable symTab);
int analiseFuncId(node root, char* id, gTable symTab);
void analiseVarId(node root, gTable symTab, table auxSymTab);
int checkIfOperation(char* string);
int checkIfLogicalOperation(char* string);
int checkIfSpecialLogicalOperation(char* string);
int checkIfId(char* string);
void annotedDecOp(node root, gTable symTab, table auxSymTab);
void printAnnotedTree(node root, int level);
int getFunctionNrParams(gTable symTab, char* funcName);
char* getOperator(char* operatorTag);
int validateConversion(node root);
int checkIfFunction(char* type);
void checkReturn(node root, char* got, table symTab);

void errorLocation(int line, int col);
void conflictingTypes(int line, int col, char* got, char* expected);
void invalidVoid(int line, int col);
void lValue(int line, int col);
void operatorApplication(int line, int col, char* token, char* type);
void operatorsApplication(int line, int col, char* token, char* type1, char* type2);
void symbolAlreadyDefined(int line, int col, char* token);
void symbolNotFunction(int line, int col, char* token);
void unknownSymbol(int line, int col, char* token);
void wrongArguments(int line, int col, char* token, int got, int expected);

extern char flag;
extern char printFlag;
extern table auxSymTab;
extern gTable symTab;
extern node root;

#endif