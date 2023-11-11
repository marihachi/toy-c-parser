#include "node.h"

node_t *new_node(syntax_kind_t kind) {
	node_t *node;

	node = malloc(sizeof(node_t));
	if (node != NULL) {
		node->kind = kind;
	}
	return node;
}

void add_child_node(node_t *self, node_t *child) {
	node_t *node;

	if (self->children == NULL) {
		self->children = child;
	} else {
		node = self->children;
		while (node->next != NULL) {
			node = node->next;
		}
		node->next = child;
	}
}

void insert_child_node(node_t *self, int index, node_t *child) {
	node_t *node;
	// TODO
	abort();
}

node_t *get_child_node_at(node_t *self, int index) {
	node_t *node;

	node = self->children;
	while (node != NULL && index > 0) {
		node = node->next;
		index--;
	}
	return node;
}

int count_child_node(node_t *self) {
	int i;
	node_t *node;

	i = 0;
	node = self->children;
	while (node != NULL) {
		i++;
		node = node->next;
	}
	return i;
}
