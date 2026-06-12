#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList {

private:
	int _Size = 0;

	
public:
	class Node {
	public:
		T value;
		Node* Next;
		Node* Previous;

		Node(T value) : value(value), Next(nullptr), Previous(nullptr) {}

	};

	Node* Head = nullptr;

	~clsDblLinkedList() {
		Node* temp = nullptr;
		while (Head) {
			temp = Head;
			Head = Head->Next;
			delete temp;
		}
	}

	void Print() {
		Node* Current = Head;
		while (Current) {
			cout << Current->value << " ";
			Current = Current->Next;
		}
		cout << endl;
	}
	Node* Find(T value) {

		Node* Current = Head;
		
		while (Current) {
			if (Current->value == value) {
				return Current;
			}
			Current = Current->Next;
		}
		return nullptr;
	}

	void InsertAtBeginning(T value) {
		Node* newNode = new Node(value);

		if (Head) {
			Head->Previous = newNode;
		}
		newNode->Next = Head;
		Head = newNode;
		_Size++;
	}

	void InsertAtEnd(T value) {
		Node* newNode = new Node(value);

		if (!Head) {
			Head = newNode;
			_Size++;
			return;
		}

		Node* Current = Head;

		while (Current->Next) {
			Current = Current->Next;
		}

		Current->Next = newNode;
		newNode->Previous = Current;
		_Size++;
	}
	
	void InsertAfter(Node* OriginalNode, T value) {
		
	
		
		if (!OriginalNode)
			return;

		Node* newNode = new Node(value);

		newNode->Previous = OriginalNode;
		newNode->Next = OriginalNode->Next;
		
		if (OriginalNode->Next) {
			OriginalNode->Next->Previous = newNode;

		}

		OriginalNode->Next = newNode;
		_Size++;
	}

	void DeleteNode(Node* NodeToDelete) {

		if (!Head || !NodeToDelete)
			return;

		if (Head == NodeToDelete) {

			Head = Head->Next;

			if (Head)
				Head->Previous = nullptr;
		}
		else {

			NodeToDelete->Previous->Next = NodeToDelete->Next;

			if (NodeToDelete->Next)
				NodeToDelete->Next->Previous = NodeToDelete->Previous;
		}
		_Size--;
		delete NodeToDelete;
	}

	void DeleteFirstNode() {

		if (!Head)
			return;

		Node* temp = Head;
		Head = Head->Next;
		
		if (Head)
			Head->Previous = nullptr;
		_Size--;
		delete temp;
	}

	void Reverse() {

		Node* Current = Head;
		Node* temp = nullptr;

		while (Current) {
			temp = Current->Previous;
			Current->Previous = Current->Next;
			Current->Next = temp;
			Head = Current;
			Current = Current->Previous;

		}

	}

	Node* GetNode(int index) {

		if (index > _Size - 1 || index <0) {
			return nullptr;
		}
	
		Node* temp = Head;
		
		for (int i = 0; i < index; i++) {
			temp = temp->Next;
		}
		return temp;
	}

	T getItem(int index) {

		Node* ItemNode = GetNode(index);

		return ItemNode ? ItemNode->value : T();
	}

	bool UpdateItem(int index, T value) {

		Node* ItemNode = GetNode(index);
		
		return ItemNode ? (ItemNode->value = value, true) : false;

	}
	  
	int Size() {

		return _Size;
	}
	void DeleteLastNode() {
		if (!Head)
			return;

		if (!Head->Next) {
			delete Head;
			Head = nullptr;
			_Size--;
			return;
		}

		Node* temp = Head;

		while (temp->Next) {
			temp = temp->Next;
		}

		temp->Previous->Next = nullptr;
		delete temp;
		_Size--;
	}
	void clear() {
		Node* temp = nullptr;
		while (Head) {
			temp = Head;
			Head = Head->Next;
			delete temp;
		}
		_Size = 0;
	}
	bool isEmpty() {
		return (!Head);
	}
};