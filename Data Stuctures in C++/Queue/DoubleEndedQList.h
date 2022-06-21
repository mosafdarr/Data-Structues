#pragma once
#include<iostream>
#include"Node.h"
class DoubleEndedQList
{
private:
	Node* head, * tail;
public:
	DoubleEndedQList() {
		head = tail = NULL;
	}
	bool isEmpty() {
		return head == tail == NULL;
	}
	bool insertTail(int key) {
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
	bool insertHead(int key) {
		Node* t = new Node(key);
		if (isEmpty()) {
			head = t;
			free(t);
			return true;
		}
		t->next = head;
		head = t;
		free(t);
		return true;
	}
	bool removeHead() {
		if (!isEmpty()) {
			head = head->next;
			head->prev = Null;
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
			tail->next = NULL;
			return true;
		}
		return false;
	}

	//this will never be blocked so no compaction and full checks are needed
};

