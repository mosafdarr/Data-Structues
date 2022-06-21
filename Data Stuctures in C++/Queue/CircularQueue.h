#pragma once
#include<iostream>
using namespace std;
#define N 10
class CircularQueue
{
private:
	int A[N], tail, head;
	bool flag;
public:
	CircularQueue() {
		tail = head = 0;
		flag = false;
	}
	bool isEmpty() {
		return (head == tail && flag == false);
	}
	bool isFull() {
		return (head == tail && flag == true);
	}
	bool insert(int key) {
		if (!isFull()) {
			if (tail == N && head > 0)
				tail = 0;
			A[tail++] = key;
			flag = true;
			return true;
		}
		return false;
	}
	bool remove(int &x) {
		if (!isEmpty()) {
			x = A[head++];
			flag = false;
			return true;
		}
		return false;
	}
	bool display() {
		if (!isFull()) {
			int i = head; 
			while (i != tail) {
				cout << A[i] << " ";
				i++;
				if (i == N)
					i = 0;
			}
			return;
		}
		cout << A[head];
		int i = head + 1;
		while (i != tail) {
			cout << A[i] << " ";
			i++;
			if (i == N)
				i = 0;
		}
		return;
	}

};

