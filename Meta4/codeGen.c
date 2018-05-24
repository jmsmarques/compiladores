#include "structs.h"

void codeGeneration(node root, gTable symTab, table auxSymTab) {
    if(!root)
        return;
    int aux;
    aux = generateCode(root, symTab, auxSymTab);
    if(aux) //only goes to child if node didnt correspond to any if in generateCode
        codeGeneration(root->child, symTab, auxSymTab);
    codeGeneration(root->sibling, symTab, auxSymTab);

}

int generateCode(node root, gTable symTab, table auxSymTab) {
    if(strcmp(root->tag, "Declaration") == 0) {
        genGlobalDeclaration(root);   
    }
    else if(strcmp(root->tag, "FuncDeclaration") == 0) {
        //genFuncDec(root, "declare");
        //printf("\n\n");
    }
    else if(strcmp(root->tag, "FuncDefinition") == 0) {
        genFuncDef(root);
    }
    else {
        return 1;
    }
    return 0;
}

void genGlobalDeclaration(node root) {
    /*char* code = NULL;
    char* type = getLlvmType(root->child->tag);
    
    code = (char*)malloc((strlen(root->child->sibling->tag) + strlen(type) + 30) * sizeof(char));
    */
    if(!root->child->sibling->sibling) { //if declaration doesnt have definition
        //sprintf(code, "@%s = common global %s 0, align %c", removeId(root->child->sibling->tag), type, getLlvmSize(root->child->tag));
        printf("@%s = common global %s 0, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
    }
    else { //declaration has definition
        //sprintf(code, "@%s = global %s %s, align %c", removeId(root->child->sibling->tag), type, genDecAtribution(root->child->sibling->sibling), getLlvmSize(root->child->tag));
        printf("@%s = global %s %s, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), genDecAtribution(root->child->sibling->sibling), getLlvmSize(root->child->tag));
    }
    /*printf("%s\n", code);
    free(code);*/
}

void genFuncBody(node root, int tabs, int variable, char* funcType) {
    if(!root)
        return;
    if(strcmp(root->tag, "Declaration") == 0) {
        doTabs(tabs);
        printf("%%%s = alloca %s, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
        if(root->child->sibling->sibling)
            variable = genStore(root->child->sibling, getLlvmType(root->child->tag), variable, tabs);
    }
    else if(strcmp(root->tag, "Call") == 0) {
        variable = genCall(root, variable, tabs);            
    }
    else if(strcmp(root->tag, "Store") == 0) {
        variable = genStore(root->child, getLlvmType(root->type), variable, tabs);
    }
    else if(strcmp(root->tag, "If") == 0) {
     /*   doTabs(tabs);
        if(strcmp(root->child->sibling->sibling->tag, "Null") == 0) {
            generateCondition(root->child, tabs);
            doTabs(tabs);
            printf("br i1 %%ifcond, label %%then, label %%else\n");
            doTabs(tabs);
            printf("then:\n");
            //analisar codigo dentro do if
            doTabs(tabs);
            printf("else:\n");
            //analisar codigo dentro do else
            doTabs(tabs);
            printf("ifcont:\n");
            tabs++;
            //continuacao do codigo
        }
        else {
            generateCondition(root->child, tabs);
            doTabs(tabs);
            printf("br i1 %%ifcond, label %%then\n");
            doTabs(tabs);
            printf("then:\n");
            //analisar codigo dentro do if
            doTabs(tabs);
            printf("ifcont:\n");
            tabs++;
            //continuacao do codigo
        }
     */   
    }
    else if(strcmp(root->tag, "While") == 0) {
        
    }
    else if(strcmp(root->tag, "Return") == 0) { //esta mal int nao consegue retornar short
        doTabs(tabs);
        if(strcmp(root->child->tag, "Null") != 0) {
            if(checkIfId(root->child->tag)) {
                printf("%%%d = load %s, %s* %c%s, align %c\n", variable, funcType, funcType, 
                root->child->scope, extractLiteral(root->child->tag), getLlvmSize(root->child->type));
                doTabs(tabs);
                printf("ret %s %%%d\n", funcType, variable);
                variable++;
            }
            else {
                printf("ret %s %s\n", funcType, extractLiteral(root->child->tag));
            }
        }
        else
            printf("ret void\n");
    }
    else {
        genFuncBody(root->child, tabs, variable, funcType);
    }
    genFuncBody(root->sibling, tabs, variable, funcType);
}

void genFuncDef(node root) {
    genFuncDec(root, "define");
    printf(" {\n");
    genFuncBody(root->child->sibling->sibling->sibling->child, 1, 1, getLlvmType(root->child->tag));
    if(strcmp(root->child->tag, "Void") == 0) {
        printf("ret void\n");
    }
    
    printf("}\n\n");
}

void genFuncDec(node root, char* type) {
    /*char* code = NULL;
    char* aux = genFuncParams(root->child->sibling->sibling);
    code = (char*)malloc((7 + strlen(root->child->sibling->tag) + strlen(aux)) * sizeof(char));
    sprintf(code, "define %s @%s(%s) #0 {", getLlvmType(root->child->tag), removeId(root->child->sibling->tag), aux);

    printf("%s\n", code);
    free(code);*/
    printf("%s %s @%s(", type, getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
    genFuncParams(root->child->sibling->sibling->child);
    printf(")");
}

void genFuncParams(node root) {
    /*char* params = NULL;

    params = (char*)malloc((strlen(root->child->sibling->tag) + 6) * sizeof(char));
    sprintf(params, "%s %s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
    while(root) {
        params = (char*)realloc(params, (strlen(params) + strlen(root->child->sibling->tag) + 7) * sizeof(char));
        sprintf(params, "%s, %s %s", params, getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
        root = root->sibling;
    }
    
    return params;*/
    if(strcmp(root->child->tag, "Void") == 0)
        return;

    if(root->child->sibling)
        printf("%s %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
    else
        printf("%s", getLlvmType(root->child->tag));
    root = root->sibling;
    while(root) {
        if(root->child->sibling)
            printf(", %s %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
        else
            printf(", %s", getLlvmType(root->child->tag));
        root = root->sibling;
    }
    return;
}

void generateCondition(node root, int tabs) {
    if(strcmp(root->tag, "And") == 0) {
        //recursive
    }
    else if(strcmp(root->tag, "Or") == 0) {
        //recursive
    }
    else {
        printf("%%ifcond = icmp ");
        genLogicOperation(root->tag);
        printf(" %s %s, %s\n", getLlvmType(root->type), genVariable(root->child), genVariable(root->child->sibling));
    }
}

char* genDecAtribution(node root) {
    return extractLiteral(root->tag);
}

char* getLlvmType(char* string) {
    char* aux = NULL;
    if(!string)
        return NULL;

    string = lowerCase(string);

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

char getLlvmSize(char* string) {
    char aux = '0';
    if(!string)
        return '0';

    string = lowerCase(string);

    if(strncmp(string, "int", 3) == 0 || strncmp(string, "i32", 3) == 0) {
        aux = '4';
    }
    else if(strncmp(string, "double", 6) == 0) {
        aux = '8';
    }
    else if(strncmp(string, "char", 4) == 0 || strncmp(string, "i8", 2) == 0) {
        aux = '1';
    }
    else if(strncmp(string, "short", 5) == 0 || strncmp(string, "i16", 3) == 0) {
        aux = '2';
    }
  
    return aux;
}

char* extractLiteral(char* string) {
    char* aux = NULL;
    int len = 0;

    if(!string)
        return NULL;

    if(strncmp(string, "Real", 4) == 0) {
        len = 8;
        aux = reduceString(string, len, len + 1);
    }
    else if(strncmp(string, "Int", 3) == 0) {
        len = 7;
        aux = reduceString(string, len, len + 1);
    }
    else if(strncmp(string, "Chr", 3) == 0) {
        len = 8;
        aux = reduceString(string, len, len + 2);
        //transforms char to ascii
        
        int transform = trasformToAscii(aux);
        sprintf(aux, "%d", transform);
    }
    else if(strncmp(string, "Id", 2) == 0) {
        aux = removeId(string);
    }

    return aux;
}

char* reduceString(char* string, int len, int end) {
    char* aux = (char*)malloc((strlen(string)) * sizeof(char));
    strncpy(aux, string + len, (strlen(string) - end) * sizeof(char));
    *(aux + strlen(string) - end) = '\0';

    return aux;
}

void genLogicOperation(char* operatorTag) {
    if(strcmp(operatorTag, "Eq") == 0) {
        printf("eq");
    }
    else if(strcmp(operatorTag, "Gt") == 0) {
        printf("sgt");
    }
    else if(strcmp(operatorTag, "Lt") == 0) {
        printf("slt");
    }
    else if(strcmp(operatorTag, "Ge") == 0) {
        printf("sge");
    }
    else if(strcmp(operatorTag, "Le") == 0) {
        printf("sle");
    }
    else if(strcmp(operatorTag, "Ne") == 0) {
        printf("ne");
    }
}

char* genVariable(node root) {
    char* aux = NULL;

    if(strcmp(root->tag, "Minus") == 0) {
        if(checkIfId(root->child->tag)) {
            return genVariable(root->child);
        }
        else {
            aux = (char*)malloc((strlen(root->child->tag)) * sizeof(char));
            sprintf(aux, "-%s", genVariable(root->child));
        }
    }
    else if(strcmp(root->tag, "Plus") == 0) {
        return genVariable(root->child);
    }
    else if(checkIfId(root->tag)) {
        aux = (char*)malloc((strlen(root->tag) + 8) * sizeof(char));
        sprintf(aux, "%c%s", root->scope, removeId(root->tag));
    }
    else {
        aux = extractLiteral(root->tag);
    }

    return aux;
}

void doTabs(int nr) {
    for(int n = 0; n < nr; n++)
        printf("\t");
}

int genStore(node root, char* type, int variable, int tabs) {
    doTabs(tabs);
    if(checkIfId(root->sibling->tag) || checkIfUnary(root->sibling)) {
        printf("%%%d = load %s, %s* %s, align %c\n", variable, type, 
        type, genVariable(root->sibling), getLlvmSize(type));

        if(checkIfUnary(root->sibling)) {
            variable = genMinusConversion(variable, tabs, type);
        }

        doTabs(tabs);
        printf("store %s %%%d, %s* %s, align %c\n", type, 
        variable, type, genVariable(root), getLlvmSize(type));
        variable++;
    }
    else {
        printf("store %s %s, %s* %s, align %c\n", type, genVariable(root->sibling), 
        type, genVariable(root), getLlvmSize(type));
    }
    return variable;
}

int genMinusConversion(int variable, int tabs, char* type) {
    variable++;
    if(strcmp(type, "double") == 0) {
        doTabs(tabs);
        printf("%%%d = fsub double -0.000000e+00, %%%d\n", variable, variable - 1);
    }
    else if(strcmp(type, "i32") == 0) {
        doTabs(tabs);
        printf("%%%d = sub nsw i32 0, %%%d\n", variable, variable - 1);
    }
    else {
        doTabs(tabs);
        printf("%%%d = sext %s %%%d to i32\n", variable, type, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = sub nsw i32 0, %%%d\n", variable, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = trunc i32 %%%d to %s\n", variable, variable - 1, type);
    }
    return variable;
}

int checkIfUnary(node root) {
    if(strcmp(root->tag, "Minus") == 0 || strcmp(root->tag, "Plus") == 0) {
        if(checkIfId(root->child->tag)) {
            return 1;
        }
    }
    return 0;
}

int genCall(node root, int variable, int tabs) {
    node params = root->child->sibling;
    char* aux = strdup("");
    doTabs(tabs);
    while(params) {
        if(checkIfId(params->tag) || checkIfUnary(params)) {
            variable = genVarToTemp(params, getLlvmType(params->type), "i32"/*mudar isto*/,variable, tabs);
            aux = (char*)realloc(aux, (strlen(params->type) + strlen(params->tag)) * sizeof(char));
            sprintf(aux, "%s%s %%%d", aux, "i32"/*mudar isto -> getLlvmType(params->type)*/, variable);
            variable++;
            doTabs(tabs);
        }
        else {
            aux = (char*)realloc(aux, (strlen(params->type) + strlen(params->tag)) * sizeof(char));
            sprintf(aux, "%s%s %s", aux, getLlvmType(params->type), genVariable(params)); //esta mal
        }
        
        if(params->sibling)
            sprintf(aux, "%s,", aux);
        params = params->sibling;
    }
    printf("%%%d = call %s @%s(%s)\n", variable, getLlvmType(root->type), removeId(root->child->tag), aux);
    variable++;
    free(aux);
    return variable;
}

int genVarToTemp(node root, char* type, char* newType, int variable, int tabs) {
    printf("%%%d = load %s, %s* %s, align %c\n", variable, type, 
    type, genVariable(root), getLlvmSize(type));
    
    if(checkIfUnary(root)) {
        variable = genMinusConversion(variable, tabs, type);
    }

    if(cmpSize(type, newType) == -1) {
        doTabs(tabs);
        variable++;
        printf("%%%d = sext %s %%%d to %s\n", variable, type, variable - 1, newType);
    }
    else if(cmpSize(type, newType) == 1) {
        doTabs(tabs);
        variable++;
        printf("%%%d = trunc %s %%%d to %s\n", variable, type, variable - 1, newType);
    }
    return variable;
}

int cmpSize(char* size1, char* size2) {
    if(strcmp(size1, size2) == 0) { //same size
        return 0;
    }
    if(strcmp(size1, "i32") == 0 && strcmp(size2, "i32") != 0) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i16") == 0 && (strcmp(size2, "i8") == 0) ) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i8") == 0 && strcmp(size2, "i8") != 0) { //size1 smaller than size2
        return -1; 
    }
    else if(strcmp(size1, "i16") == 0 && strcmp(size2, "i32") == 0) { //size1 smaller than size2
        return -1; 
    }
    return 0;
}

int trasformToAscii(char* string) {
    int transform = 0;

    if(*string == '\\' && *(string + 1) == 'n') {
        transform = 10;
    }
    else if(*string == '\\' && *(string + 1) == 't') {
        transform = 9;
    }
    else if(*string == '\\' && *(string + 1) == '"') {
        transform = 34;
    }
    else if(*string == '\\' && *(string + 1) == '\'') {
        transform = 39;
    }
    else if(*string == '\\' && *(string + 1) == '\\') {
        transform = 92;
    }
    else if(*string == '\\') {
        int aux;
        int aux1 = 0;
        printf("\n%s\n", string);
        printf("\n%lu\n", strlen(string));
        aux = *(string + 3) - 48;
        printf("\n-->%d\n", aux);
        aux1 += aux;

        aux = *(string + 2);
        aux1 += aux * 10;

        aux = *(string + 1);
        aux1 += aux * 100;

        printf("\n%d\n",aux1);
    }
    else {
        transform = *string;
    }


    return transform;
}