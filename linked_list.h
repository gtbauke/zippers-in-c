#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct linked_list_node
{
  void *data;
  struct linked_list_node *next;
} linked_list_node;

typedef struct linked_list
{
  linked_list_node *head;
} linked_list;

typedef struct linked_list_zipper
{
  linked_list *previous;
  linked_list *next;
} linked_list_zipper;

linked_list *linked_list_create(void);

void linked_list_append(linked_list *list, void *data);
void linked_list_prepend(linked_list *list, void *data);

void linked_list_destroy(linked_list *list);
void linked_list_print(linked_list *list);

bool linked_list_is_empty(linked_list *list);

linked_list_zipper *linked_list_zipper_create(linked_list *list);

/*
Advances one position into the list. This works by moving the head of the `next`
list to the head of the `previous` list.
*/
void linked_list_zipper_move_right(linked_list_zipper *zipper);

/*
Moves one position back into the list. This works by moving the head of the
`previous` list to the head of the `next` list.
*/
void linked_list_zipper_move_left(linked_list_zipper *zipper);

void linked_list_zipper_destroy(linked_list_zipper *zipper);
void linked_list_zipper_print(linked_list_zipper *zipper);

#endif
