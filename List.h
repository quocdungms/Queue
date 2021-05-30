#pragma once
#include <iostream>
#include <string>

template <class T>
class List
{
public:
	class Node
	{
		friend class List;
	protected:
		T data;
		Node* next;
		Node* prev;
	public:
		Node() {
			this->data = INT32_MIN;
			this->next = nullptr;
			this->prev = nullptr;
		}
		Node(const T& data) {
			this->data = data;
			this->next = nullptr;
			this->prev = nullptr;
		}
	};

protected:
	Node* head;
	Node* tail;
	int count;
public:
	List() {
		this->count = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}
	~List() {
		this->destroy();
	}

	void clear();
	void destroy();
	int size();
	bool empty();
	bool add(const T& item);
	bool insert(int index, const T& item);
	void deleteNode(Node* node);
	bool remove(const T& item);
	T removeAt(int index);
	int search(const T& item);
	T get(int index);
	std::string toString();
	void printList();
	void printDetail();
};

template <class T>
void List<T>::clear()
{
	Node* current = this->head;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->count = 0;
}

template <class T>
void List<T>::destroy()
{
	this->clear();
	delete head;
	delete tail;
}

template <class T>
int List<T>::size()
{
	return this->count;
}

template <class T>
bool List<T>::empty()
{
	return this->count == 0;
}

template <class T>
bool List<T>::add(const T& item)
{
	if (this->empty()) {
		Node* temp = new Node(item);
		this->count++;
		this->head = this->tail = temp;
		return true;
	}
	else
	{
		Node* temp = new Node(item);
		this->count++;
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		return true;
	}
	return false;
}

template <class T>
bool List<T>::insert(int index, const T& item)
{
	if (index < 0 || index > this->count) {
		return false;
	}

	if (index == 0) {
		if (this->empty()) {
			return this->add(item);
		}
		else
		{
			Node* temp = new Node(item);
			this->count++;
			temp->next = this->head;
			this->head->prev = temp;
			this->head = temp;
			return true;
		}
	}
	else if (index == this->count) {
		Node* temp = new Node(item);
		this->count++;
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
		return true;
	}
	else
	{
		Node* current = this->head;
		Node* prev = nullptr;
		int pos = 0;
		while (current != nullptr)
		{
			if (index == pos) {
				Node* temp = new Node(item);
				this->count++;
				prev->next = temp;
				temp->prev = prev;
				temp->next = current;
				current->prev = temp;
				return true;
			}
			pos++;
			prev = current;
			current = current->next;
		}
		return false;
	}
}


template <class T>
void List<T>::deleteNode(Node* node)
{
	if (node == nullptr) {
		return;
	}
	else
	{
		Node* next = node->next;
		Node* prev = node->prev;
		if (prev == nullptr) {
			if (next == nullptr) {
				this->clear();
			}
			else
			{
				next->prev = prev;
				delete this->head;
				this->head = next;
				this->count--;
			}
		}
		else
		{
			if (next == nullptr) {
				prev->next = next;
				delete this->tail;
				this->tail = prev;
				this->count--;
			}
			else
			{
				prev->next = next;
				next->prev = prev;
				delete node;
				this->count--;
			}
		}
	}
}


template <class T>
bool List<T>::remove(const T& item)
{
	if (this->empty()) {
		return false;
	}
	else
	{
		Node* current = this->head;
		while (current != nullptr)
		{
			if (current->data == item)
			{
				this->deleteNode(current);
				return true;
			}
			current = current->next;
		}
		return false;
	}
}

template <class T>
T List<T>::removeAt(int index)
{
	if (index < 0 || index >= this->count || this->empty() == true)
	{
		return -1;
	}
	else
	{
		int pos = 0;
		Node* current = this->head;
		while (current != nullptr)
		{
			if (index == pos) {
				Node* ans = new Node(current->data);
				this->deleteNode(current);
				return ans->data;
			}
			pos++;
			current = current->next;
		}
		return -1;
	}
}

template <class T>
int List<T>::search(const T& item)
{
	if (this->empty()) {
		return -1;
	}
	else
	{
		Node* current = this->head;
		int pos = 0;
		while (current != nullptr)
		{
			if (current->data == item) {
				return pos;
			}
			pos++;
			current = current->next;
		}
		return -1;
	}
}

template <class T>
T List<T>::get(int index)
{
	if (index < 0 || index >= this->count || this->empty()) {
		return -1;
	}

	Node* current = this->head;
	int pos = 0;
	while (current != nullptr)
	{
		if (index == pos)
		{
			return current->data;
		}
		pos++;
		current = current->next;
	}
	return -1;
}

template <class T>
std::string List<T>::toString()
{
	std::string list = "";
	if (this->empty()) {
		list = "List is empty!\n";
		return list;
	}
	else
	{
		Node* current = this->head;
		while (current != nullptr)
		{
			if (current == tail) {
				list += std::to_string(current->data);
			}
			else
			{
				list += std::to_string(current->data) + ' ';
			}
			current = current->next;
		}
		return list;
	}
}

template <class T>
void List<T>::printList()
{
	printf("================= List =================\n");
	printf("Size: %d\n", this->count);
	printf("----------------------------------------\n");
	printf("%s", this->toString().c_str());
	printf("========================================\n");

}

template <class T>
void List<T>::printDetail()
{
	printf("===================== List =======================\n");
	printf("Size: %d\n", this->count);
	printf("--------------------------------------------------\n");
	if (this->empty()) {
		printf("List is empty!\n");
	}
	else
	{
		Node* p = this->head;
		printf(" Index || Data ||   prev   |  current |   next   |\n");
		int index = 0;
		while (p != nullptr)
		{
			printf(" %5d || %4d || %8d | %8d | %8d |\n", index, (int)p->data, (int)p->prev, (int)p, (int)p->next);
			p = p->next;
			index++;
		}
	}
	printf("==================================================\n");

}