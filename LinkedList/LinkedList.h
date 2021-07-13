#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H
#include <iostream>
using namespace std;
template <typename T>
struct Node {
	T data;
	Node<T>* nextPtr;
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
	int len;
public:
	LinkedList();
	LinkedList(T data);
	void addHead(T data);
	void addTail(T data);
	void add(int index, T data);
	int size();
	Node<T>* node(int index);
	T search(int index);
	T popHead();
	T popTail();
	T pop(int index);
	template <typename S>
	friend ostream& operator<<(ostream& os, LinkedList<S>& L);
};

template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = head;
	len = 0;
}

template<typename T>
LinkedList<T>::LinkedList(T data)
{
	head = new Node<T>;
	head->data = data;
	head->nextPtr = nullptr;
	tail = head;
	len = 1;
}

template<typename T>
void LinkedList<T>::addHead(T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->nextPtr = head;
	newNode->data = data;
	head = newNode;	
	len++;
	if (!head->nextPtr)
		tail = head;
}

template<typename T>
void LinkedList<T>::addTail(T data)
{
	if (!len)
		addHead(data);
	else {
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	tail->nextPtr = newNode;
	tail = newNode;
	tail->nextPtr = nullptr;
	len++;
	}
}

template<typename T>
void LinkedList<T>::add(int index, T data)
{
	if (index == 0)
		addHead(data);
	else {
		Node<T>* pre = node(index - 1);
		Node<T>* temp = pre->nextPtr;
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		pre->nextPtr = newNode;
		newNode->nextPtr = temp;
		len++;
		if (!newNode->nextPtr)
			addTail(data);
	}
}

template<typename T>
int LinkedList<T>::size()
{
	return len;
}

template<typename T>
Node<T>* LinkedList<T>::node(int index)
{
	Node<T>* temp = head;
	for (int i = 0; i < index; i++)
		temp = temp->nextPtr;
	return temp;
}

template<typename T>
T LinkedList<T>::search(int index)
{
	Node<T>* temp = head;
	for (int i = 0; i < index; i++)
		temp = temp->nextPtr;
	return temp->data;
}

template<typename T>
T LinkedList<T>::popHead()
{
	if (len >= 0) {
		Node<T>* temp = head;
		head = head->nextPtr;
		T returnData = temp->data;
		delete temp;
		len--;
		return returnData;
	}
}

template<typename T>
T LinkedList<T>::popTail()
{
	return pop(len - 1);
}

template<typename T>
T LinkedList<T>::pop(int index)
{
	if (index == 0)
		popHead();
	else {
		Node<T>* pre = node(index - 1);
		Node<T>* temp = pre->nextPtr;
		Node<T>* next = temp->nextPtr;
		T returnData = temp->data;
		pre->nextPtr = next;
		delete temp;
		len--;
		return returnData;
	}
}

template<typename S>
ostream& operator<<(ostream& os, LinkedList<S>& L)
{
	Node<S>* temp = L.head;
	os << "< ";
	for (int i = 0; i < L.len - 1; i++) {
		os << temp->data << " | ";
		temp = temp->nextPtr;
	}
	os << temp->data << " >" << endl;
	return os;
}

#endif