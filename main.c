#include "linked_list.h"

static void linked_list_example(void)
{
  linked_list *list = linked_list_create();
  linked_list_append(list, 1);
  linked_list_append(list, 2);
  linked_list_append(list, 3);
  linked_list_append(list, 4);
  linked_list_append(list, 5);

  linked_list_print(list);
  linked_list_zipper *zipper = linked_list_zipper_create(list);

  linked_list_zipper_print(zipper);

  linked_list_zipper_move_right(zipper);
  linked_list_zipper_move_right(zipper);
  linked_list_zipper_print(zipper);
  linked_list_zipper_move_left(zipper);
  linked_list_zipper_print(zipper);

  linked_list_zipper_destroy(zipper);
}

static void binary_tree_example(void)
{
}

int main(void)
{
  binary_tree_example();
  return 0;
}
