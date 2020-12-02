/**
 *  A LockDListNode is a node in a DList which can be locked
 */

#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

template<typename T>
class LockDList;

template<typename T>
class LockDListNode : public DListNode<T>
{
protected:
    friend class LockDList<T>;
    bool isLocked = 0;

public:
    LockDListNode(const T &i, DListNode<T> *p, DListNode<T> *n);
};

#endif
