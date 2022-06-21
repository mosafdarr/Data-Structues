#pragma once
#include<iostream>
#include"Node.h"
class SingleList
{
private:
	Node* first, * last;
public:
	SingleList() {
		first = last = NULL;
	}
	bool isEmpty() {
		return first == NULL;
	}
	bool insertFirst(int key) {
		if (isEmpty()) {
			Node* t = new Node(key);
			last = t;
			delete t;
			first = last;
			return true;
		}
		Node* t = new Node(key);
		t->next = first;
		first = t;
		return true;
	}
	bool insertLast(int key) {
		if (isEmpty()) {
			insertFirst(key);
			return true;
		}
		Node* t = new Node(key);
		last->next = t;
		last = t;
		return true;
	}
	bool insertAfter(int key, int newVal) {
		if (!isEmpty()) {
			Node* t = new Node(newVal);
			if (key == last->data) {
				last->next = t;
				last = t;
				return NULL;
			}
			Node* t1 = first;
			while (t1) {
				if (t1->data == key) {
					t1->next = t;
					t->next = t1->next;
					return true;
				}
				t1 = t1->next;
			}
		}
		return false;

	}
	bool deleteNode(int key) {
		if (!isEmpty()) {
			if (key == first->data) {			//to delete first node
				first = first->next;
				return true;
			}
			Node* t = first;
			if (key == last->data) {			//to delete the last node
				while (t) {
					if (t->next == last)
						break;
					t = t->next;
				}
				last = t;
				delete t;
				return true;
			}
			while (t) {
				if (t->next->data == key)
					break;
			}
			t->next = t->next->next;
			return true;
		}
		return false;
	}
	bool deleteLast() {
		if (!isEmpty()) {
			Node* t = first;
			while (t) {
				if (t->next == last)
					break;
				t = t->next;
			}
			last = t;
			delete t;
			return true;
		}
		return false;
	}
	bool deleteFirst() {
		if (!isEmpty()) {
			if (first->next) {
				first = first->next;
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
		while (t) {
			if (t->data == key) {
				t->data = newVal;
				return true;
			}
			t = t->next;
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

	

	
};

