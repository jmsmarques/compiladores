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
    char scope;
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
//aux struct for params
typedef struct _params_node* paramsInfo;
typedef struct _params_node{
    char* id;
    char* type;
    int var;
    paramsInfo next;
}params_node;

int yylex(void);
void yyerror (char *s);
int semanticAnalysis();
idInfo sendInfo(char* info);

//ast creation functions
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

//symbol table creation functions
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

//annotation functions
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

//errors functions
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

//code generation functions
void codeGeneration(node root, gTable symTab, table auxSymTab); //function that runs the ast and calls the function that generates code for each node
int generateCode(node root, gTable symTab, table auxSymTab); //functions that generates code
void genGlobalDeclaration(node root); //generates code for a global declaration
int genFuncBody(node root, paramsInfo paramList, int tabs, int variable, char* funcType, int flag); //generates code for a function body
void genFuncDef(node root); //generates code for a function
void genFuncDec(node root, char* type); //generates code for the first line of a definition
void genFuncParams(node root); //transforms func params to code
char* getLlvmType(char* string); //returns type in llvm language
char getLlvmSize(char* string); //return nr of bytes of a type
char* extractLiteral(char* id, char* type); //extracts literal value from string ...Lit(value)
char* reduceString(char* string, int len, int end); //aux function for extractLiteral()
char* genVariable(node root, char* type); //generates a variable with its scope or a constant
void doTabs(int nr); //does tabs
int genStore(node root, char* type, int variable, int tabs, paramsInfo paramList); //generates code for a store
int genMinusConversion(int variable, int tabs, char* type); //converts a variable to -variable
int genNotConversion(int variable, int tabs, char* type); //converts a variable to !variable
int checkIfUnary(node root); //checks if its a unary sign before an id
int genCall(node root, int variable, int tabs, paramsInfo paramList); //generates code for a function call
int genVarToTemp(node root, char* type, char* newType, int variable, int , paramsInfo paramList); //generates a temp value for a variable
int genExpr(node root, int variable, int tabs, char* type, paramsInfo paramList); //generates arithmetic code
int generateIf(node root, paramsInfo paramList, int variable, int tabs, char* funcType); //generates code for a if condition
int generateWhile(node root, paramsInfo paramList, int variable, int tabs, char* funcType); //generates code for a while condition
char* genOperationCommand(char* op, char* type); //generates a operation command (ex. Add = add)
int genParams(paramsInfo params, node root, int variable, int tabs); //associates the function params with a temp
int checkIfArgument(paramsInfo params, char* id); //checks if an id is an argument
//aux
int convertSize(char* type, char* newType, int variable, int tabs); //converts sizes
int cmpSize(char* size1, char* size2); //compares sizes of 1 and 2 returns 1 if 1 is bigger 0 if equal -1 else
int trasformToAscii(char* string); //transforms a string with a char to ascii code
int powAux(int nr, int el); //power function
int checkIfLiteral(node root); //check if node is literal
char* checkType(char* type1, char* type2); //checks type for comparisions >...
char* generateOctal(char* string); //transforms octal to int
char* extractParamType(char * string); //extracts function parameters type
int getParamVar(paramsInfo params, char* paramId); //gets temp var with the value of the parameter
char* analiseReal(char* real); //adds a . to a real if it has a e and no .

extern char flag;
extern char printFlag;
extern table auxSymTab;
extern gTable symTab;
extern node root;
extern char codeGenFlag;

#endif