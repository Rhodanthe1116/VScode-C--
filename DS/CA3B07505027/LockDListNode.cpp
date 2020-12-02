/**
 *  A LockDListNode is a node in a DList which can be locked
 */

#include "LockDListNode.h"

template <typename T>
LockDListNode<T>::LockDListNode(const T &i, DListNode<T> *p, DListNode<T> *n) : DListNode<T>::DListNode(i, p, n){};
