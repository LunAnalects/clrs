#ifndef CLRS_RBT_H
#define CLRS_RBT_H

#include "stdio.h"
#include "stdlib.h"
typedef int dtype;

typedef enum {black,red} Color;

typedef struct red_black_tree_node {
	Color color;
	struct red_black_tree_node* l;
	struct red_black_tree_node* r;
	struct red_black_tree_node* p;
	dtype d;
} rbtn, *rbtnp;

typedef struct red_black_tree {
	rbtnp root;
	rbtnp nil;
} rbt, *rbtp;


rbtp rbt_init();
rbtnp rbtn_init();

/*when do a left rotation, assume its right child y is not nil
*/
void l_rotate(rbtp t, rbtnp x);
void r_rotate(rbtp t, rbtnp x);
void rb_insert(rbtp t, rbtnp z);
void rb_insert_fixup(rbtp t, rbtnp z);
void rb_transplant(rbtp t, rbtnp u, rbtnp v);
rbtnp rb_minimum(rbtp t, rbtnp h);
void rb_delete(rbtp t, rbtnp z);
void rb_delete_fixup(rbtp t, rbtnp x);
#endif
