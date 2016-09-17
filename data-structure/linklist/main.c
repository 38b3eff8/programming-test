#include <stdio.h>

#include "linklist/node.h"
#include "linklist/linklist.h"

int main(int argc, char const *argv[]) {
	struct LinkList* list = create_list();

	append_list(list, 1);
	insert_list(list, 2, 0);
	push_list(list, 10);
	show_list(list);

	int data = pop_list(list);
	printf("pop data is %d\n", data);
	show_list(list);

	push_list(list, 10);
	push_list(list, 11);
	push_list(list, 10);
	push_list(list, 11);
	show_list(list);

	remove_list(list, 1);
	show_list(list);

	remove_data_list(list, 10);
	show_list(list);

	remove_all_data_list(list, 11);
	show_list(list);

	struct Node* node = get_node_list(list, 0);
	printf("data is %d\n", node->data);

	int index = search_list(list, 2);
	printf("index is %d\n", index);

	destory_list(list);
	return 0;
}
