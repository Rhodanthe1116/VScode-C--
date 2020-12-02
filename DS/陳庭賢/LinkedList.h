#pragma once
#include <iostream>
#include "Entry.h"
#include<list>
using namespace std;
template<typename T>
class LinkedList;
template<typename T> 
class ListNode {
private:
	T data;
	ListNode<T> *next;
public:
	ListNode() { data = 0; next = NULL; }
	ListNode(const T &a) { data = a; next = NULL; }
	friend class LinkedList<T>;
};


template<typename T>
class LinkedList {
private:
	ListNode<T> *first;
public:
	LinkedList() { first = NULL; }
	void printList();
	void push(const T &item);
	void remove();
	void clear();
};
