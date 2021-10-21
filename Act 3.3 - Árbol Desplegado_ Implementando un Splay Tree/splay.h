//
//  File: bst.h
//  Date: 13/10/2021
//  Author: Said Ortigoza
//  Description: Implementación de la clase Splay Tree
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose
//

#ifndef SPLAY_H
#define SPLAY_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class SplayTree;

template <class T>
class Node {
    private:
        T value;
        Node *left, *right, *parent;

        Node<T>* succesor();
        Node<T>* rot_left(Node<T>*);
        Node<T>* rot_right(Node<T>*);

    public:
        Node(T);
        Node(T, Node<T>*, Node<T>* ,Node<T>*);
        
        Node<T>* add(T);
		Node<T>* remove(T);
        Node<T>* find(T);
        
        void preorder(std::stringstream&) const;
        void inorder(std::stringstream&) const;
        
        Node<T>* splay(Node<T>*, Node<T>*);

        friend class SplayTree<T>;
};

template <class T>
Node<T>::Node(T val)
    : value(val), left(0), right(0), parent(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, Node<T> *p)
    : value(val), left(le), right(ri), parent(p) {}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (right->left == 0) {
		right = right->right;
		ri->right = 0;
		return ri;
	}

	Node<T> *parent, *child;
	parent = right;
	child = right->left;
	while (child->left != 0) {
		parent = child;
		child = child->left;
	}
	parent->left = child->right;
	child->right = 0;
	return child;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x){
	Node<T> *y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->left = x;
	//Enlace de y con el padre de x
	y->parent = x->parent;
	x->parent = y;
	//Enlace del padre de x a y
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* x){
	Node<T> *y = x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent = x;
	y->right = x;
	//Enlace de y con el padre de x
	y->parent = x->parent;
	x->parent = y;
	//Enlace del padre de x a y
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template <class T>
Node<T>* Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			return left->add(val);
		} else {
			left = new Node<T>(val);
			left->parent = this;
			return left;
		}
	} else {
		if (right != 0) {
			return right->add(val);
		} else {
			right = new Node<T>(val);
			right->parent = this;
			return right;
		}
	}
}

template <class T>
Node<T>* Node<T>::remove(T val) {
	Node<T> *succ, *old;
	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				if(old->left != 0 && old->right != 0) {
					succ = left->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					left = succ;
				} else if (old->right != 0) { //Solo hijo derecho
					old->right->parent = left->parent;
					left = old->right;

				} else if (old->left != 0) { //Solo hijo izquierdo
					old->left->parent = left->parent;
					left = old->left;
				} else {  //Hoja
					left = 0;
				}
				delete old;
				return this;
			} else {
				return left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				if(old->left != 0 && old->right != 0) {
					succ = right->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					right = succ;
				} else if (old->right != 0) { //Solo hijo derecho
					old->right->parent = right->parent;
					right = old->right;

				} else if (old->left != 0) { //Solo hijo izquierdo
					old->left->parent = right->parent;
					right = old->left;
				} else {  //Hoja
					right = 0;
				}
				delete old;
				return this;
			} else {
				return right->remove(val);
			}
		}
	}
	return this; //To avoid warning
}

template <class T>
Node<T>* Node<T>::find(T val) {
	if (val == value) {
		return this;
	} else if (val < value) {
		if (left != 0)
		 	return left->find(val);
		else
			return this;
	} else {
		if (right != 0)
		 	return right->find(val);
		else
			return this;
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
Node<T>* Node<T>::splay(Node<T>* root, Node<T>* x){
	while(x->parent != 0){

		if(x->parent->value == root->value){
			if(x->parent->left && x->parent->left->value == x->value){
				rot_right(x->parent);
			}else{
				rot_left(x->parent);
			}
		}else{
			Node<T>*p = x->parent;
			Node<T>*g = p->parent;
			if(p->left && g->left &&
				x->value == p->left->value && p->value == g->left->value){
				rot_right(g);
				rot_right(p);
			}else if(p->right && g->right &&
				x->value == p->right->value && p->value == g->right->value){
				rot_left(g);
				rot_left(p);
			}else	if(p->left && g->right &&
				x->value == p->left->value && p->value == g->right->value){
				rot_right(p);
				rot_left(g);
			}else{
				rot_left(p);
				rot_right(g);
			}
		}
	}
	return x;
}

template <class T>
class SplayTree {
private:
	Node<T> *root;
	int elements;

public:
	SplayTree();
	
	void add(T);
	void remove(T);
	bool find(T);
	int size();
	
	bool empty() const;
	string preorder() const;
	string inorder() const;
};

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template<class T>
void SplayTree<T>::add(T val) {
	if (root != 0) {
			Node<T>* added = root->add(val);
			root = root->splay(root,added);
	} else {
		root = new Node<T>(val);
	}
	elements++;
}

template <class T>
void SplayTree<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
					succ->left = root->left;
					succ->right = root->right;
					succ->parent = 0;
					if(succ->left)
						succ->left->parent = succ;
					if(succ->right)
						succ->right->parent = succ;
			}
			delete root;
			root = succ;
		} else {
			Node<T>* p = root->remove(val);
			root = root->splay(root,p);
		}
	}
	elements--;
}

template <class T>
bool SplayTree<T>::find(T val) {
	if (root != 0) {
		Node<T>* found = root->find(val);
		root = root->splay(root,found);
		return (root->value == val);
	} else {
		return false;
	}
}

template <class T>
int SplayTree<T>::size() {
	return elements;
}

template <class T>
bool SplayTree<T>::empty() const {
	return (root == 0);
}

template <class T>
std::string SplayTree<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string SplayTree<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif