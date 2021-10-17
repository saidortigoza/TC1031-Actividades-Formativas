//
//  File: bst.h
//  Date: 13/10/2021
//  Author: Said Ortigoza
//  Description: Implementación de la clase bst
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose

#ifndef BST_H
#define BST_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <class T> class BST;

template <class T>
class Node {
  private:
    T value;
    Node *left, *right;

  public:
    Node(T);
    Node(T, Node<T>*, Node<T>*);
    
    void add(T);
    bool find(T);

    //Funciones de visit
    void preorder(stringstream&) const;
    void inorder(stringstream&) const;
    void postorder(stringstream&) const;
    void printlevel(stringstream&, int) const;
    void levelbylevel(stringstream&) const;

    //Funcion height
    int height() const;

    //Funcion ancestors
    bool ancestors(T, stringstream&);
    
    //Funcion whatlevelamI
    int whatlevelamI(T);

    friend class BST<T>;
};

template <class T>
Node<T>::Node(T val)
 : value(val), left(0), right(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		}
    else {
			left = new Node<T>(val);
		}
	}
  else {
		if (right != 0) {
			right->add(val);
		}
    else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	}
  else if (val < value) {
		return (left != 0 && left->find(val));
	}
  else {
		return (right != 0 && right->find(val));
	}
}

template <class T>
void Node<T>::preorder(stringstream &aux) const {
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
void Node<T>::inorder(stringstream &aux) const {
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
void Node<T>::postorder(stringstream &aux) const {
	if (left != 0) {
		left->postorder(aux);
	}
	if (right != 0) {
		right->postorder(aux);
	}
  if (aux.tellp() != 1) {
			aux << " ";
	}
	aux << value;
}

template <class T>
void Node<T>::printlevel(stringstream &aux, int level) const {
	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
  if (left != 0) {
		left->printlevel(aux, level -1);
	}
  if (right != 0) {
		right->printlevel(aux, level -1);
	}
}

template <class T>
void Node<T>::levelbylevel(stringstream &aux) const {
	int level = height();
  for(int i = 0; i < level; i++){
			printlevel(aux, i);
	}
}

template <class T>
int Node<T>::height() const {
	int leftLevel = 0, rightLevel = 0;
	if (left != 0) {
		leftLevel = left->height() + 1;
	}
  if (right != 0) {
		rightLevel= right->height() +1;
	}
  if (leftLevel == 0 && rightLevel == 0) {
    return 1;
  }
	return (rightLevel > leftLevel ) ? rightLevel : leftLevel;
}

template <class T>
bool Node<T>::ancestors(T val, stringstream &aux) {
	if (val == value) {
	  return true;
	}
  else if (val < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (left != 0 && left->ancestors(val,aux));
	}
  else {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (right != 0 && right->ancestors(val,aux));
	}
}

template <class T>
int Node<T>::whatlevelamI(T val) {
	if (val == value) {
		return 1;
	}
  else if (val < value) {
		if(left != 0)
			return left->whatlevelamI(val) + 1;
	}
  else {
		if (right != 0)
		return right->whatlevelamI(val) + 1;
	}
  return -1;
}

template <class T>
class BST {
  private:
    Node<T> *root;

  public:
    BST();
    
    bool empty() const;
    void add(T);
    bool find(T) const;
    
    string visit();
    string preorder() const;
    string inorder() const;
    string postorder() const;
    string levelbylevel() const;
    
    string ancestors(T);
    
    int height() const;
    
    int  whatlevelamI(T) const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	}
	else {
		return false;
	}
}

template <class T>
string BST<T>::visit() {
	stringstream aux;
	aux << preorder() << "\n";
	aux << inorder() << "\n";
	aux << postorder() << "\n";
	aux << levelbylevel();
	return aux.str();
}

template <class T>
string BST<T>::preorder() const {
	stringstream aux;
	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::inorder() const {
	stringstream aux;
	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::postorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string BST<T>::levelbylevel() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->levelbylevel(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::height() const {
	return root->height();
}

template <class T>
string BST<T>::ancestors(T val) {
	stringstream aux;
	aux << "[";
	if (!empty()) {
		if(!root->ancestors(val, aux))
			return "[]";
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val) const {
	if (root != 0) {
	 	int num = root->whatlevelamI(val);
		if(num < 0) return -1;
		return num;
	}
	else {
		return -1;
	}
}

#endif