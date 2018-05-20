#include "structs.h"

void codeGeneration(node root, gTable symTab, table auxSymTab) {
    if(!root)
        return;
    generateCode(root, symTab, auxSymTab);
    codeGeneration(root->child, symTab, auxSymTab);
    codeGeneration(root->sibling, symTab, auxSymTab);

}

void generateCode(node root, gTable symTab, table auxSymTab) {
    if(strcmp(root->tag, "Declaration") == 0) {
        printf("@\n");
    }
    else if(strcmp(root->tag, "FuncDeclaration") == 0) {
        printf("declare\n");
    }
    else if(strcmp(root->tag, "FuncDefinition") == 0) {
        printf("define\n");
    }
}

char* getLlvmType(char* string) {
    char* aux = NULL;
    if(!string)
        return NULL;
    if(strncmp(string, "int", 3) == 0) {
        aux = strdup("i32");
    }
    else if(strncmp(string, "double", 6) == 0 || strncmp(string, "void", 4) == 0) {
        aux = strdup(string);
    }
    else if(strncmp(string, "char", 4) == 0) {
        aux = strdup("i8");
    }
    else if(strncmp(string, "short", 5) == 0) {
        aux = strdup("i16");
    }
  
    return aux;
}