#include "forward_list.h"
/*Be sure that all node and list are in heap! Otherwise you should cope with deconstruction on your own
*/
struct forward_list_node* flist_head(struct forward_list* l){
	return l->head;
}


struct forward_list* flist_con(size_t len){
	struct forward_list* l = malloc(sizeof(struct forward_list));
	struct forward_list_node* n;
	for(int i =0;i<len;++i){
		n = flist_init_node(0);
		flist_push_front(l,n);
	}
	return l;
}
void flist_decon(struct forward_list* l){
	struct forward_list_node* n = flist_head(l);
	struct forward_list_node* temp;
	while(n != NULL){
		temp = n->next;
		free(n);
		n = temp;
	}
	free(l);
}

struct forward_list_node* flist_init_node(datatype d){
	struct forward_list_node* n = malloc(sizeof(struct forward_list_node));
	n->next = NULL;
	n->d = d;
	return n;
}
int flist_empty(struct forward_list* l){
	return flist_head(l)==NULL;
}
int flist_size(struct forward_list* l){
	int i = 0;
	struct forward_list_node* n = flist_head(l);
	while(n != NULL){
		++i;
		n = n->next;
	}
	return i;
}

struct forward_list_node* flist_insert_after(struct forward_list_node* d,struct forward_list_node* t){
	struct forward_list_node* temp = d->next;
	d->next = t;
	t->next = temp;
	return t;
}
struct forward_list_node* flist_erase_after(struct forward_list_node* d){
	struct forward_list_node* temp =d->next->next;
	free(d->next);
	d->next=temp;
	return temp;
}
struct forward_list_node* flist_push_front(struct forward_list* l,struct forward_list_node* n){
	n->next = l->head;
	l->head = n;
	return n;
}
struct forward_list_node* flist_pop_front(struct forward_list* l){
	struct forward_list_node* h = l->head;
	if(h == NULL){
		return NULL;
	}
	l->head = h->next;
	return h;
}


void flist_traverse(struct forward_list* l){
	struct forward_list_node* n = l->head;
	int i = 0;
	while(n != NULL){
			printf("No.%d, data:%d\n",i,n->d);
			++i;
			n = n->next;
	}

}