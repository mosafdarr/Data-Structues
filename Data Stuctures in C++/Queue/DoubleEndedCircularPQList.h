#pragma once
#include<iostream>
#include"Node.h"
class DoubleEndedCircularPQList
{
private:
	Node* head, * tail;
public:
	DoubleEndedCircularPQList() {
		head = tail = NULL;
	}
	bool isEmpty() {
		return head == tail == NULL;
	}
	bool insert(int key) {
		Node* t = new Node(key);
		Node* p = head;
		if (isEmpty()) {
			head = tail = t;
			free(t);
			tail->next = head;
			return true;
		}
		else if (key > tail->data) {
			tail->next = t;
			tail = t;
			free(t);
			tail->next = head;
			return true;
		}
		else {
			if ((tail == head) && tail->data > key) {		//for one node
				t->next = head;
				head = t;
				free(t);
				tail->next = head;
				return true;
			}
			while (p) {
				if (p->next->data > key)
					break;
				p = p->next;
			}
			t->next = p->next;
			p->next = t;
			free(t);
			return true;
		}
	}
	bool removeHead() {
		if (!isEmpty()) {
			head = head->next;
			tail->next = head;
			return true;
		}
		return false;
	}
	bool removeTail() {
		if (!isEmpty()) {
			Node* t = head;
			while (t) {
				if (t->next == tail)
					break;
				t = t->next;
			}
			tail = t;
			free(t);
			tail->next = head;
			return true;
		}
		return false;
	}

	//this will never be blocked so no compaction and full checks are needed
};

