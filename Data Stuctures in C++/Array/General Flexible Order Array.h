#pragma once
#include<iostream>
using namespace std;
class GFOrderArray
{
private:
	int* A, size, last, first;
	float occupancy;
public:
	GFOrderArray(int size) {
		A = new int[size];
		last = first = occupancy = 0;
	}
	bool isEmpty() {
		return last == first == 0;
	}
	bool block() {
		occupancy = float(last / size);
		return occupancy >= 0.8;
	}
	bool needToShrink() {
		occupancy = float(last / size);
		return occupancy <= 0.4;
	}
	bool grow() {
		size *= 2;
		int* B = new int[size];
		for (int i = 0; i < last; i++) {
			B[i] = A[i];
		}
		A = B;
		delete B;
		return true;
	}
	bool shrink() {
		size /= 2;
		int* B = new int[size];
		for (int i = 0; i < last; i++)
			B[i] = A[i];
		A = B;
		delete B;
		return true;
	}
	bool insertFirst(int key) {
		if (isEmpty) {
			A[first] = key;
			last++;
			return true;
		}
		return false;

	}
	bool insertLast(int key) {
		if (block())
			grow();
		if (isEmpty()) {
			A[last] = key;
			first = last;
			last++;
			return true;
		}
		if (key > A[last - 1]) {
			A[last++] = key;
			return true;
		}
		return false;
	}
	bool insert(int key) {
		if (isEmpty()) {
			A[first] = key;
			last++;
			return true;
		}
		if (block())
				grow();
		int i = 0;
		for (i = last - 1; i >= 0; i++) {
			if (A[i] > key)
				A[i + 1] = A[i];
			else
				break;
		}
		A[i] = key;
		last++;
		return true;
	}
	bool deletefirst() {
		if (!isEmpty()) {
			if (first == last) {
				last--;
				return true;
			}
			for (int i = 0; i < last; i++)
				A[i] = A[i + 1];
			if (needToShrink())
				shrink();
			return true;
		}
		return false;
	}
	bool deleteLast() {
		if (!isEmpty) {
			last--;
			if (needToShrink())
				shrink();
			return true;
		}
		return false;
	}
	bool deleteAfter(int index) {
		if (!isEmpty()) {
			if (index < last - 1) {
				int i = 0;
				for (i = index; i < last - 1; i++)
					A[i] = A[i + 1];
				last--;
				if (needToShrink())
					shrink();
				return true;
			}
		}
		return false;
	}
	bool deletebefore(int index) {
		if (!isEmpty()) {
			if (index <= last && index > 0) {
				int i = 0;
				for (i = index - 1; i < last - 1; i++)
					A[i] = A[i + 1];
				last--;
				if (needToShrink())
					shrink();
				return true;
			}
		}
		return false;
	}
	bool deleteAt(int index) {
		if (index == last - 1) {
			last--;
			if (needToShrink())
				shrink();
			return true;
		}
		if (index < (last - 1) && index >= 0) {
			int i = 0;
			for (int i = index; i < last - 1; i++)
				A[i] = A[i + 1];
			last--;
			if (needToShrink())
				shrink();
			return true;
		}
		return false;
	}
	bool updateAt(int key, int index) {
		if (!isEmpty()) {
			if (A[index + 1] > key && A[index - 1] < key) {
				A[index] = key;
				return true;
			}
		}
	}
	bool searchByVal(int key) {
		if (!isEmpty())
			for (int i = 0; i < last; i++)
				if (A[i] == key)
					return true;
		return false;
	}
	int searchOccurances(int key) {
		int count = 0;
		if (!isEmpty()) {
			for (int i = 0; i < last; i++)
				if (A[i] == key)
					count++;
			return count;
		}
		return -1;
	}
	bool searchAndUpdate(int oldVal, int newVal) {
		if (!isEmpty()) {
			for (int i = 0; i < last; i++)
				if (A[i] == oldVal) 
					if (A[i + 1] > newVal && A[i - 1] < newVal) {
						A[i] = newVal;
						return true;
					}	
		}
		return false;
	}
	bool searchAndDelete(int key) {
		if (!isEmpty()) {
			for (int i = 0; i < last; i++)
				if (A[i] == key) {
					for (int j = i; j < last; j++)
						A[j] = A[j + 1];
					last--;
				}
			return true;
		}
		return false;
	}

};

