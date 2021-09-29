//
//  File: dlist.h
//  Date: 29/09/2021
//  Author: Said Ortigoza
//  Description: Implementación de la clase DList
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose

#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T> class DList;
template <class T> class DListIterator;

template <class T>
class DLink {
    private:
    DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
	friend class DListIterator<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
    private:
    DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

	friend class DListIterator<T>;

    public:
    DList();
	~DList();

	bool empty() const;
	void clear();
    string toStringForward() const;
    string toStringBackward() const;

    void insertFirst(T);
    void insertion(T);
    int search(T) const;
    void update(int, T);
    T deleteFirst();
    T deleteAt(int);
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
bool DList<T>::empty() const {
	return (head == 0 && tail == 0);
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
string DList<T>::toStringForward() const {
	stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
string DList<T>::toStringBackward() const {
	stringstream aux;
	DLink<T> *p;

	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

template <class T>
void DList<T>::insertFirst(T val) {
	DLink<T> *newLink;

	newLink = new DLink<T>(val);

	if (empty()) {
		head = newLink;
		tail = newLink;
	} else {
		newLink ->next = head;
		head->previous = newLink;
		head = newLink;
	}
	size++;
}

template <class T>
void DList<T>::insertion(T val) {
	DLink<T> *newLink, *p;

	newLink = new DLink<T>(val);

	if (empty()) {
		insertFirst(val);
		return;
	} else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}
	size++;
}

template <class T>
int DList<T>::search(T val) const {
	DLink<T> *p;
	int pos = 0;

	p = head;
	while(p != 0) {
		if (val == p->value) {
			return pos;
		}
		pos++;
		p = p->next;
	}
	return -1;
}

template <class T>
void DList<T>::update(int index, T val) {
	DLink<T> *p;
	int pos = 0;

	if (index < 0 || index >= size) {
		cout << "Invalid index" << endl;
	}

	p = head;
	while(pos != index) {
		p = p->next;
		pos++;
	}
	p->value = val;
}

template <class T>
T DList<T>::deleteFirst() {
	DLink<T> *p;
	T val;

	if (empty()) {
		cout << "Empty list";
	}

	p = head;
	val = p->value;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size --;

	return val;
}

template <class T>
T DList<T>::deleteAt(int index) {
	DLink<T> *p;
	T val;
	int pos = 0;

	if (index < 0 || index >= size) {
		cout << "Invalid index" << endl;
	}
	
	if (index == 0) {
		return deleteFirst();
	}

	p = head;
	while (pos != index) {
		p = p->next;
		pos++;
	}
	
	val = p->value;
	p->previous->next = p->next;

	if (p->next != 0) {
		p->next->previous = p->previous;
	}

	delete p;
	return val;
	size--;
}

#endif