#pragma once
class Node
{
public:
	int data;
	Node* next,*prev;
public:
	Node() { next = nullptr; }
	Node(int x) {
		data = x;
		next = nullptr;
		prev = NULL;
	}
};

