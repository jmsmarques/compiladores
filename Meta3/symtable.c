#include "structs.h"

gTable startTable() {
    gTable symTab;
    symTab = createSymbolGTable("===== Global Symbol Table =====", "", NULL);
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
    aux->param = NULL;
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

int searchFuncDef(table root, char* tagValue) { //procura tabela de definicao de uma funcao
    char* aux = NULL;
    aux = (char*)malloc((strlen(tagValue) + 35) * sizeof(char));
    sprintf(aux, "===== Function %s Symbol Table =====", tagValue);
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

table startAuxTable(node tree, table root, char* tagValue, char* tagType) {
    table aux = NULL;
    table params = getParamList(tree->child->sibling->sibling->child);
    while(root->next) {
        root = root->next;
    }
    root->next = createSymbolTable(tagValue, "");
    root->next->next = createSymbolTable("return", lowerCase(tagType));
    if(params) {
        aux = root->next->next;
        while(params) { //caso tenha parametros poe os na tabela
            if(strcmp(params->tag, "") != 0) {
                aux->next = createSymbolTable(strdup(params->tag), strdup(params->type));
                aux = aux->next;
                aux->param = strdup("param");
            }
            params = params->next;
        }
        aux->next = createSymbolTable("", "");
    }
    else {
        root->next->next->next = createSymbolTable("", "");
    }
    root = root->next;
    return root;
}

void insertInAuxTable(table root, table node) { //insere linha na tabela de uma funcao
    while(strcmp(root->next->tag, "") != 0) {
        root = root->next;
    }
    node->next = root->next;
    root->next = node;
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
        table func;
        if(strcmp(root->tag, "FuncDeclaration") == 0) {
            if(!searchFuncDec(symTab, removeId(root->child->sibling->tag)))
                analiseFuncDec(root, symTab);
        }
        else if(strcmp(root->tag, "FuncDefinition") == 0) {
            aux = removeId(root->child->sibling->tag);
            if(!searchFuncDef(auxSymTab, aux)) { //verifica se funcao ja foi definida (V se nao tiver sido)
                if(!checkDeclaration(symTab, aux)) { //verifica se funcao ja foi declarada (V se nao tiver sido)
                    analiseFuncDec(root, symTab); //cria declaracao na tabela global
                }
                func = createFuncTable(root, auxSymTab); //cria definicao na tabela de simbolos
                analiseFuncBody(root->child->sibling->sibling->sibling, symTab, func);
            }
            else {
                //funcao ja definida
            }
        }
        else if(strcmp(root->tag, "Declaration") == 0) {
            aux = removeId(root->child->sibling->tag);
            if(!checkDeclaration(symTab, aux)) { //Se variavel nao estiver declarada
                analiseDec(root, symTab);
                if(root->child->sibling->sibling) {
                    annotedDecOp(root->child->sibling->sibling, symTab, auxSymTab);
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

void analiseFuncDec(node root, gTable symTab) { //cria declaracao na tabela global
    char* aux;
    table aux1;
    //falta marcar na tabela de simbolos das funcoes
    aux = removeId(root->child->sibling->tag);
    aux1 = getParamList(root->child->sibling->sibling->child);
    insertInTable(symTab, aux, lowerCase(root->child->tag), aux1);

    free(aux);
}

table createFuncTable(node root, table auxSymTab) {
    table func;
    char* aux = removeId(root->child->sibling->tag);
    aux = (char*)realloc(aux, (strlen(aux) + 35) * sizeof(char));
    sprintf(aux, "===== Function %s Symbol Table =====", strdup(aux));
    func = startAuxTable(root, auxSymTab, aux, root->child->tag);
    return func;
}

void analiseDec(node root, gTable symTab) {
    char* aux;

    aux = removeId(root->child->sibling->tag);
    insertInTable(symTab, aux, lowerCase(root->child->tag), NULL);

    free(aux);
}

void analiseDecF(node root, table symTab) { //verifica se funcao ja foi definida se nao foi define
    char* aux;
    table aux1;

    aux = removeId(root->child->sibling->tag);
    if(!checkFuncVarDec(symTab, aux)) { //verifica se funcao ja foi definida (V se nao estiver)
        aux1 = createSymbolTable(aux, lowerCase(root->child->tag));
        insertInAuxTable(symTab, aux1);
    }
    
    free(aux);
}

void analiseFuncBody(node root, gTable symTab, table auxSymTab) {
    if(!root) {
        return;
    }
    
    int aux = 1;

    if(strcmp(root->tag, "Declaration") == 0) {
        analiseDecF(root, auxSymTab);
        aux = 0;
        if(root->child->sibling->sibling) {
            annotedDecOp(root->child->sibling->sibling, symTab, auxSymTab);
        }
    }

    annoteTree(root, symTab, auxSymTab);
    if(aux)
        analiseFuncBody(root->child, symTab, auxSymTab);
    analiseFuncBody(root->sibling, symTab, auxSymTab);
}

void printGTable(gTable root) {
    if(root) {
        if(strcmp(root->type, "") == 0) {
            printf("%s", root->tag);
        }
        else if(strcmp(root->tag, "") != 0){
            printf("%s\t%s", root->tag, root->type);
        }
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
        /*if(strcmp(param->tag, "") != 0)
            printf(" %s", param->tag);*/
        if(param->next) {
            printf(",");
        }
        printParams(param->next);
        free(param->tag);
        free(param->type);
        free(param);
    }
}

void printTable(table root) {
    if(root) {
        if(strcmp(root->type, "") == 0) {
            printf("%s", root->tag);
        }
        else if(strcmp(root->tag, "") != 0){
            printf("%s\t%s", root->tag, root->type);
        }
        if(root->param)
            printf("\t%s", root->param);
        printf("\n");
        printTable(root->next);
        free(root->tag);
        free(root->type);
        free(root->param);
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

int checkDeclaration(gTable symTab, char* dec) { //verifica se variavel ja foi declarada globalmente
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
    if(symTab == NULL || strcmp("", symTab->tag) == 0) {
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