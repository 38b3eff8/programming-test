#include <stdio.h>
#include <stdlib.h>

typedef struct ST_Node {
    int left_value;
    int right_value;

    struct ST_Node *left;
    struct ST_Node *middle;
    struct ST_Node *right;
} Node;

Node *create_node(int value, int position) {
    Node *node = malloc(sizeof(Node));

    node->left = NULL;
    node->middle = NULL;
    node->right = NULL;

    if (position == 0) {
        node->left_value = value;
    } else {
        node->right_value = value;
    }

//    printf("%d\n", node->left_value);
    return node;
}

Node *create_tree(int init_value) {
    Node *root = create_node(init_value, 0);
    return root;
}

Node *insert_value(Node *root, int value) {
    if (root->left_value == value || root->right_value == value) {
        return root;
    }


    if (root->middle == NULL) {
        if (value < root->left_value) {
            if (root->left == NULL) {
                root->left = create_node(value, 0);
            } else {
                insert_value(root->left, value);
            }
        } else {
            if (root->right == NULL) {
                root->right = create_node(value, 0);
            } else {
                insert_value(root->right, value);
            }
        }
    } else {

    }

    return root;
}

void _print_value(int value, int level) {
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("└──");

    printf("%d\n", value);
}

void _show_tree(Node *root, int level) {
    if (root == NULL) {
        return;
    }

    _print_value(root->left_value, level);
    if (root->middle != NULL) {
        _print_value(root->right_value, level);
    }

    _show_tree(root->left, level + 1);
    if (root->middle != NULL) {
        _show_tree(root->middle, level + 1);
    }
    _show_tree(root->right, level + 1);
}

void show_tree(Node *root) {
    printf(".\n");
    _show_tree(root, 0);
}

int main() {
    Node *root = create_tree(10);
    insert_value(root, 11);
    insert_value(root, 9);
    insert_value(root, 14);
    insert_value(root, 14);
    show_tree(root);
    return 0;
}
