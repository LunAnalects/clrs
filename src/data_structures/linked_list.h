#ifndef CLRS_LINKED_LIST
#define CLRS_LINKED_LIST
#include "stdio.h"
#include "stdlib.h"
/*TODO: alternative implementation using sentinels
*/
struct Double_linked_list_node{
	int key;
	struct Double_linked_list_node* next;
	struct Double_linked_list_node* prev;
};

struct Double_linked_list{
	struct Double_linked_list_node* head;
	struct Double_linked_list_node* tail;
};
/* return a pointer to  empty list(head is NULL)
*/
struct Double_linked_list* create_list();
struct Double_linked_list_node* create_node(int key);
/* search the whole list
*/
struct Double_linked_list_node* list_search(struct Double_linked_list* l, int k);

/*insert at the head
*/
struct Double_linked_list_node* list_find_headnode(struct Double_linked_list_node* n);

struct Double_linked_list_node* list_find_tailnode(struct Double_linked_list_node* n);

void list_insert_head(struct Double_linked_list* l,struct Double_linked_list_node* n);

void list_insert_tail(struct Double_linked_list* l,struct Double_linked_list_node* n);

void list_insert_node_before(struct Double_linked_list* l,struct Double_linked_list_node* t,struct Double_linked_list_node* n);

void list_insert_node_after(struct Double_linked_list* l,struct  Double_linked_list_node* t,struct Double_linked_list_node* n);


#endif