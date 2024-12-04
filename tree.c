#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

binary_tree *binary_tree_create()
{
  binary_tree *tree = (binary_tree *)malloc(sizeof(binary_tree));
  tree->root = NULL;
  return tree;
}

void binary_tree_insert(binary_tree *tree, int data)
{
  binary_tree_node *node = malloc(sizeof(binary_tree_node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  if (tree->root == NULL)
  {
    tree->root = node;
    return;
  }

  binary_tree_node *current = tree->root;
  binary_tree_node *parent = NULL;

  while (true)
  {
    parent = current;

    if (data < current->data)
    {
      current = current->left;

      if (current == NULL)
      {
        parent->left = node;
        return;
      }
    }
    else
    {
      current = current->right;

      if (current == NULL)
      {
        parent->right = node;
        return;
      }
    }
  }
}

static void binary_tree_print_node(binary_tree_node *node)
{
  if (node->left != NULL)
  {
    binary_tree_print_node(node->left);
  }

  printf("%d\n", node->data);

  if (node->right != NULL)
  {
    binary_tree_print_node(node->right);
  }
}

void binary_tree_print(binary_tree *tree)
{
  binary_tree_node *node = tree->root;
  binary_tree_print_node(node);
}

static void binary_tree_destroy_node(binary_tree_node *node)
{
  if (node->left != NULL)
  {
    binary_tree_destroy_node(node->left);
  }

  if (node->right != NULL)
  {
    binary_tree_destroy_node(node->right);
  }

  free(node);
}

void binary_tree_destroy(binary_tree *tree)
{
  if (tree->root != NULL)
  {
    binary_tree_destroy_node(tree->root);
  }

  free(tree);
}

static bool binary_tree_node_is_leaf(binary_tree_node *node)
{
  return node->left == NULL && node->right == NULL;
}

binary_tree_zipper *binary_tree_zipper_create(binary_tree *tree)
{
  binary_tree_zipper *zipper = malloc(sizeof(binary_tree_zipper));
  zipper->focus = tree->root;
  zipper->history = NULL;

  return zipper;
}

void binary_tree_zipper_move_left(binary_tree_zipper *zipper)
{
  if (binary_tree_node_is_leaf(zipper->focus))
  {
    return;
  }

  binary_tree_zipper_history_node *history_node = malloc(sizeof(binary_tree_zipper_history_node));
  history_node->node_with_direction = malloc(sizeof(binary_tree_node_with_direction));
  history_node->node_with_direction->node = zipper->focus;
  history_node->node_with_direction->is_left = true;
  history_node->next = zipper->history;

  zipper->history = history_node;
  zipper->focus = zipper->focus->left;
}

void binary_tree_zipper_move_right(binary_tree_zipper *zipper)
{
  if (binary_tree_node_is_leaf(zipper->focus))
  {
    return;
  }

  binary_tree_zipper_history_node *history_node = malloc(sizeof(binary_tree_zipper_history_node));
  history_node->node_with_direction = malloc(sizeof(binary_tree_node_with_direction));
  history_node->node_with_direction->node = zipper->focus;
  history_node->node_with_direction->is_left = false;
  history_node->next = zipper->history;

  zipper->history = history_node;
  zipper->focus = zipper->focus->right;
}

void binary_tree_zipper_move_up(binary_tree_zipper *zipper)
{
  if (zipper->history == NULL)
  {
    return;
  }

  binary_tree_zipper_history_node *history_node = zipper->history;
  zipper->focus = history_node->node_with_direction->node;
  zipper->history = history_node->next;
  free(history_node->node_with_direction);
  free(history_node);
}

void binary_tree_zipper_print(binary_tree_zipper *zipper)
{
  binary_tree_node *node = zipper->focus;
  printf("%d\n", node->data);

  binary_tree_zipper_history_node *history_node = zipper->history;
  while (history_node != NULL)
  {
    binary_tree_node_with_direction *node_with_direction = history_node->node_with_direction;
    printf("%d\n", node_with_direction->node->data);
    history_node = history_node->next;
  }

  printf("\n");
}

void binary_tree_zipper_destroy(binary_tree_zipper *zipper)
{
  if (zipper->history != NULL)
  {
    binary_tree_zipper_history_node *history_node = zipper->history;
    binary_tree_zipper_history_node *next = NULL;

    while (history_node != NULL)
    {
      next = history_node->next;
      free(history_node->node_with_direction);
      free(history_node);
      history_node = next;
    }
  }

  free(zipper);
}
