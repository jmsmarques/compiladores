#include "structs.h"

gTable startTable() {
    gTable symTab;
    symTab = createSymbolGTable("==== Global Symbol Table ====", "", NULL);
    insertInTable(symTab, "putchar", "int", createSymbolTable("", "int"));
    insertInTable(symTab, "getchar", "int", createSymbolTable("", "void"));
    return symTab;
}

gTable createSymbolGTable(char* tagValue, char* typeValue, table fParams) {
    gTable aux = (gTable)malloc(sizeof(g_sym_table));
    aux->tag = (char*)malloc((strlen(tagValue) + 1) * sizeof(char));
    strcpy(aux->tag, tagValue);
    aux->type = (char*)malloc((strlen(typeValue) + 1) * sizeof(char));
    strcpy(aux->type, typeValue);
    aux->params = fParams;
    aux->next = NULL;
    return aux;
}

table createSymbolTable(char* tagValue, char* typeValue) {
    table aux = (table)malloc(sizeof(sym_table));
    aux->tag = (char*)malloc((strlen(tagValue) + 1) * sizeof(char));
    strcpy(aux->tag, tagValue);
    aux->type = (char*)malloc((strlen(typeValue) + 1) * sizeof(char));
    strcpy(aux->type, typeValue);
    aux->next = NULL;
    return aux;
}

void insertInTable(gTable root, char* tagValue, char* typeValue, table param) {
    while(root->next) {
        root = root->next;
    }
    root->next = createSymbolGTable(tagValue, typeValue, param);
}

int searchFuncDec(gTable root, char* tagValue) {
    while(root) {
        if(strcmp(tagValue, root->tag) == 0) {
            return 1;
        }
        else {
            root = root->next;
        }
    }
    return 0;
}

int searchFuncDef(table root, char* tagValue) {
    char* aux = NULL;
    aux = (char*)malloc((strlen(tagValue) + 33) * sizeof(char));
    sprintf(aux, "==== Function %s Symbol Table ====", tagValue);
    while(root) {
        if(strcmp(aux, root->tag) == 0) {
            free(aux);
            return 1;
        }
        else {
            root = root->next;
        }
    }
    free(aux);
    return 0;
}

table startAuxTable(table root, char* tagValue, char* tagType) {
    while(root->next) {
        root = root->next;
    }
    root->next = createSymbolTable(tagValue, "");
    root->next->next = createSymbolTable("return", lowerCase(tagType));
    root->next->next->next = createSymbolTable("", "");
    root = root->next;

    return root;
}

void insertInAuxTable(table root, table node) {
    while(strcmp(root->next->tag, "") != 0) {
        root = root->next;
    }
    node->next = root->next;
    root->next = node;
}

table findAuxTable(table root, char* functionName) {
    while(root) {
        if(strcmp(root->tag, functionName) == 0) {
            return root;
        }
        root = root->next;
    }
    return NULL;
}

table getParamList(node root) {
    table aux;
    table init;

    if(root->child->sibling) {
        init = aux = createSymbolTable(removeId(root->child->sibling->tag), lowerCase(root->child->tag));
    }
    else {
        init = aux = createSymbolTable("", lowerCase(root->child->tag));
    }
    while(root->sibling) {
        root = root->sibling;
        if(root->child->sibling) {
            aux->next = createSymbolTable(removeId(root->child->sibling->tag), lowerCase(root->child->tag));
        }
        else {
            aux->next = createSymbolTable("", lowerCase(root->child->tag));
        }
        aux = aux->next;
    }
    return init;
}

int checkFuncDec(node root, gTable symTab, table auxSymTab) {
    if(root) {
        char* aux = NULL;
        char* functionName = NULL;
        table func;
        if(strcmp(root->tag, "FuncDeclaration") == 0) {
            if(!searchFuncDec(symTab, removeId(root->child->sibling->tag)))
                analiseFuncDec(root, symTab);
        }
        else if(strcmp(root->tag, "FuncDefinition") == 0) {
            aux = removeId(root->child->sibling->tag);
            if(!searchFuncDef(auxSymTab, aux)) {
                if(!checkDeclaration(symTab, aux)) {
                    analiseFuncDec(root, symTab);
                }
                func = createFuncTable(root, auxSymTab);
                functionName = strdup(func->tag);
                analiseFuncBody(root->child->sibling->sibling->sibling, symTab, func, functionName);
            }
            else {
                //funcao ja definida
            }
            free((char*)functionName);
        }
        else if(strcmp(root->tag, "Declaration") == 0) {
            aux = removeId(root->child->sibling->tag);
            if(!checkDeclaration(symTab, aux)) {
                analiseDec(root, symTab);
                if(root->child->sibling->sibling) {
                    root->child->sibling->sibling->type = checkVarType(root->child->sibling->sibling->tag);
                }
            }
        }
        else {
            free(aux);
            return 1;
        }
        free(aux);
    }
    return 0;
}

void analiseFuncDec(node root, gTable symTab) {
    char* aux;
    table aux1;

    aux = removeId(root->child->sibling->tag);
    aux1 = getParamList(root->child->sibling->sibling->child);
    insertInTable(symTab, lowerCase(aux), lowerCase(root->child->tag), aux1);

    free(aux);
}

table createFuncTable(node root, table auxSymTab) {
    table func;
    char* aux = removeId(root->child->sibling->tag);
    aux = (char*)realloc(aux, (strlen(aux) + 33) * sizeof(char));
    sprintf(aux, "==== Function %s Symbol Table ====", strdup(aux));
    func = startAuxTable(auxSymTab, aux, root->child->tag);
    return func;
}

void analiseDec(node root, gTable symTab) {
    char* aux;

    aux = removeId(root->child->sibling->tag);
    insertInTable(symTab, lowerCase(aux), lowerCase(root->child->tag), NULL);

    free(aux);
}

void analiseDecF(node root, table symTab, char* functionName) {
    char* aux;
    table aux1;

    aux = removeId(root->child->sibling->tag);
    if(!checkFuncVarDec(symTab, aux)) {
        aux1 = createSymbolTable(aux, lowerCase(root->child->tag));
        insertInAuxTable(symTab, aux1);
    }
    
    free(aux);
}

void analiseFuncBody(node root, gTable symTab, table auxSymTab, char* functionName) {
    if(!root) {
        return;
    }
    
    int aux = 1;

    if(strcmp(root->tag, "Declaration") == 0) {
        analiseDecF(root, auxSymTab, functionName);
        aux = 0;
        if(root->child->sibling->sibling) {
            root->child->sibling->sibling->type = checkVarType(root->child->sibling->sibling->tag);
        }
    }

    annoteTree(root, symTab, auxSymTab);
    if(aux)
        analiseFuncBody(root->child, symTab, auxSymTab, functionName);
    analiseFuncBody(root->sibling, symTab, auxSymTab, functionName);
}

void printGTable(gTable root) {
    if(root) {
        printf("%s\t%s", root->tag, root->type);
        if(root->params) {
            printf("(");
            printParams(root->params);
            printf(")");
        }
        printf("\n");    
        printGTable(root->next);
        free(root->type);
        free(root->tag);
        free(root);
    }
}

void printParams(table param) {
    if(param) {
        printf("%s", param->type);
        if(strcmp(param->tag, "") != 0)
            printf(" %s", param->tag);
        if(param->next) {
            printf("\t");
        }
        printParams(param->next);
        free(param->tag);
        free(param->type);
        free(param);
    }
}

void printTable(table root) {
    if(root) {
        printf("%s\t%s\n", root->tag, root->type);
        printTable(root->next);
        free(root->tag);
        free(root->type);
        free(root);
    }
}

char* lowerCase(char* string) {
    char* aux;
    int i = 0;
    aux = strdup(string);
    while(*(aux + i)) {
        if(*(aux + i) >= 'A' && *(aux + i) <= 'Z') {
            *(aux + i) = *(aux + i) + 32;
        }
        i++;
    }
    return aux;
}

int checkDeclaration(gTable symTab, char* dec) {
    if(symTab == NULL) {
        return 0;
    }
    else if(strcmp(dec, symTab->tag) == 0) {
        return 1;
    }
    else {
        return checkDeclaration(symTab->next, dec);
    }
}

int checkFuncVarDec(table symTab, char* dec) {
    if(symTab == NULL || strcmp("", symTab->tag)) {
        return 0;
    }
    else if(strcmp(dec, symTab->tag) == 0) {
        return 1;
    }
    else {
        return checkFuncVarDec(symTab->next, dec);
    }
}

char* removeId(char* id) {
    char* aux = (char*)malloc((strlen(id) - 3) * sizeof(char));;
    strncpy(aux, id + 3, (strlen(id) - 4) * sizeof(char));
    *(aux + strlen(id) - 4) = '\0';
    return aux;
}

void checkSemantics(node root, gTable symTab, table auxSymTab) {
    int aux;
    if(!root) {
        return;       
    }
    aux = checkFuncDec(root, symTab, auxSymTab);
    annoteTree(root, symTab, auxSymTab);
    if(aux)
        checkSemantics(root->child, symTab, auxSymTab);
    checkSemantics(root->sibling, symTab, auxSymTab);
}