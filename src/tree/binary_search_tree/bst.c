#include "bst.h"

bstp bstp_init() {
	bstp t1 = (bstp)malloc(sizeof(bst));
	t1->root = NULL;
	return t1;
}

bstnp bstnp_init() {
	bstnp np1 = (bstnp)malloc(sizeof(bstn));
	np1->d = 0;
	np1->left = NULL;
	np1->right = NULL;
	np1->parent = NULL;
	return np1;
}

void inorder_walk(bstnp t) {
	if (t != NULL) {
		inorder_walk(t->left);
		printf("%d\n", t->d);
		inorder_walk(t->right);
	}
}

bstnp tree_search_recursion(bstnp tp, dtype k) {
	if (tp == NULL || tp->d == k) {
		return tp;
	}
	if (tp->d > k) {
		return tree_search(tp->left, k);
	}
	else {
		return tree_search(tp->right, k);
	}
}

bstnp tree_search(bstnp tp, dtype k) {
	while (tp == NULL || tp->d == k) {
		tp = (tp->d > k) ? tp->left : tp->right;
	}
	return tp;
}

bstnp tree_minimum(bstnp h) {
	while (h->left != NULL)
		h = h->left;
	return h;
}

bstnp tree_maximum(bstnp h) {
	while (h->right != NULL)
		h = h->right;
	return h;
}


bstnp tree_successor(bstnp x) {
	if (x->right != NULL)
		return tree_minimum(x->right);

	bstnp y = x->parent;
	while (y != NULL && x == y->right) {
		x = y;
		y = y->parent;
	}
	return y;
}

bstnp tree_predecessor(bstnp x) {
	if (x->left != NULL)
		return tree_maximum(x->left);

	bstnp y = x->parent;
	while (y != NULL && y->left == x) {
		x = y;
		y = y->parent;
	}
	return y;
}

void tree_insert(bstp t, bstnp n) {
	bstnp y = NULL;
	bstnp x = t->root;
	while (x != NULL) {
		y = x;
		if (n->d < x->d)
			x = x->left;
		else
			x = x->right;
	}
	n->parent = y;
	if (y == NULL)
		t->root = n;
	else if (n->d < y->d)
		y->left = n;
	else
		y->right = n;
}

void tree_delete(bstp t, bstnp d) {
	bstnp y;
	if (d->left == NULL)
		transplant(t, d, d->right);
	else if (d->right == NULL)
		transplant(t, d, d->left);
	else {
		y = tree_minimum(d->right);
		if (y->parent != d) {
			transplant(t, y, y->right);
			y->right = d->right;
			y->right->parent = y;
		}
		transplant(t, d, y);
		y->left = d->left;
		y->left->parent = y;
	}
	free(d);
}

void transplant(bstp t, bstnp u, bstnp v) {
	if (u->parent == NULL)
		t->root = v;
	else if (u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}
