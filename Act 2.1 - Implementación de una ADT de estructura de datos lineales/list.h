//
//  File: list.h
//  Date: 25/09/2021
//  Author: Said Ortigoza
//  Description: Implementación de la clase Lista
//
//  Copyrigth (c) 2021 by Tecnologico de Monterrey.
//  All Rights Reserved. May be reproduced for any non-commercial
//  purpose

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T> class List;

template <class T>
class Link {
  private:
    Link(T);
    Link(T, Link<T>*);
    Link(const Link <T>&);
    
    T value;
    Link<T> *next;
    
    friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next (source.next) {}

template <class T>
class List {
  private:
    Link<T> *head;
    int size;
  
  public:
    List();
    ~List();
    
    void clear();
    bool empty() const;
    string toString() const;
  
    void insertFirst(T);
    void insertion(T);
    int search(T) const;
    void update(int, T);
    T deleteFirst();
    T deleteAt(int);
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
  clear();
}

template <class T>
void List<T>::clear() {
  Link<T> *p, *q;
  
  p = head;
  while (p != 0) {
    q = p->next;
    delete p;
    p = q;
  }
  head = 0;
  size = 0;
}

template <class T>
bool List<T>::empty() const {
  return (head == 0);
}

template <class T>
string List<T>::toString() const {
	Link<T> *p;
	stringstream aux;

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
void List<T>::insertFirst(T val) {
  Link<T> *newLink;
  
  newLink = new Link<T>(val);
  
  newLink->next = head;
  head = newLink;
  size++;
}

template <class T>
void List<T>::insertion (T val) {
  Link<T> *newLink, *p;
  
  newLink = new Link<T>(val);
  
  if(empty()) {
    insertFirst(val);
    return;
  }
  
  p = head;
  while (p->next != 0) {
    p = p->next;
  }
  
  newLink->next = 0;
  p->next = newLink;
  size++;
}

template <class T>
int List<T>::search (T val) const {
  Link<T> *p;
  int pos = 0;
  
  p = head;
  while (p != 0) {
    if (val == p->value) {
      return pos;
    }
    pos++;
    p = p->next;
  }
  return -1;
}

template <class T>
void List<T>::update (int index, T val) {
  Link<T> *p;
  int pos = 0;
  
  if (index < 0 || index >= size) {
    cout << "Invalid index" << endl;
  }
  
  p = head;
  while (pos != index) {
    p = p->next;
    pos++;
  }
  p->value = val;
}

template <class T>
T List<T>::deleteFirst () {
  Link<T> *p;
  T val;
  
  if (empty()) {
    cout << "Empty list" << endl;
  }
  
  p = head;
  
  head = p->next;
  val = p->value;
  
  delete p;
  size--;
  
  return val;
}

template <class T>
T List<T>::deleteAt (int index) {
  Link<T> *p, *q;
  T val;
  int pos = 0;
  
  if (index < 0 || index >= size) {
    cout << "Invalid index" << endl;
  }
  
  if (index == 0) {
    return deleteFirst();
  }
  
  p = head;
  q = 0;
  while (pos != index) {
    q = p;
    p = p->next;
    pos++;
  }
  val = p->value;
  q->next = p->next;
  
  delete p;
  return val;
  size--;
}

#endif