
#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "LockDListNode.h"

template <typename T>
class LockDList : public DList<T>
{
protected:
	DListNode<T> *newNode(const T &item, DListNode<T> *prev,
								  		DListNode<T> *next);
public:
	void remove(DListNode<T> *node);
	void lockNode(DListNode<T> *node);

};

#endif
