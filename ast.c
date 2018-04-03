#include "structs.h"

node createNode(char* tagValue) {
    node no = malloc(sizeof(tree_node));
    strcpy(no->tag, tagValue);
    no->child = NULL;
    no->sibling = NULL;
    return no;
}
void addChild(node father, node son) {
    father->child = son;
}

void addSibling(node sibling1, node sibling2) {
    sibling1->sibling = sibling2;
}

void printTree(node root) {
    if(root == NULL) {
        return;
    }
    else {
        printf("%s\n", root->tag);
    }
    printTree(root->child);
    printTree(root->sibling);
    free(root);
}

void freeTree(node root) {
    if(root == NULL) {
        return;
    }
    freeTree(root->child);
    freeTree(root->sibling);
    free(root);
}