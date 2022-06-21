#pragma once
#include<iostream>
#include"Node.h"
class CircularQueueList
{
private:
	Node* head, * tail;
public:
	CircularQueueList() {
		head = tail = nullptr;
	}
	bool isEmpty() {
		return (head == nullptr && tail == nullptr);
	}
	bool insert(int key) {
		if (isEmpty()) {
			insertFirst(key);
			return true;
		}
		Node* t = new Node(key);
		tail->next = t;
		tail = t;
		free(t);
		tail->next = head;
		return true;
	}
	bool deleteHead() {
		if (!isEmpty()) {
			if (!head->next) {
				head = NULL;
				return true;
			}
			head = head->next;
			tail->next = head;
			return true;
		}
		return false;
	}
private:bool insertFirst(int key) {
		Node* t = new Node(key);
		if (isEmpty()) {
			head = t;
			head->next = t;
			free(t);
			return true;
		}
		t->next = head;
		head = t;
		tail->next = head;
		free(t);
		return true;
	}
	
};

