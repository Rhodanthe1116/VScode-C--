#include"LinkedList.h"

template<typename T> 
void LinkedList<T>::printList()
{
	if (first == 0) {               
		cout << "List is empty.\n";
		return;
	}
	ListNode<T>* current = first;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
template<typename T>
void LinkedList<T>::push(const T &item)
{
	ListNode<T> *new_node = new ListNode<T>(item);
	if (first == 0) {       
		first = new_node;
		return;
	}
	ListNode<T>* current = first;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

template<typename T>
void LinkedList<T>::remove()
{
	if (first == 0) {
	}
	ListNode<T>* current = first, *prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
}

template<typename T>
void LinkedList<T>::clear()
{
	first->next = NULL;
}
