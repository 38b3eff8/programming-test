#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <stdbool.h>

#include "node.h"

struct LinkList {
	struct Node* head;
	struct Node* last;
};

struct LinkList* create_list();
void show_list(struct LinkList* list);
void destory_list(struct LinkList* list);

int search_list(struct LinkList* list, int data); // get index
struct Node* get_node_list(struct LinkList* list, int index); // get data;

void append_list(struct LinkList* list, int data);
struct Node*  insert_list(struct LinkList* list, int data, int index);

void remove_list(struct LinkList* list, int index);
void remove_data_list(struct LinkList* list, int data);
void remove_all_data_list(struct LinkList* list, int data);

void push_list(struct LinkList* list, int data);
int pop_list(struct LinkList* list);

#endif
