#pragma once
#include<iostream>
#define N 10
class Queue
{
private:
	int A[N], tail, head;
public:
	Queue() {
		tail = head = 0;
	}
	bool isFull() {
		return head == 0 && tail == N;
	}
	bool isEmpty() {
		return head == tail == 0;
	}
	bool isBlocked() {
		return (tail == N && head > 0);
	}
	bool compation() {
		for (int i = head; i < tail; i++)
			A[i - head] = A[i];
		tail -= head;
		head = 0;
		return true;
	}
	bool insert(int x) {
		if (!isFull()) {
			if (isBlocked())
				compation();
			A[tail++] = x;
			return true;
		}
		return false;
	}
	bool remove(int& x) {
		if (!isEmpty()) {
			x = A[head++];
			return true;
		}
		return false;
	}

};

