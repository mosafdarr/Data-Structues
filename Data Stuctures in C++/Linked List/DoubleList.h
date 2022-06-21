#pragma once
#include<iostream>
#include"Node.h"
class DoubleList
{
private:
	Node* first, * last;
public:
	DoubleList() {
		first = last = NULL;
	}
	bool isEmpty() {
		return first == NULL;
	}
	bool insertFirst(int key) {
		Node* t = new Node(key);
		if (isEmpty()) {
			last = t;
			delete t;
			first = last;
			return true;
		}
		t->next = first;
		t->prev = NULL;
		first = t;
		delete t;
		return true;
	}
	bool insertLast(int key) {
		if (isEmpty()) {
			insertFirst(key);
			return true;
		}
		Node* t = new Node(key);
			t->prev = last;
			t->next = NULL;
			last = t;
			delete t;
			return true;
	}
	bool insertAfter(int key, int newVal) {
		Node* t = first;
		if(!isEmpty()){
		while (t) {
			if (t->data == key)
				break;
			t = t->next;
		}
		Node* p = new Node(newVal);
		p->next = t->next;
		t->next->prev = p;
		t->next = p;
		p->prev = t;	
		delete t;
		return true;	
	}
		return false;
	} 
	bool deleteNode(int key) {
		if (!isEmpty()) {
			if (key == first->data) {
				first = first->next;
				first->prev = NULL;
				return true;
			}
			if (key == last->data) {
				last = last->prev;
				last->next = NULL;
				return true;
			}
			Node* t = first;
			while (t) {
				if (t->next->data = key)
					break;
				t = t->next;
			}
			t->next->next->prev = t;
			t->next = t->next->next;
			delete t;
			return true;
		}
		return false;
		
	}
	bool deleteLast() {
		if (!isEmpty()) {
			last = last->prev;
			last->next = NULL;
			return true;
		}
		return false;
	}
	bool deleteFirst() {
		if (!isEmpty()) {
			first = first->next;
			first->prev = NULL;
			return true;
		}
		return false;
	}
	bool search(int key) {
		Node* t = first;
		while (t) {
			if (t->data == key)
				return true;
			t = t->next;
		}
		return false;
	}
	bool update(int key, int newVal) {
		Node* t = first;
		while (t) {
			if (t->data == key) {
				t->data = newVal;
				return true;
			}
			t = t->next;
		}
		return fasle;
	}
};

