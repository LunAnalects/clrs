#include "linked_list.h"


/* return a pointer to  empty list(head is NULL)
*/
struct Double_linked_list* create_list(){
	struct Double_linked_list* add = malloc(sizeof(struct Double_linked_list));
	add->head = NULL;
	add->tail = NULL;
	return add;
}
struct Double_linked_list_node* create_node(int key){
	struct Double_linked_list_node* n = malloc(sizeof(struct Double_linked_list_node));
	n->prev = NULL;
	n->next = NULL;
	n->key = key;
	return n;
}
/*arg1:l,list
  arg2:k,value for searching

traverse the whole list from the head(if head is NULL, which means the list is empty, return NULL)
*/
struct Double_linked_list_node* list_search(struct Double_linked_list* l, int k){
	struct Double_linked_list_node* x =l->head;
	while(x && x->key !=k){
		x = x->next;
	}
	return x;
}

/*arg1:n, node to be searched
keep moving to prev or next. If prev or next is NULL,return current node as head or tail.
if n is NULL, return n
*/
struct Double_linked_list_node* list_find_headnode(struct Double_linked_list_node* n){
	while(n && n->prev){
		n = n->prev;
	}
	return n;
}
struct Double_linked_list_node* list_find_tailnode(struct Double_linked_list_node* n){
	while(n && n->next){
		n = n->next;
	}
	return n;
}
/*insert before the head(if head is NULL)
*/
void list_insert_head(struct Double_linked_list* l,struct Double_linked_list_node* n){
	if(!l->head){
		l->head =n;
	}
	else{
		l->head->prev = n;
		n->next =l->head;
		l->head = n;
		n->prev = NULL;
	}
}

void list_insert_tail(struct Double_linked_list* l, struct Double_linked_list_node* n){
	if(!l->tail){
		l->tail =n;
	}
	else{
		l->tail->next = n;
		n->prev =l->tail;
		l->tail = n;
	}
}
/*arg1:t, target
  arg2:n, node to be inserted

 Assuming that n is not linked to another list and t is not NULL
*/
void list_insert_node_before(struct Double_linked_list* l,struct Double_linked_list_node* t,struct Double_linked_list_node* n){
	if(l->head !=t){
		t->prev->next = n;
		n->prev = t->prev;
		t->prev = n;
		n->next = t;
	}else{
		list_insert_head(l, n);
	}
}

void list_insert_node_after(struct Double_linked_list* l,struct  Double_linked_list_node* t,struct Double_linked_list_node* n){
	if(l->tail !=t){
		t->next->prev = n;
		n->next = t->next;
		t->next = n;
		n->prev = t;
	}else{
		list_insert_tail(l, n);
	}
}


