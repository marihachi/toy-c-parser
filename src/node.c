#include "node.h"

node_t *new_node(syntax_kind_t kind) {
  node_t *node;
  node = malloc(sizeof(node_t));
  if (node == NULL) {
    printf("FAIL: malloc in new_node()\n");
    exit(EXIT_FAILURE);
  }
  node->kind = kind;
  node->children = NULL;
  node->next = NULL;
  return node;
}

void list_add(node_t **list, node_t *item) {
  if (list == NULL) { printf("FAIL: null argument in list_add()\n"); exit(EXIT_FAILURE); }
  if (item == NULL) { printf("FAIL: null argument in list_add()\n"); exit(EXIT_FAILURE); }

  if ((*list) == NULL) {
    *list = item;
    item->next = NULL;
  } else {
    while ((*list)->next != NULL) { list_move_next(list); }
    (*list)->next = item;
    item->next = NULL;
  }
}

void list_insert(node_t **list, int index, node_t *item) {
  if (list == NULL) { printf("FAIL: null argument in list_insert()\n"); exit(EXIT_FAILURE); }
  if (item == NULL) { printf("FAIL: null argument in list_insert()\n"); exit(EXIT_FAILURE); }

  node_t *ptr = *list;
  if (index == 0) {
    if ((*list) != NULL) {
      item->next = (*list)->next;
    }
    *list = item;
  } else {
    while (ptr != NULL && index > 1) {
      index--;
      list_move_next(&ptr);
    }
    if (index > 1 || ptr == NULL) {
      printf("FAIL: index out of range in list_insert()\n");
      exit(EXIT_FAILURE);
    }
    item->next = ptr->next;
    ptr->next = item;
  }
}

node_t *list_at(node_t **list, int index) {
  if (list == NULL) { printf("FAIL: null argument in list_at()\n"); exit(EXIT_FAILURE); }

  node_t *ptr = *list;
  while (ptr != NULL && index > 0) {
    index--;
    list_move_next(&ptr);
  }
  if (index != 0 || ptr == NULL) {
    printf("FAIL: index out of range in list_at()\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

int list_count(node_t **list) {
  if (list == NULL) { printf("FAIL: null argument in list_count()\n"); exit(EXIT_FAILURE); }

  node_t *ptr = *list;
  int i = 0;
  while (ptr != NULL) {
    i++;
    list_move_next(&ptr);
  }
  return i;
}

void list_move_next(node_t **list) {
  if (list == NULL) { printf("FAIL: null argument in list_move_next()\n"); exit(EXIT_FAILURE); }

  if ((*list) != NULL) {
    *list = (*list)->next;
  }
}
