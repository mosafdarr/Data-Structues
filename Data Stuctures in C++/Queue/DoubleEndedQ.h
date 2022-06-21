#pragma once
#include<iostream>
#define N 100
class DoubleEndedQ
{
private:
	int A[N], tail, head;
public:
	DoubleEndedQ() {
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
	bool insertTail(int x) {
		if (!isFull()) {
			if (isBlocked())
				compation();
			A[tail++] = x;
			return true;
		}
		return false;
	}
	bool removeTail(int &x) {
		if (!isEmpty()) {
			x = A[tail--];
			return true;
		}
		return false;
	}
	bool removeHead(int& x) {
		if (!isEmpty()) {
			x = A[head++];
			return true;
		}
		return false;
	}
	bool insertHead(int key) {
		if (isEmpty()) {
			A[head] = key;
			tail++;
			return true;
		}
		else if(!isFull){
			for (int i = tail; i >= 0; i--)
				A[i + 1] = A[i];
			A[head] = key;
			tail++;
			return true;
		}
		return false;
	}
};

