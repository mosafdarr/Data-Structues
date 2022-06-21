#pragma once
#include<iostream>
#include"Node.h"
class Stacklist
{
private:
	Node* top, *first;
public:
	Stacklist() {
		first = top = NULL;
	}
	// Empty check to check weather the stack list is empty or not // we will not have full check because list is flexible
	bool isEmpty() {
		return top == NULL;
	}
	// method to push in stack list
	bool push(int key){
			Node* t = new Node(key);	// creating a new node having data key
			if (isEmpty()) {			// necessary empty check 
				t->next = NULL;
				first = top = t;
				return true;
			}							// if not empty 
			top = t;
			free(t);
			return true;
	}
	// method to pop from stack list 
	bool pop(int& x) {				// will pop from anywhere in the stack
		if (!isEmpty()) {			// stack cannot supposed to pop from empty list
			x = top->data;
			Node* t = first;
			while (t) {		
				if (t->next->data == x)
					break;
				t = t->next;
			}
			top = t;
			return true;
		}
		return false;
	}

};

