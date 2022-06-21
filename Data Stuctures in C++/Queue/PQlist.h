#pragma once
#include<iostream>
#include"Node.h"
class QueueList
{
private:
	Node* head, * tail;
public:
	QueueList() {
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
			return true;
		}
		else if (key > tail->data) {
			tail->next = t;
			tail = t;
			free(t);
			return true;
		}
		else {
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
	bool remove() {
		if (!isEmpty()) {
			head = head->next;
			return true;
		}
		return false;
	}

	//this will never be blocked so no compaction and full checks are needed
};
