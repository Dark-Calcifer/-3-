#pragma once 

template<typename W>
class Deque
{
public:
	Deque();
	~Deque();

	void pop_front();
	void push_back(W& Object);
	void clear();
	int size() { return Size; }
	W& operator[](const int index);
	void pop_back();

private:
	template<typename W>
	class Node
	{
	public:
		Node* pNext;
		W Object;

		Node(W& Object, Node* pNext = nullptr)
		{
			this->Object = Object;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<W>* head;
};


template<typename W>
Deque<W>::Deque()
{
	Size = 0;
	head = nullptr;
}

template<typename W>
Deque<W>::~Deque()
{
	clear();
}


template<typename W>
void Deque<W>::pop_front()
{
	Node<W>* temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename W>
void Deque<W>::push_back(W& const Object)
{
	Worker TEMP;
	TEMP = Object;
	if (head == nullptr)
	{
		head = new Node<W>(TEMP);
	}
	else
	{
		Node<W>* temp = this->head;

		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = new Node<W>(TEMP);
	}

	Size++;
}

template<typename W>
void Deque<W>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename W>
W& Deque<W>::operator[](const int index)
{
	int counter = 0;

	Node<W>* temp = this->head;

	while (temp != nullptr)
	{
		if (counter == index)
		{
			return temp->Object;
		}
		temp = temp->pNext;
		counter++;
	}
}

template<typename W>
void Deque<W>::pop_back()
{
	Node<W>* previous = this->head;
		for (int i = 0; i < Size - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<W>* toDelete = previous->pNext;

		previous->pNext = nullptr;

		delete toDelete;

		Size--;
}