# include <stdlib.h>

#include "node.h"

struct Node* create_node(int data){
	struct Node* node = malloc(sizeof(struct Node));
	node->next = NULL;
	node->data = data;
	return node;
}
