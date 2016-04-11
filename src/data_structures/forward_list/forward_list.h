#ifndef CLRS_FORWARD_LIST_H
#define CLRS_FORWARD_LIST_H

#include "stdlib.h"
#include "stdio.h"
typedef int datatype;

struct forward_list{
	struct forward_list_node* head;
};

struct forward_list_node{
	struct forward_list_node* next;
	datatype d;
};

struct forward_list_node* flist_head(struct forward_list* l);

struct forward_list* flist_con(size_t len);
void flist_decon(struct forward_list* l);
struct forward_list_node* flist_init_node(datatype d);

int flist_empty(struct forward_list* l);
int flist_size(struct forward_list* l);

struct forward_list_node* flist_insert_after(struct forward_list_node* d,struct forward_list_node* t);
struct forward_list_node* flist_erase_after(struct forward_list_node* d);
struct forward_list_node* flist_push_front(struct forward_list* l,struct forward_list_node* n);
struct forward_list_node* flist_pop_front(struct forward_list* l);

void flist_traverse(struct forward_list* l);
/*TODO: reverse, remove_if, sort, merge
*/
#endif