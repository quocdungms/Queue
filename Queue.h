#pragma once
#include "List.h"

template <class T>
class Queue : public List<T>
{
protected:
	List<T>* list;
	int capacity = 1000;
public:
	Queue(int capacity)
	{
		this->capacity = capacity;
		this->list = new List<T>();
	}
	Queue() {
		this->list = new List<T>();
	}
	~Queue()
	{
		this->list->destroy();
	}
	
	void clear();
	int size();
	bool empty();
	bool full();
	void push(const T& item);
	void push_front(const T& item);
	T front();
	T back();
	void pop();
	void print();

};

template <class T>
void Queue<T>::clear()
{
	this->list->clear();
}

template <class T>
int Queue<T>::size() {
	return (int)this->list->size();
}

template <class T>
bool Queue<T>::empty()
{
	return this->list->empty();
}

template <class T>
bool Queue<T>::full()
{
	return this->list->size() == this->capacity;
}

template <class T>
void Queue<T>::push(const T& item)
{
	if (this->full()) {
		printf("Queue overflow!\n");
		return;
	}
	else
	{
		this->list->add(item);
	}
}

template <class T>
void Queue<T>::push_front(const T& item)
{
	if (this->full()) {
		printf("Queue overflow!\n");
		return;
	}
	else
	{
		this->list->insert(0, item);
	}
}

template <class T>
T Queue<T>::front()
{
	if (this->list->empty()) {
		printf("Queue is empty!\n");
		return -1;
	}
	else
	{
		return this->list->get(0);
	}
}

template <class T>
T Queue<T>::back()
{
	if (this->empty()) {
		printf("Queue is empty!\n");
		return -1;
	}
	else
	{
		int back = (int)this->size() - 1;
		return this->list->get(back);
	}
	
}

template <class T>
void Queue<T>::pop()
{
	if (this->empty()) {
		printf("Queue underflow!\n");
		return;
	}
	else
	{
		this->list->removeAt(0);
	}
	
}

template <class T>
void Queue<T>::print()
{
	printf("==================== Queue ====================\n");
	printf("Capacity: %d, Size: %d\n", this->capacity, (int)this->size());
	printf("-----------------------------------------------\n");
	if (this->empty()) {
		printf("Queue is empty!\n");
	}
	else
	{
		printf("Front: %s\n", this->list->toString().c_str());
	}
	
	printf("===============================================\n");
}
