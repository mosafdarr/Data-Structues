#pragma once
#include<iostream>
#define N 10
class DoubleEndedCircularPQ
{
private:
	int A[N], head, tail;
	bool flag;
public:
	DoubleEndedCircularPQ() {
		head = tail = 0;
		flag = false;
	}
	bool isEmpty() {
		return (head == tail && flag == false);
	}
	bool isFull() {
		return (head == tail && flag == true);
	}
	bool insert(int key) {					//only inorder searching is allowed
		if (isEmpty()) {
			A[head] = key;
			tail++;
			return true;
		}
		if (!isFull()) {
			int i = 0;
			for (i = tail - 1; i >= 0; i--) {
				if (key > A[i])
					break;
				A[i + 1] = A[i];
			}
			A[i] = key;
			flag = true;
			tail++;
			return true;
		}
		return false;
	}
	bool removeHead(int& x) {
		if (!isEmpty()) {
			x = A[head++];
			flag = false;
			return true;
		}
		return false;
	}
	bool removeTail(int& x) {
		if (!isEmpty()) {
			x = A[tail--];
			flag = false;
			return true;
		}
		return false;
	}
};

