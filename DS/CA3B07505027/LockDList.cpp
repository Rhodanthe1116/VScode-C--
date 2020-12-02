#include <iostream>
#include "LockDList.h"
using namespace std;

template <typename T>
DListNode<T> *LockDList<T>::newNode(const T &item,
								DListNode<T> *prev, DListNode<T> *next)
{
	return new LockDListNode<T>(item, prev, next);
}

template <typename T>
void LockDList<T>::remove(DListNode<T> *node)
{
	// Your solution here.
	LockDListNode<T>* lockNode = (LockDListNode<T>*)node;
	if (lockNode->isLocked)
		return;
	DList<T>::remove(node);

}

template <typename T>
void LockDList<T>::lockNode(DListNode<T> *node)
{
	LockDListNode<T>* lockNode = (LockDListNode<T>*)node;
	lockNode->isLocked = true;
};