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

void startAuxTable(table root, char* tagValue, char* tagType) {
    while(root->next) {
        root = root->next;
    }
    root->next = createSymbolTable(tagValue, "");
    root->next->next = createSymbolTable("return", lowerCase(tagType));
    root->next->next->next = createSymbolTable("", "");
}

table insertInAuxTable(table root, char* tagValue, table node) {
    while(root) {
        if(strcmp(root->tag, tagValue) == 0) {
            while(strcmp(root->next->tag, "") != 0) {
                root = root->next;
            }
            node->next = root->next;
            root->next = node;
            return node;
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

void checkFuncDec(node root, gTable symTab, table auxSymTab) {
    if(root) {
        char* aux = NULL;

        if(strcmp(root->tag, "FuncDeclaration") == 0) {
            analiseFuncDec(root, symTab);
        }
        else if(strcmp(root->tag, "FuncDefinition") == 0) {
            aux = removeId(root->child->sibling->tag);
            if(checkDeclaration(symTab, aux)) {
                createFuncTable(root, auxSymTab);
            }
            else {
                analiseFuncDec(root, symTab);
                createFuncTable(root, auxSymTab);
            }
        }
        else if(strcmp(root->tag, "Declaration") == 0) {
            aux = removeId(root->child->sibling->tag);
            if(checkDeclaration(symTab, aux)) {
                //not good
            }
            else {
                analiseDec(root, symTab);
            }
        }
        free(aux);
    }
}

void analiseFuncDec(node root, gTable symTab) {
    char* aux;
    table aux1;

    aux = removeId(root->child->sibling->tag);
    aux1 = getParamList(root->child->sibling->sibling->child);
    insertInTable(symTab, lowerCase(aux), lowerCase(root->child->tag), aux1);

    free(aux);
}

void createFuncTable(node root, table auxSymTab) {
    char* aux = removeId(root->child->sibling->tag);
    aux = (char*)realloc(aux, (strlen(aux) + 33) * sizeof(char));
    sprintf(aux, "==== Function %s Symbol Table ====", strdup(aux));
    startAuxTable(auxSymTab, aux, root->child->tag);
    free(aux);
}

void analiseDec(node root, gTable symTab) {
    char* aux;

    aux = removeId(root->child->sibling->tag);
    insertInTable(symTab, lowerCase(aux), lowerCase(root->child->tag), NULL);

    free(aux);
}

void analiseFuncBody(node root, table auxSymTab) {

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

char* removeId(char* id) {
    char* aux = (char*)malloc((strlen(id) - 3) * sizeof(char));;
    strncpy(aux, id + 3, (strlen(id) - 4) * sizeof(char));
    *(aux + strlen(id) - 4) = '\0';
    return aux;
}

void checkSemantics(node root, gTable symTab, table auxSymTab) {
    if(!root) {
        return;       
    }
    checkFuncDec(root, symTab, auxSymTab);
    checkSemantics(root->child, symTab, auxSymTab);
    checkSemantics(root->sibling, symTab, auxSymTab);
}