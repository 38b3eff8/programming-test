#ifndef NODE_H_
#define NODE_H_

struct Node {
	int data;
	struct Node* next;
};

struct Node* create_node(int data);

#endif
