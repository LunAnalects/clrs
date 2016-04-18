#ifndef CLRS_BST_H
#define CLRS_BST_H

#include "stdlib.h"
#include "stdio.h"

typedef int dtype;

typedef struct binary_search_tree_node {
	struct binary_search_tree_node* parent;
	struct binary_search_tree_node* left;
	struct binary_search_tree_node* right;
	dtype d;
} bstn, *bstnp;

typedef struct binary_search_tree {
	struct binary_search_tree_node* root;
} bst, *bstp;

void inorder_walk(bstnp t);

bstp bstp_init();
bstnp bstnp_init();

/*recursion version and iterative version
*/
bstnp tree_search_recursion(bstnp tp, dtype k);
bstnp tree_search(bstnp tp, dtype k);

bstnp tree_minimum(bstnp h);
bstnp tree_maximum(bstnp h);

bstnp tree_successor(bstnp x);
bstnp tree_predecessor(bstnp x);

void tree_insert(bstp t, bstnp n);
void tree_delete(bstp t, bstnp d);
void transplant(bstp t, bstnp u, bstnp v);
#endif
