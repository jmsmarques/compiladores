#include "structs.h"

int label;

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
        if(strcmp(root->child->tag, "Double") != 0) {
            printf("@%s = common global %s 0, align %c\n", removeId(root->child->sibling->tag),
            getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
        }
        else {
            printf("@%s = common global %s 0.0, align %c\n", removeId(root->child->sibling->tag),
            getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
        }
    }
    else { //declaration has definition
        //sprintf(code, "@%s = global %s %s, align %c", removeId(root->child->sibling->tag), type, genDecAtribution(root->child->sibling->sibling), getLlvmSize(root->child->tag));
        if(checkIfLiteral(root->child->sibling->sibling)) {
            printf("@%s = global %s %s, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), 
            genVariable(root->child->sibling->sibling, getLlvmType(root->child->tag)), getLlvmSize(root->child->tag));
        }
        else {

        }
    }
    /*doTabs(tabs);
        printf("%%%s = alloca %s, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
        if(root->child->sibling->sibling)
            variable = genStore(root->child->sibling, getLlvmType(root->child->tag), variable, tabs, paramList);
    printf("%s\n", code);
    free(code);*/
}

int genFuncBody(node root, paramsInfo paramList, int tabs, int variable, char* funcType, int flag) {
    if(!root) 
        return variable;
    //int variable1 = variable;
    //int variable2 = variable1;
    int aux = 1;
    if(strcmp(root->tag, "Declaration") == 0) {
        doTabs(tabs);
        printf("%%%s = alloca %s, align %c\n", removeId(root->child->sibling->tag), getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
        if(root->child->sibling->sibling)
            variable = genStore(root->child->sibling, getLlvmType(root->child->tag), variable, tabs, paramList);
    }
    else if(strcmp(root->tag, "Call") == 0) {
        //printf("--->%d\n", variable);
        variable = genCall(root, variable, tabs, paramList);
        //printf("---->%d\n", variable);         
    }
    else if(strcmp(root->tag, "Store") == 0) {
        //printf("---->%d\n", variable);
        variable = genStore(root->child, getLlvmType(root->type), variable, tabs, paramList);
        //printf("----->%d\n", variable);
    }
    else if(strcmp(root->tag, "If") == 0) {
        variable = generateIf(root, paramList, variable, tabs, funcType);
        if(variable < 0) {
            return variable;
        }
    }
    else if(strcmp(root->tag, "While") == 0) {
        variable = generateWhile(root, paramList, variable, tabs, funcType);
        if(variable < 0) {
            return variable;
        }
    }
    else if(strcmp(root->tag, "Return") == 0) {
        if(strcmp(root->child->tag, "Null") != 0) {
            if(checkIfLiteral(root->child)) {
                doTabs(tabs);
                printf("ret %s %s\n", funcType, genVariable(root->child, funcType));
            }
            else {
                variable = genExpr(root->child, variable, tabs, getLlvmType(funcType), paramList);
                doTabs(tabs);
                printf("ret %s %%%d\n", funcType, variable);
                variable++;
            }
        }
        else {
            doTabs(tabs);
            printf("ret void\n");
        }
        
        return variable * -1;
    }
    else {
        variable = genFuncBody(root->child, paramList, tabs, variable, funcType, 1);
        aux = 0;
    }
    if(flag) {
        //printf("||->%d\n", variable);
        variable = genFuncBody(root->sibling, paramList, tabs, variable, funcType, 1);
    }
    return variable;
    /*else if(aux) {
        return variable;
    }
    if(variable1 < 0) {
        return variable1;
    }
    else if(variable2 < 0) {
        return variable2;
    }
    else if(variable1 > variable2) {
        printf("return1-->%d\n", variable);
        return variable1;
    }
    else {
        printf("return2-->%d\n", variable2);
        return variable2;
    }*/
}

void genFuncDef(node root) {
    int variable = 1;
    paramsInfo params = NULL;
    genFuncDec(root, "define");
    printf(" {\n");
    label = 1;
    //returnFlag = 0;
    if(strcmp(root->child->sibling->sibling->child->child->tag, "Void") != 0) {
        params = (paramsInfo)malloc(sizeof(params_node));
        variable = genParams(params, root->child->sibling->sibling->child, variable, 1);
        //genParams(params, root->child->sibling->sibling->child, variable, 1);
    }
    variable = genFuncBody(root->child->sibling->sibling->sibling->child, params, 1, variable, getLlvmType(root->child->tag), 1);
    
    if(variable > 0) {
        if(strcmp(root->child->tag, "Void") == 0) {
            doTabs(1);
            printf("ret void\n");
        }
        else if(strcmp(root->child->tag, "Double") == 0) {
            doTabs(1);
            printf("ret double 0.0\n");
        }
        else {
            doTabs(1);
            printf("ret %s 0\n", getLlvmType(root->child->tag));
        }
    }

    

    printf("}\n\n");
    /*while(params) {
        printf("->%s\n->%%%d\n->%s\n", params->id, params->var, params->type);
        params = params->next;
    }*/
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

    if(root->child->sibling) {
        if(strcmp(getLlvmType(root->child->tag), "i8") == 0 || strcmp(getLlvmType(root->child->tag), "i16") == 0) {
            printf("%s signext %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
        }
        else {
            printf("%s %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
        }
    }
    else {
        printf("%s", getLlvmType(root->child->tag));
    }
    root = root->sibling;
    while(root) {
        if(root->child->sibling) {
            if(strcmp(getLlvmType(root->child->tag), "i8") == 0 || strcmp(getLlvmType(root->child->tag), "i16") == 0) {
                printf(", %s signext %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
            }
            else {
                printf(", %s %%%s", getLlvmType(root->child->tag), removeId(root->child->sibling->tag));
            }
        }
        else {
            printf(", %s", getLlvmType(root->child->tag));
        }
        root = root->sibling;
    }
    return;
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
    else {
        return string;
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

char* extractLiteral(char* string, char* type) {
    char* aux = NULL;
    int len = 0;

    if(!string)
        return NULL;

    if(strncmp(string, "Real", 4) == 0) {
        len = 8;
        aux = reduceString(string, len, len + 1);
        if(*aux == '.') {
            sprintf(aux, "0%s", strdup(aux));
        }
        else {
            aux = analiseReal(aux);
        }
    }
    else if(strncmp(string, "Int", 3) == 0) {
        len = 7;
        aux = reduceString(string, len, len + 1);
        if((*aux == '0' && strlen(aux) > 1)) {
            //printf("octal\n");
            aux = generateOctal(aux);
        }
        if(strcmp(type, "double") == 0) {
            sprintf(aux, "%s.0", aux);
        }
    }
    else if(strncmp(string, "Chr", 3) == 0) {
        len = 8;
        aux = reduceString(string, len, len + 2);
        //transforms char to ascii
        
        int transform = trasformToAscii(aux);
        sprintf(aux, "%d", transform);
        if(strcmp(type, "double") == 0) {
            sprintf(aux, "%s.0", aux);
        }
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

char* genVariable(node root, char* type) {
    char* aux = NULL;

    if(strcmp(root->tag, "Minus") == 0) {
        if(checkIfId(root->child->tag)) {
            return genVariable(root->child, type);
        }
        else {
            aux = (char*)malloc((strlen(root->child->tag)) * sizeof(char));
            aux = genVariable(root->child, type);
            if(strcmp(aux, "0") != 0)
                sprintf(aux, "-%s", strdup(aux));
        }
    }
    else if(strcmp(root->tag, "Plus") == 0) {
        return genVariable(root->child, type);
    }
    else if(strcmp(root->tag, "Not") == 0) {
        if(checkIfId(root->child->tag)) {
            return genVariable(root->child, type);
        }
        else {
            //aux = (char*)malloc((strlen(root->child->tag)) * sizeof(char));
            aux = genVariable(root->child, type);
            if(strcmp(aux, "0") == 0) {
                if(strcmp(type, "double") == 0) {
                    sprintf(aux, "1.0");
                }
                else {
                    sprintf(aux, "1");
                }                
            }
            else {
                if(strcmp(type, "double") == 0) {
                    sprintf(aux, "0.0");
                }
                else {
                    sprintf(aux, "0");
                } 
            }
        }
    }
    else if(checkIfId(root->tag)) {
        aux = (char*)malloc((strlen(root->tag) + 8) * sizeof(char));
        sprintf(aux, "%c%s", root->scope, removeId(root->tag));
    }
    else {
        aux = extractLiteral(root->tag, type);
    }

    return aux;
}

void doTabs(int nr) {
    for(int n = 0; n < nr; n++)
        printf("\t");
}

int genStore(node root, char* type, int variable, int tabs, paramsInfo paramList) {
    if(!checkIfLiteral(root->sibling)) {
        /*printf("%%%d = load %s, %s* %s, align %c\n", variable, type, 
        type, genVariable(root->sibling), getLlvmSize(type));

        if(checkIfUnary(root->sibling)) {
            variable = genMinusConversion(variable, tabs, type);
        }*/
        
        variable = genExpr(root->sibling, variable, tabs, type, paramList);
        
        int arg = checkIfArgument(paramList, genVariable(root, root->type));
        if(arg) {
            doTabs(tabs);
            printf("store %s %%%d, %s* %%%d, align %c\n", type, 
            variable, type, arg, getLlvmSize(type));
            variable++;
        }
        else {
            doTabs(tabs);
            printf("store %s %%%d, %s* %s, align %c\n", type, 
            variable, type, genVariable(root, type), getLlvmSize(type));
            variable++;
        }
    }
    else {
        //printf("%s\n", genVariable(root, type));
        int arg = checkIfArgument(paramList, genVariable(root, root->type));
        if(arg) {
            doTabs(tabs);
            printf("store %s %s, %s* %%%d, align %c\n", type, 
            genVariable(root->sibling, type), type, arg, getLlvmSize(type));
        }
        else {
            doTabs(tabs);
            printf("store %s %s, %s* %s, align %c\n", type, genVariable(root->sibling, type), 
            type, genVariable(root, type), getLlvmSize(type));
        }
    }
    //printf("-->%d\n", variable);
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

int genNotConversion(int variable, int tabs, char* type) {
    variable++;
    if(strcmp(type, "double") == 0) {
        doTabs(tabs);
        printf("%%%d = fcmp une double %%%d, 0.0\n", variable, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = xor i1 %%%d, true\n", variable, variable - 1);
    }
    else {
        doTabs(tabs);
        printf("%%%d = icmp ne %s %%%d, 0\n", variable, type, variable - 1);
        variable++;
        doTabs(tabs);
        printf("%%%d = xor i1 %%%d, true\n", variable, variable - 1);
    }
    return variable;
}

int checkIfUnary(node root) {
    if(strcmp(root->tag, "Minus") == 0 || strcmp(root->tag, "Plus") == 0 || strcmp(root->tag, "Not") == 0) {
        if(checkIfId(root->child->tag)) {
            return 1;
        }
    }
    return 0;
}

int genCall(node root, int variable, int tabs, paramsInfo paramList) {
    node params = root->child->sibling;
    char* saveptr;
    char* token;
    char* aux = strdup("");
    char* paramsType = extractParamType(root->child->type);
    //printf("tag = %s\n", root->tag);
    
    //printf("begin-->%s = %s\n", root->child->type, root->child->tag);
    //printf("before-->%s\n", paramsType);
    token = strtok_r(paramsType, ",", &saveptr);
    //printf("after-->%s\n", paramsType);
    while(params && token) {
        //printf("type->%s->%s\n", paramsType, root->child->tag);
        if(checkIfLiteral(params)){
            aux = (char*)realloc(aux, (10 + strlen(aux) + strlen(params->type) + strlen(params->tag)) * sizeof(char));
            if(strcmp(getLlvmType(token), "i8") == 0 || strcmp(getLlvmType(token), "i16") == 0 ) {
                sprintf(aux, "%s%s signext %s", aux, getLlvmType(token), genVariable(params, getLlvmType(token))); //esta mal
            }
            else {
                sprintf(aux, "%s%s %s", aux, getLlvmType(token), genVariable(params, getLlvmType(token))); //esta mal
            }
        }
        else {
            variable = genExpr(params, variable, tabs, getLlvmType(token), paramList);
            aux = (char*)realloc(aux, (10 + strlen(aux) + strlen(params->type) + strlen(params->tag) + 5) * sizeof(char));
            if(strcmp(getLlvmType(token), "i8") == 0 || strcmp(getLlvmType(token), "i16") == 0 ) {
                sprintf(aux, "%s%s signext %%%d", aux, getLlvmType(token), variable); //esta mal
            }
            else {
                sprintf(aux, "%s%s %%%d", aux, getLlvmType(token), variable); //esta mal
            }
            variable++;
        }
        //printf("token1--->%s\n", token);
        //printf("%s\n", params->tag);
        //printf("1=%s\n", paramsType);
        //printf("type->%s->%s\n", paramsType, root->child->tag);
        if(params->sibling)
            sprintf(aux, "%s,", aux);
        params = params->sibling;
        token = strtok_r(NULL, ",", &saveptr);
        //printf("token2--->%s\n", token);
        //printf("2=%s\n", paramsType);
        //printf("--->%s\n", token);
    }
    
    doTabs(tabs);
    if(strcmp(root->type, "void") != 0) {
        printf("%%%d = call %s @%s(%s)\n", variable, getLlvmType(root->type), removeId(root->child->tag), aux);
        variable++;
    }
    else {
        printf("call %s @%s(%s)\n", getLlvmType(root->type), removeId(root->child->tag), aux);
    }
    free(aux);
    //free(token);
    return variable;
}

int genVarToTemp(node root, char* type, char* newType, int variable, int tabs, paramsInfo paramList) {
    if(strcmp(root->tag, "Not") == 0) {
        type = getLlvmType(root->child->type);
    }
    int arg = checkIfArgument(paramList, genVariable(root, type));
    if(arg) {
        doTabs(tabs);
        printf("%%%d = load %s, %s* %%%d, align %c\n", variable, type, type, arg, getLlvmSize(type));
    }
    else {
        doTabs(tabs);
        printf("%%%d = load %s, %s* %s, align %c\n", variable, type, 
        type, genVariable(root, type), getLlvmSize(type));
    }
    //getParamVar(params, paramId); //aqui
    if(checkIfUnary(root)) {
        if(strcmp(root->tag, "Minus") == 0) {
            variable = genMinusConversion(variable, tabs, type);
        }
        else if(strcmp(root->tag, "Not") == 0) {
            variable = genNotConversion(variable, tabs, type);
            type = strdup("i1");
        }
    }
    variable = convertSize(type, newType, variable, tabs);

    return variable;
}

int convertSize(char* type, char* newType, int variable, int tabs) {
    if(strcmp(newType, "double") == 0 && strcmp(type, "double") != 0) {
        doTabs(tabs);
        variable++;
        printf("%%%d = sitofp %s %%%d to %s\n", variable, type, variable - 1, newType);
    }
    else if(cmpSize(type, newType) == -1) {
        doTabs(tabs);
        variable++;
        if(strcmp(type, "i1") == 0) {
            printf("%%%d = zext %s %%%d to %s\n", variable, type, variable - 1, newType);
        }
        else {
            printf("%%%d = sext %s %%%d to %s\n", variable, type, variable - 1, newType);
        }
    }
    else if(cmpSize(type, newType) == 1) {
        doTabs(tabs);
        variable++;
        printf("%%%d = trunc %s %%%d to %s\n", variable, type, variable - 1, newType);
    }

    return variable;
}

int genExpr(node root, int variable, int tabs, char* type, paramsInfo paramList) {
    char* aux1 = NULL;
    char* aux2 = NULL;
    char* operation = NULL;
    if((strcmp(root->tag, "Add") == 0) || (strcmp(root->tag, "Sub") == 0) || (strcmp(root->tag, "Mul") == 0)
    || (strcmp(root->tag, "Div") == 0) || (strcmp(root->tag, "Mod") == 0) || (strcmp(root->tag, "BitWiseXor") == 0)
    || (strcmp(root->tag, "BitWiseOr") == 0) || (strcmp(root->tag, "BitWiseAnd") == 0)) {
        operation = genOperationCommand(root->tag, root->type);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, root->type);
        }
        else {
            aux1 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(root->type), paramList);
            //variable = convertSize(root->child->type, type, variable, tabs);
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, root->type);
        }
        else {
            aux2 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(root->type), paramList);
            //variable = convertSize(root->child->sibling->type, type, variable, tabs);
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        printf("%%%d = %s %s %s, %s\n", variable, operation, getLlvmType(root->type), aux1, aux2);
        variable = convertSize(getLlvmType(root->type), type, variable, tabs);
        free(aux1);
        free(aux2);
    }
    else if(checkIfLogicalOperation(root->tag)) {
        char* realType = checkType(root->child->type, root->child->sibling->type);
        operation = genOperationCommand(root->tag, realType);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, realType);
        }
        else {
            aux1 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(realType), paramList);
            //variable = convertSize(root->child->type, type, variable, tabs);
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        
        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, realType);
            //printf("%s\n", aux2);
        }
        else {
            aux2 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(realType), paramList);
            //variable = convertSize(root->child->sibling->type, type, variable, tabs);
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        
        doTabs(tabs);
        printf("%%%d = %s %s %s, %s\n", variable, operation, getLlvmType(realType), aux1, aux2);
        variable = convertSize("i1", type, variable, tabs);
        free(aux1);
        free(aux2);
    }
    else if(strcmp(root->tag, "And") == 0) {
        //char* realType = checkType(root->child->type, root->child->sibling->type);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, root->child->type);
        }
        else {
            aux1 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(root->child->type), paramList);
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux1);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->type), aux1);
        }
        label++;
        doTabs(tabs);
        printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label - 1, label);
        variable++;
        doTabs(tabs);
        printf("label%d:\n", label - 1);

        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, root->child->sibling->type);
        }
        else {
            aux2 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(root->child->sibling->type), paramList);
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->sibling->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux2);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->sibling->type), aux2);
        }
        variable++;
        doTabs(tabs);
        printf("br label %%label%d\n\n", label);
        
        doTabs(tabs);
        printf("label%d:\n", label); //true condition
        doTabs(tabs);
        int help = label - 2;
        if(help == 0) {
            printf("%%%d = phi i1 [ false, %%0 ], [ %%%d, %%label%d ]\n", variable, variable - 1, label - 1);
        }
        else {
            printf("%%%d = phi i1 [ false, %%label%d ], [ %%%d, %%label%d ]\n", variable, help, variable - 1, label - 1);
        }
        
        variable = convertSize("i1", type, variable, tabs);
        
        label++;
    
    }
    else if(strcmp(root->tag, "Or") == 0) {
        //char* realType = checkType(root->child->type, root->child->sibling->type);
        if(checkIfLiteral(root->child)) {
            aux1 = genVariable(root->child, root->child->type);
        }
        else {
            aux1 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child, variable, tabs, getLlvmType(root->child->type), paramList);
            sprintf(aux1, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux1);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->type), aux1);
        }
        label++;
        doTabs(tabs);
        printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label, label - 1);
        variable++;
        doTabs(tabs);
        printf("label%d:\n", label - 1);
        if(checkIfLiteral(root->child->sibling)) {
            aux2 = genVariable(root->child->sibling, root->child->sibling->type);
        }
        else {
            aux2 = (char*)malloc(10 * sizeof(char));
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(root->child->sibling->type), paramList);
            sprintf(aux2, "%%%d", variable);
            variable++;
        }
        doTabs(tabs);
        if(strcmp(root->child->sibling->type, "double") == 0) {
            printf("%%%d = fcmp une double %s, 0.0\n", variable, aux2);
        }
        else {
            printf("%%%d = icmp ne %s %s, 0\n", variable, getLlvmType(root->child->sibling->type), aux2);
        }
        variable++;
        doTabs(tabs);
        printf("br label %%label%d\n\n", label);
        
        doTabs(tabs);
        printf("label%d:\n", label); //true condition
        doTabs(tabs);
        int help = label - 2;
        if(help == 0) {
            printf("%%%d = phi i1 [ true, %%0 ], [ %%%d, %%label%d ]\n", variable, variable - 1, label - 1);
        }
        else {
            printf("%%%d = phi i1 [ true, %%label%d ], [ %%%d, %%label%d ]\n", variable, help, variable - 1, label - 1);
        }
        
        variable = convertSize("i1", type, variable, tabs);
        
        label++;
    }
    else if(strcmp(root->tag, "Store") == 0) {
        //erro aqui
        variable = genStore(root->child, getLlvmType(root->type), variable, tabs, paramList);
        int arg = checkIfArgument(paramList, genVariable(root->child, root->type));
        if(arg) {
            doTabs(tabs);
            printf("%%%d = load %s, %s* %%%d, align %c\n", variable, getLlvmType(root->child->type), getLlvmType(root->child->type),
            arg, getLlvmSize(getLlvmType(root->child->type)));
        }
        else {
            doTabs(tabs);
            printf("%%%d = load %s, %s* %s, align %c\n", variable, getLlvmType(root->child->type), getLlvmType(root->child->type),
            genVariable(root->child, getLlvmType(root->child->type)), getLlvmSize(getLlvmType(root->child->type)));
        }
        variable = convertSize(getLlvmType(root->type), type, variable, tabs);
    }
    else if(strcmp(root->tag, "Call") == 0) {
        variable = genCall(root, variable, tabs, paramList);
        variable--;
        variable = convertSize(getLlvmType(root->type), type, variable, tabs);
    }
    else if(strcmp(root->tag, "Comma") == 0) {
        if(!checkIfLiteral(root->child)) { 
            variable = genExpr(root->child, variable, tabs, getLlvmType(root->child->type), paramList);
            variable++;
        }
        if(checkIfLiteral(root->child->sibling)) {
            aux1 = genVariable(root->child->sibling, root->child->sibling->type);
            doTabs(tabs);
            printf("%%jorge%d = alloca %s\n", variable, getLlvmType(root->child->sibling->type));
            doTabs(tabs);
            printf("store %s %s, %s* %%jorge%d\n", getLlvmType(root->child->sibling->type), aux1, 
            getLlvmType(root->child->sibling->type), variable);
            doTabs(tabs);
            printf("%%%d = load %s, %s* %%jorge%d\n", variable, getLlvmType(root->child->sibling->type),
            getLlvmType(root->child->sibling->type), variable);
            free(aux1);
            variable = convertSize(getLlvmType(root->type), type, variable, tabs);
        }
        else 
            variable = genExpr(root->child->sibling, variable, tabs, getLlvmType(root->type), paramList);
    }
    else {
        if(checkIfId(root->tag) || checkIfUnary(root)) {
            variable = genVarToTemp(root, getLlvmType(root->type), type, variable, tabs, paramList);
        }
        else if(strcmp(root->tag, "Minus") == 0) {
            variable = genExpr(root->child, variable, tabs, type, paramList);
            variable = genMinusConversion(variable, tabs, type);
            variable = convertSize(getLlvmType(root->type), type, variable, tabs);
        }
        else if(strcmp(root->tag, "Not") == 0) {
            variable = genExpr(root->child, variable, tabs, type, paramList);
            variable = genNotConversion(variable, tabs, type);
            variable = convertSize("i1", type, variable, tabs);
        }
        else if(strcmp(root->tag, "Plus") == 0) {
            variable = genExpr(root->child, variable, tabs, type, paramList);
            variable = convertSize(getLlvmType(root->type), type, variable, tabs);
        }
    }

    return variable;
}

int generateIf(node root, paramsInfo paramList, int variable, int tabs, char* funcType) {
    /*if(!(checkIfLogicalOperation(root->child->tag) || strcmp(root->child->tag, "And") == 0 || strcmp(root->child->tag, "Or") == 0)) {
        if(strcmp(root->child->type, "double") == 0) {
            variable = genExpr(root->child, variable, tabs, "double");
            variable++;
            doTabs(tabs);
            printf("%%%d = fcmp une double %%%d, 0.0\n", variable, variable - 1);
        }
        else {
            variable = genExpr(root->child, variable, tabs, "i32");
            variable++;
            doTabs(tabs);
            printf("%%%d = icmp ne i32 %%%d, 0\n", variable, variable - 1);
        }
    }*/
    int auxLabel;
    int auxLabel1;
    if(checkIfLiteral(root->child)) {
        char* aux = NULL;
        aux = genVariable(root->child, root->child->type);
        if(strcmp(aux, "0") != 0) {
            variable = genFuncBody(root->child->sibling, paramList, tabs, variable, funcType, 0);
        }
        else {
            if(root->child->sibling->sibling)
                variable = genFuncBody(root->child->sibling->sibling, paramList, tabs, variable, funcType, 0);
        }
        free(aux);
        return variable;
    }
    else {
        variable = genExpr(root->child, variable, tabs, "i32", paramList);
        doTabs(tabs);
        variable++;
        printf("%%%d = icmp ne i32 %%%d, 0\n", variable, variable - 1);
    }
    
    doTabs(tabs);
    printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label, label + 1);
    variable++;
    label += 2;
    auxLabel = label - 1;
    doTabs(tabs);
    printf("label%d:\n", label - 2);
    variable = genFuncBody(root->child->sibling, paramList, tabs, variable, funcType, 0);
    if(strcmp(root->child->sibling->sibling->tag, "Null") != 0) { //else
        auxLabel1 = label;
        label++; 
        if(variable < 0) {
            variable *= -1;
        }
        else {
            doTabs(tabs);
            printf("br label %%label%d\n\n", auxLabel1);
        }
        doTabs(tabs);
        printf("label%d:\n", auxLabel);
        //label++;
        variable = genFuncBody(root->child->sibling->sibling, paramList, tabs, variable, funcType, 0);
         
        if(variable < 0) {
            variable *= -1;
        }
        else {
            doTabs(tabs);
            printf("br label %%label%d\n\n", auxLabel1);
        }
        
        doTabs(tabs);
        printf("label%d:\n", auxLabel1); //continue
    }
    else { //no else   
        if(variable < 0) {
            variable *= -1;
        }
        else {
            doTabs(tabs);
            printf("br label %%label%d\n\n", auxLabel);
        }
        doTabs(tabs);
        printf("label%d:\n", auxLabel);
    }
    //label++;
    return variable;
}

int generateWhile(node root, paramsInfo paramList, int variable, int tabs, char* funcType) {
    int auxLabel;
    int auxLabel1;
    doTabs(tabs);
    printf("br label %%label%d\n\n", label);
    doTabs(tabs);
    printf("label%d:\n", label);
    auxLabel = label;
    label++;
    //comparacao aqui
    /*if(!(checkIfLogicalOperation(root->child->tag) || strcmp(root->child->tag, "And") == 0 || strcmp(root->child->tag, "Or") == 0)) {
        if(strcmp(root->child->type, "double") == 0) {
            variable = genExpr(root->child, variable, tabs, "double");
            variable++;
            doTabs(tabs);
            printf("%%%d = fcmp une double %%%d, 0\n", variable, variable - 1);
        }
        else {
            variable = genExpr(root->child, variable, tabs, "i32");
            variable++;
            doTabs(tabs);
            printf("%%%d = icmp ne i32 %%%d, 0\n", variable, variable - 1);
        }
    }*/
    
    if(checkIfLiteral(root->child)) {
        char* aux = NULL;
        aux = genVariable(root->child, root->child->type);
        if(strcmp(aux, "0") != 0) {
            variable = genFuncBody(root->child->sibling, paramList, tabs, variable, funcType, 0);
            if(variable >= 0) {
                doTabs(tabs);
                printf("br label %%label%d\n\n", auxLabel);
                
            }
            else {
                variable *= -1;
            }
        }
        free(aux);
        return variable;
    }
    
    variable = genExpr(root->child, variable, tabs, "i32", paramList);
    doTabs(tabs);
    variable++;
    printf("%%%d = icmp ne i32 %%%d, 0\n", variable, variable - 1);
    
    doTabs(tabs);
    printf("br i1 %%%d, label %%label%d, label %%label%d\n\n", variable, label, label + 1);
    variable++;
    doTabs(tabs);
    printf("label%d:\n", label);
    label += 2;
    auxLabel1 = label - 1;
    variable = genFuncBody(root->child->sibling, paramList, tabs, variable, funcType, 0);
    if(variable < 0) {
        variable *= -1;
    }
    else {
        doTabs(tabs);
        printf("br label %%label%d\n\n", auxLabel);
    }
    doTabs(tabs);
    printf("label%d:\n", auxLabel1); //continue
    //label++;
    return variable;
}

char* genOperationCommand(char* op, char* type) {
    char* result = NULL;
    if(strcmp(op, "Add") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fadd");
        }
        else {
            result = strdup("add");
        }
    }
    else if(strcmp(op, "Sub") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fsub");
        }
        else {
            result = strdup("sub");
        }
    }
    else if(strcmp(op, "Mul") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fmul");
        }
        else {
            result = strdup("mul");
        }
    }
    else if(strcmp(op, "Div") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fdiv");
        }
        else {
            result = strdup("sdiv");
        }
    }
    else if(strcmp(op, "Mod") == 0) {
        result = strdup("srem");
    }
    else if(strcmp(op, "BitWiseAnd") == 0) {
        result = strdup("and");
    }
    else if(strcmp(op, "BitWiseOr") == 0) {
        result = strdup("or");
    }
    else if(strcmp(op, "BitWiseXor") == 0) {
        result = strdup("xor");
    }
    else if(strcmp(op, "Eq") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp oeq");
        }
        else {
            result = strdup("icmp eq");
        }
    }
    else if(strcmp(op, "Ne") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp one");
        }
        else {
            result = strdup("icmp ne");
        }
    }
    else if(strcmp(op, "Le") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp ole");
        }
        else {
            result = strdup("icmp sle");
        }
    }
    else if(strcmp(op, "Ge") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp oge");
        }
        else {
            result = strdup("icmp sge");
        }
    }
    else if(strcmp(op, "Lt") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp olt");
        }
        else {
            result = strdup("icmp slt");
        }
    }
    else if(strcmp(op, "Gt") == 0) {
        if(strcmp(type, "double") == 0) {
            result = strdup("fcmp ogt");
        }
        else {
            result = strdup("icmp sgt");
        }
    }
    return result;
}

int genParams(paramsInfo params, node root, int variable, int tabs) {
    char* aux = (char*)malloc(20*sizeof(char));
    while(root) {
        doTabs(tabs);
        printf("%%%d = alloca %s, align %c\n", variable, getLlvmType(root->child->tag), getLlvmSize(root->child->tag));
        doTabs(tabs);
        printf("store %s %%%s, %s* %%%d, align %c\n", getLlvmType(root->child->tag), removeId(root->child->sibling->tag), 
        getLlvmType(root->child->tag), variable, getLlvmSize(root->child->tag));
        params->next = NULL;
        //printf("---->%s\n", removeId(root->child->sibling->tag));
        sprintf(aux, "%%%s", removeId(root->child->sibling->tag));
        params->id = strdup(aux);
        params->type = getLlvmType(root->child->tag);
        params->var = variable;
        variable++;
        if(root->sibling) {
            params->next = (paramsInfo)malloc(sizeof(params_node));
            params = params->next;
        }
        root = root->sibling;
    }
    
    return variable;
}

int checkIfArgument(paramsInfo params, char* id) {
    while(params) {
        //printf("-->%s-->%s\n", id, params->id);
        if(strstr(params->id, id)) {
            //printf("entrei\n");
            return params->var;
        }
        params = params->next;
    }
    return 0;
}

//aux functions

int cmpSize(char* size1, char* size2) {
    if(strcmp(size1, size2) == 0) { //same size
        return 0;
    }
    if(strcmp(size1, "i32") == 0 && strcmp(size2, "i32") != 0) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i16") == 0 && (strcmp(size2, "i8") == 0 || strcmp(size2, "i1") == 0) ) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i8") == 0 && (strcmp(size2, "i1") == 0) ) { //size1 bigger than size2
        return 1; 
    }
    else if(strcmp(size1, "i1") == 0 && strcmp(size2, "i1") != 0) { //size1 smaller than size2
        return -1; 
    }
    else if(strcmp(size1, "i8") == 0 && (strcmp(size2, "i8") != 0 || strcmp(size2, "i1") != 0)) { //size1 smaller than size2
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
        int size = strlen(string) - 1;
        int el = 0;

        for(; size > 0; size--) {
            aux = *(string + size) - 48;
            aux1 += aux * powAux(10, el);
            el++;
        }
        el = 0;
        while(aux1 != 0) {
            transform += (aux1 % 10)* powAux(8, el);
            el++;
            aux1 /= 10;
        }
    }
    else {
        transform = *string;
    }

    return transform;
}

int powAux(int nr, int el) {
    int result = nr;

    if(el == 0) {
        result = 1;
    }
    else {
        for(int n = 1; n < el; n++) {
            result *= nr;
        }
    }

    return result;
}

int checkIfLiteral(node root) {
    if(strncmp(root->tag, "Real", 4) == 0 || strncmp(root->tag, "Int", 3) == 0 || strncmp(root->tag, "Chr", 3) == 0) {
        return 1;
    }
    else if(strcmp(root->tag, "Minus") == 0 || strcmp(root->tag, "Plus") == 0 || strcmp(root->tag, "Not") == 0) {
        return checkIfLiteral(root->child);
    }
    else {
        return 0;
    }
}

char* checkType(char* type1, char* type2) {
    char* type;
    if(strcmp(type1, "double") == 0 || strcmp(type2, "double") == 0) {
        type = strdup("double");
    }
    else if (strcmp(type1, "int") == 0 || strcmp(type2, "int") == 0) {
        type = strdup("int");
    }
    else if (strcmp(type1, "short") == 0 || strcmp(type2, "short") == 0) {
        type = strdup("short");
    }
    else {
        type = strdup("char");
    }
    return type;
}

char* generateOctal(char* string) {
    int aux;
    int transform = 0;
    int aux1 = 0;
    int size = strlen(string) - 1;
    int el = 0;

    for(; size > 0; size--) {
        aux = *(string + size) - 48;
        aux1 += aux * powAux(10, el);
        el++;
    }
    el = 0;
    while(aux1 != 0) {
        transform += (aux1 % 10)* powAux(8, el);
        el++;
        aux1 /= 10;
    }
    char* ret = (char*)malloc((strlen(string) + 3) * sizeof(char));
    sprintf(ret, "%d", transform);
    return ret;
}

char* extractParamType(char * string) {
    int rem;
    rem = strlen(checkVarType(string));
    char* result = (char*)malloc((strlen(string) + 1) * sizeof(char));
    strncpy(result, string + rem + 1, strlen(string) - 2);
    *(result + strlen(string) - rem - 2) = '\0';
    return result;
}

int getParamVar(paramsInfo params, char* paramId) {
/*    while(params) {
        if(strcmp(params->id, paramId) == 0) {
            return params->var;
        }

        params = params->next;
    }*/
    return 0;
}

char* analiseReal(char* real) {
    char* result = NULL;
    for(int i = 0; i < strlen(real); i++) {
        if(*(real + i) == '.') {
            return real;
        }
        if(*(real + i) == 'e') {
            result = (char*)malloc(50*sizeof(char));
            strncpy(result, real, i);
            strcpy(result + i, ".");
            strcpy(result + i + 1, real + i);
            return result;
        }
    }
    return real;
}