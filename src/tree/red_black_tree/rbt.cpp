
#include "stdafx.h"
#include "rbt.h"

rbtp rbt_init() {
	rbtp r = (rbtp)malloc(sizeof(rbt));
	r->nil = (rbtnp)malloc(sizeof(rbtn));
	r->root = r->nil;
	r->nil->color = black;
	r->nil->l = NULL;
	r->nil->r = NULL;
	r->nil->p = NULL;
	r->nil->d = 0;
	return r;
}

rbtnp rbtn_init() {
	rbtnp n = (rbtnp)malloc(sizeof(rbtn));
	n->color = black;
	n->l = NULL;
	n->r = NULL;
	n->p = NULL;
	return n;
}

void l_rotate(rbtp t,rbtnp x) {
	rbtnp y = x->r;
	x->r = y->l;
	if (y->l != t->nil)
		y->l->p = x;
	y->p = x->p;
	if (x->p == t->nil)
		t->root = y;
	else if (x == x->p->l)
		x->p->l = y;
	else
		x->p->r = y;
	y->l = x;
	x->p = y;
}


void r_rotate(rbtp t, rbtnp y) {
	rbtnp x = y->l;
	y->l = x->r;
	if (x->r != t->nil)
		x->r->p = y;
	x->p = y->p;
	if (y->p != t->nil)
		t->root = x;
	else if (y == y->p->l)
		y->p->l = x;
	else
		y->p->r = x;
	x->r = y;
	y->p = x;
}

void rb_insert(rbtp t, rbtnp z) {
	rbtnp y = t->nil;
	rbtnp x = t->root;
	while (x != t->nil) {
		y = x;
		if (z->d < x->d)
			x = x->l;
		else
			x = x->r;
	}
	z->p = y;
	if (y == t->nil)
		t->root = z;
	else if (z->d < y->d)
		y->l = z;
	else
		y->r = z;
	z->l = t->nil;
	z->r = t->nil;
	z->color = red;
	rb_insert_fixup(t, z);
}
void rb_insert_fixup(rbtp t, rbtnp z) {
	rbtnp y;
	while(z->p->color == red) {
		if (z->p == z->p->p->l) {
			y = z->p->p->r;
			if (y->color == red) {
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				z = z->p->p;
			}
			else if (z == z->p->r) {
				z = z->p;
				l_rotate(t, z);
			}
			z->p->color = black;
			z->p->p->color = red;
			r_rotate(t, z->p->p);
		}
		else{
			y = z->p->p->l;
			if (y->color == red) {
				z->p->color = black;
				y->color = black;
				z->p->p->color = red;
				z = z->p->p;
			}
			else if (z == z->p->l) {
				z = z->p;
				r_rotate(t, z);
			}
			z->p->color = black;
			z->p->p->color = red;
			l_rotate(t, z->p->p);
		}
	}
	t->root->color = black;
}

void rb_transplant(rbtp t, rbtnp u, rbtnp v) {
	if (u->p == t->nil)
		t->root = v;
	else if (u == u->p->l)
		u->p->l = v;
	else
		u->p->r = v;
	v->p = u->p;
}
rbtnp rb_minimum(rbtp t, rbtnp h) {
	while (h->l != t->nil)
		h = h->l;
	return h;
}
void rb_delete(rbtp t, rbtnp z) {
	rbtnp y = z;
	rbtnp x;
	int y_color = y->color;
	if (z->l == t->nil) {
		x = z->r;
		rb_transplant(t, z, z->r);
	}
	else if (z->r = t->nil) {
		x = z->l;
		rb_transplant(t, z, z->l);
	}
	else {
		y = rb_minimum(t, z->r);
		y_color = y->color;
		x = y->r;
		if (y->p == z)
			x->p = y;
		else {
			rb_transplant(t, y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		rb_transplant(t, z, y);
		y->l = z->l;
		y->l->p = y;
		y->color = z->color;
	}
	if (y_color == black)
		rb_delete_fixup(t, x);

	free(z);
}

void rb_delete_fixup(rbtp t, rbtnp x) {
	rbtnp w;
	while (x != t->nil && x->color == black) {
		if (x == x->p->l) {
			w = x->p->r;
			if (w->color == red) {
				w->color = black;
				x->p->color = red;
				l_rotate(t, x->p);
				w = x->p->r;
			}
			if (w->l->color == black && w->r->color == black) {
				w->color = red;
				x = x->p;
			}
			else if (w->r->color == black) {
				w->l->color = black;
				w->color = red;
				r_rotate(t, w);
				w = x->p->r;
			}
			w->color = x->p->color;
			x->p->color = black;
			w->r->color = black;
			l_rotate(t, x->p);
			x = t->root;
		}
		else {
			w = x->p->l;
			if (w->color == red) {
				w->color = black;
				x->p->color = red;
				r_rotate(t, x->p);
				w = x->p->l;
			}
			if (w->r->color == black && w->l->color == black) {
				w->color = red;
				x = x->p;
			}
			else if (w->l->color == black) {
				w->r->color = black;
				w->color = red;
				l_rotate(t, w);
				w = x->p->l;
			}
			w->color = x->p->color;
			x->p->color = black;
			w->r->color = black;
			r_rotate(t, x->p);
			x = t->root;
		}
	}

	x->color = black;
}