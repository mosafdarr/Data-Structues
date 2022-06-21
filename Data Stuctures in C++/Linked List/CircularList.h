#pragma once
#include<iostream>
#include"Node.h"
class CircularList
{
private:
	Node* first, * last;
public:
	CircularList() {
		first = last = NULL;
	}
	bool isEmpty() {
		return first == NULL;
	}
	bool insertFirst(int key) {
		Node* t = new Node(key);
		if (isEmpty()) {
			last = t;
			t->next = t;
			delete t;
			first = last;
			return true;
		}
		t->next = first;
		first = t;
		last->next = t;
		free(t);
		return true;
	}
	bool insertLast(int key) {
		if (isEmpty()) {
			insertFirst(key);
			return true;
		}
		Node* t = new Node(key);
		t->next = first;
		last->next = t;
		last = t;
		delete t;
		return true;
	}
	bool insertAfter(int key, int newVal) {
		if (!isEmpty()) {
			Node* t = new Node(newVal);
			if (key == last->data) {
				t->next = first;
				last->next = t;
				last = t;
				delete t;
				return true;
			}
			Node* t1 = first;
			do {
				if (t1->data == key) {
					t->next = t1->next;
					t1->next = t;
					return true;
				}
				t1 = t1->next;
			}	while (t1 != first);
		}
		return false;

	}
	bool deleteNode(int key) {
		if (!isEmpty()) {
			if (key == first->data) {			//to delete first node
				first = first->next;
				last->next = first;
				return true;
			}
			Node* t = first;
			if (key == last->data) {			//to delete the last node
				do {
					if (t->next == last)
						break;
					t = t->next;
				}while (t != first);
				last = t;
				delete t;
				last->next = first;
				return true;
			}
			do {
				if (t->next->data == key)		//to delete any in between Node
					break;	
				t = t->next;
			}while (t != first);
			t->next = t->next->next;
			return true;
		}
		return false;
	}
	bool deleteLast() {
		if (!isEmpty()) {
			Node* t = first;
			while (t->next != last) 
				t = t->next;
			last = t;
			delete t;
			last->next = first;
			return true;
		}
		return false;
	}
	bool deleteFirst() {
		if (!isEmpty()) {
			if (first->next) {
				first = first->next;
				last->next = first;
				return true;
			}
			else {
				first = NULL;
				return true;
			}
		}
		return false;
	}
	bool update(int key, int newVal) {
		Node* t = first;
		do {
			if (t->data == key) {
				t->data = newVal;
				return true;
			}
			t = t->next;
		}while (t != first);
		return false;
	}
	bool search(int key) {
		Node* t = first;
		if(!isEmpty()){	
		do{
			if (t->data == key)
				return true;
			t = t->next;
		}	while (t != first); 
	}
		return false;
	}


};

