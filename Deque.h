#pragma once

template<typename T>
class Deque
{
private:
	template<typename T>
	class Node
	{
	public: 
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T>* head;

//-------------------------------------PUBLIC---------------------------------------

public:
	Deque();	
	~Deque();
	void push_back(T data);
	void pop_front();
	void pop_back();
	void clear();
	int GetSize() { return Size; }

	T& operator[](const int index);

};




template<typename T>
inline Deque<T>::Deque()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
inline Deque<T>::~Deque()
{
	clear();
}

template<typename T>
inline void Deque<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;	
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
inline void Deque<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
inline void Deque<T>::pop_back()
{
	if (head != nullptr)
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		delete current->pNext;
		Size--;
	}
}

template<typename T>
inline void Deque<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
inline T& Deque<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
