#pragma once
#include<iostream>
#define N 10
class PQueue
{
private:
	int A[N], last;
public:
	PQueue() {
		last = 0;
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
	bool insert(int key) {
		if (isBlocked())
			compation();
		if (isEmpty()) {
			insertFirst(key);
			return true;
		}
		if (!isFull()) {
			int i = 0;
			for ( i = last - 1; i >= head; i--) {
				if (A[i] < key)
					break;
				else
					A[i+1] = A[i];
				}
			A[i] = key;
			last++;
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
private: bool insertFirst(int key) {
	if (isEmpty()) {
		A[last++] = key;
		return true;
	}
	return false;	
		}
};

