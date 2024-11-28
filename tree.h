#ifndef TREE_H
#define TREE_H

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

binary_tree *binary_tree_create();

void binary_tree_insert(binary_tree *tree, int data);
void binary_tree_print(binary_tree *tree);

void binary_tree_destroy(binary_tree *tree);

#endif
