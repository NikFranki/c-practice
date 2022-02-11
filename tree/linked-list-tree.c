#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

typedef struct TREE_NODE 
{
  TREE_TYPE value;
  struct TREE_NODE *left;
  struct TREE_NODE *right;
} TreeNode;

static TreeNode *tree;

void insert(TREE_TYPE value)
{
  TreeNode *current;
  TreeNode **link;

  link = &tree;

  while ((current = *link) != NULL)
  {
    if (value < current->value)
    {
      link = &current->left;
    }
    else
    {
      assert(value != current->value);
      link = &current->right
    }
  }

  current = malloc(sizeof(TreeNode));
  assert(current != NULL);
  current->value = value;
  current->left = NULL;
  current->right = NULL;
  *link = current;
}

TREE_TYPE *find(TREE_TYPE value)
{
  TreeNode *current;

  current = tree;

  while (current != NULL && current->value != value)
  {
    if (value < current->value)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }

  if (current != NULL)
  {
    return &current->value;
  }

  return NULL;
}

static void do_pre_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value))
{
  if (current != NULL)
  {
    callback(current->value);
    do_pre_order_traverse(current->left);
    do_pre_order_traverse(current->right);
  }
}

void pre_order_traverse(void (*callback)(TREE_TYPE value))
{
  do_pre_order_traverse(tree, callback);
}

void do_in_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value))
{
  if (current != NULL)
  {
    do_in_order_traverse(current->left);
    callback(current->value);
    do_in_order_traverse(current->right);
  }
}

void in_order_traverse(void (*callback)(TREE_TYPE value))
{
  do_in_order_traverse(tree, callback);
}

void do_post_order_traverse(TreeNode *current, void (*callback)(TREE_TYPE value))
{
  if (current != NULL)
  {
    do_post_order_traverse(current->left);
    do_post_order_traverse(current->right);
    callback(current->value);
  }
}

void post_order_traverse(void (*callback)(TREE_TYPE value))
{
  do_pre_order_traverse(tree, callback);
}