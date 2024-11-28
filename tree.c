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
