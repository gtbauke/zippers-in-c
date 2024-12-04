#include "linked_list.h"
#include "tree.h"

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
  binary_tree *tree = binary_tree_create();
  binary_tree_insert(tree, 5);
  binary_tree_insert(tree, 3);
  binary_tree_insert(tree, 7);
  binary_tree_insert(tree, 2);
  binary_tree_insert(tree, 4);
  binary_tree_insert(tree, 6);
  binary_tree_insert(tree, 8);

  binary_tree_zipper *zipper = binary_tree_zipper_create(tree);

  binary_tree_zipper_print(zipper);
  binary_tree_zipper_move_left(zipper);
  binary_tree_zipper_print(zipper);

  binary_tree_zipper_move_right(zipper);
  binary_tree_zipper_print(zipper);

  binary_tree_zipper_move_up(zipper);
  binary_tree_zipper_print(zipper);

  binary_tree_zipper_destroy(zipper);
  binary_tree_destroy(tree);
}

int main(void)
{
  binary_tree_example();
  return 0;
}
