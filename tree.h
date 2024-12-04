#ifndef TREE_H
#define TREE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct binary_tree_node
{
  int data;

  struct binary_tree_node *left;
  struct binary_tree_node *right;
} binary_tree_node;

typedef struct binary_tree
{
  binary_tree_node *root;
} binary_tree;

typedef struct binary_tree_node_with_direction
{
  binary_tree_node *node;
  bool is_left;
} binary_tree_node_with_direction;

typedef struct binary_tree_zipper_history_node
{
  binary_tree_node_with_direction *node_with_direction;
  struct binary_tree_zipper_history_node *next;
} binary_tree_zipper_history_node;

typedef struct binary_tree_zipper
{
  binary_tree_node *focus;
  binary_tree_zipper_history_node *history;
} binary_tree_zipper;

binary_tree *binary_tree_create();

void binary_tree_insert(binary_tree *tree, int data);
void binary_tree_print(binary_tree *tree);

void binary_tree_destroy(binary_tree *tree);

binary_tree_zipper *binary_tree_zipper_create(binary_tree *tree);

void binary_tree_zipper_move_left(binary_tree_zipper *zipper);
void binary_tree_zipper_move_right(binary_tree_zipper *zipper);
void binary_tree_zipper_move_up(binary_tree_zipper *zipper);
void binary_tree_zipper_print(binary_tree_zipper *zipper);
void binary_tree_zipper_destroy(binary_tree_zipper *zipper);

#endif
