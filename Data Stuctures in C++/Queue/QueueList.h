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
		if (isEmpty()) {
			tail = t;
			free(t);
			return true;
		}
		tail->next = t;
		tail = t;
		free(t);
		return true;
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

