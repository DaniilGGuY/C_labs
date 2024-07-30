#include <stdlib.h>
#include <string.h>

#include "tree.h"

void tree_free(node_t *tree)
{
    if (!tree)
        return;
    
    tree_free(tree->left);
    tree_free(tree->right);

    node_free(tree);
}

void tree_each(node_t *tree, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!tree)
        return;

    tree_each(tree->left, action, param);
    tree_each(tree->right, action, param);

    action(tree->key, &tree->num, param);
}

int *tree_get_min(node_t *tree)
{
    if (!tree->left)
        return &tree->num;
    
    return tree_get_min(tree->left);
}

int *tree_get_max(node_t *tree)
{
    if (!tree->right)
        return &tree->num;
    
    return tree_get_max(tree->right);
}

int *tree_find(node_t *tree, const char *key)
{
    if (!tree)
        return NULL;
    
    int cmp = strcmp(key, tree->key);
    if (cmp == 0)
        return &tree->num;
    else if (cmp < 0)
        return tree_find(tree->left, key);
    else
        return tree_find(tree->right, key);
}

node_t *tree_insert(node_t *tree, node_t *el)
{
    if (!tree)
        return el;

    int cmp = strcmp(el->key, tree->key);
    if (cmp < 0)
        tree->left = tree_insert(tree->left, el);
    else
        tree->right = tree_insert(tree->right, el);

    return tree;
}

node_t *del_el_tree(node_t *tree)
{
    if (!tree)
        return NULL;
    if (!tree->left && !tree->right)
    {
        node_free(tree);
        tree = NULL;
    }
    else if (!tree->left && tree->right)
    {
        node_t *old_el = tree;
        tree = tree->right;
        node_free(old_el);
    }
    else if (tree->left && !tree->right)
    {
        node_t *old_el = tree;
        tree = tree->left;
        node_free(old_el);
    }
    else
    {
        node_t *old_el = tree, *last_el;
        tree = tree->left;
        if (tree->right)
        {
            while (tree->right)
                tree = tree->right;
            tree->left = old_el->left;
            tree->right = old_el->right;
            last_el = old_el->left;
            while (last_el->right != tree)
                last_el = last_el->right;
            last_el->right = NULL;
        }
        else
            tree->right = old_el->right;   

        node_free(old_el);    
    }

    return tree;
}

node_t *tree_delete(node_t *tree, const char *key)
{
    if (!tree)
        return NULL;

    int cmp = strcmp(key, tree->key);
    if (cmp < 0)
        tree->left = tree_delete(tree->left, key);
    else if (cmp > 0)
        tree->right = tree_delete(tree->right, key);
    else
        tree = del_el_tree(tree);

    return tree;
}