#include <stdlib.h>
#include <stdio.h>
#include "linklist.h"

struct LinkList* create_list(){
	struct Node* node = create_node(0);

	struct LinkList* list = malloc(sizeof(struct LinkList));
	list->head = node;
	list->last = node;

	return list;
}

void show_list(struct LinkList* list){
	if(list->head->next == NULL) {
		printf("list is empty\n");
		return;
	}
	struct Node* index = list->head->next;
	while (index != NULL) {
		printf("%d ", index->data);

		index = index->next;
	}
	printf("\n");
}

void destory_list(struct LinkList* list){
	if(list == NULL) {
		return;
	}
	while (list->head != NULL) {
		struct Node* del = list->head;
		list->head = del->next;
		free(del);
	}
	free(list);
}

int search_list(struct LinkList* list, int data){
	struct Node* index = list->head->next;

	int i = 0;
	while (index != NULL && index->data != data) {
		index = index->next;
		i++;
	}

	if(index == NULL) {
		return -1;
	}else{
		return i;
	}
}

struct Node* get_node_list(struct LinkList* list, int index){

	struct Node* current = list->head;
	for(int i = 0; i <= index; i++) {
		current = current->next;
		if(current == NULL) {
			return NULL;
		}
	}

	return current;
}

void append_list(struct LinkList* list, int data){
	struct Node* node = create_node(data);
	list->last->next = node;
	list->last = node;
}

struct Node* insert_list(struct LinkList* list, int data, int index){
	struct Node* current = list->head;
	for(int i = 0; i < index; i++) {
		current = current->next;
		if(current == NULL) {
			return NULL;
		}
	}


	struct Node* node = create_node(data);
	node->next = current->next;
	current->next = node;
	return node;

}

void push_list(struct LinkList* list, int data){
	struct Node* node = create_node(data);
	printf("%d\n", node->data);
	node->next = list->head->next;
	list->head->next = node;
}
int pop_list(struct LinkList* list){
	struct Node* node = list->head->next;
	list->head->next = node->next;
	int data = node->data;
	free(node);
	return data;
}

void remove_list(struct LinkList* list, int index){
	struct Node* current = list->head;
	for(int i = 0; i < index; i++) {
		current = current->next;
		if(current == NULL) {
			return;
		}
	}
	struct Node* del = current->next;
	current->next = del->next;
	free(del);
}


void remove_data_list(struct LinkList* list, int data){
	struct Node* current = list->head;

	while(current->next != NULL && current->next->data != data) {
		current = current->next;
	}

	struct Node* del = current->next;
	current->next = del->next;
	free(del);
}

void remove_all_data_list(struct LinkList* list, int data){
	struct Node* current = list->head;
	while (current->next != NULL) {
		if(current->next->data == data) {
			struct Node* del = current->next;
			current->next = del->next;
			free(del);
		}else{
			current = current->next;
		}
	}
}
