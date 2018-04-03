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