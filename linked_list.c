#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

linked_list *linked_list_create(void)
{
  linked_list *list = malloc(sizeof(linked_list));
  list->head = NULL;

  return list;
}

void linked_list_append(linked_list *list, void *data)
{
  linked_list_node *node = malloc(sizeof(linked_list_node));
  node->data = data;
  node->next = NULL;

  if (linked_list_is_empty(list))
  {
    list->head = node;
    return;
  }

  linked_list_node *current = list->head;
  while (current->next != NULL)
  {
    current = current->next;
  }

  current->next = node;
}

void linked_list_prepend(linked_list *list, void *data)
{
  linked_list_node *node = malloc(sizeof(linked_list_node));
  node->data = data;
  node->next = list->head;
  list->head = node;
}

void linked_list_destroy(linked_list *list)
{
  linked_list_node *current = list->head;
  while (current != NULL)
  {
    linked_list_node *next = current->next;

    free(current);
    current = next;
  }

  free(list);
}

void linked_list_print(linked_list *list)
{
  linked_list_node *current = list->head;
  while (current != NULL)
  {
    printf(" %d ->", current->data);
    current = current->next;
  }

  printf(" NULL\n");
}

bool linked_list_is_empty(linked_list *list)
{
  return list->head == NULL;
}

linked_list_zipper *linked_list_zipper_create(linked_list *list)
{
  linked_list_zipper *zipper = malloc(sizeof(linked_list_zipper));
  zipper->previous = NULL;
  zipper->next = list;

  return zipper;
}

void linked_list_zipper_move_right(linked_list_zipper *zipper)
{
  if (zipper->next == NULL || zipper->next->head == NULL)
  {
    return;
  }

  if (zipper->previous == NULL)
  {
    zipper->previous = linked_list_create();
  }

  linked_list_node *node = zipper->next->head;
  linked_list_prepend(zipper->previous, node->data);
  zipper->next->head = node->next;
}

void linked_list_zipper_move_left(linked_list_zipper *zipper)
{
  if (zipper->previous == NULL || zipper->previous->head == NULL)
  {
    return;
  }

  if (zipper->next == NULL)
  {
    zipper->next = linked_list_create();
  }

  linked_list_node *node = zipper->previous->head;
  linked_list_prepend(zipper->next, node->data);
  zipper->previous->head = node->next;
}

void linked_list_zipper_destroy(linked_list_zipper *zipper)
{
  if (zipper->previous != NULL)
  {
    linked_list_destroy(zipper->previous);
  }

  if (zipper->next != NULL)
  {
    linked_list_destroy(zipper->next);
  }

  free(zipper);
}

void linked_list_zipper_print(linked_list_zipper *zipper)
{
  printf("----------------------\n");
  if (zipper->previous != NULL)
  {
    printf("Previous: ");
    linked_list_print(zipper->previous);
  }

  if (zipper->next != NULL)
  {
    printf("Next: ");
    linked_list_print(zipper->next);
  }
  printf("----------------------\n");
}
