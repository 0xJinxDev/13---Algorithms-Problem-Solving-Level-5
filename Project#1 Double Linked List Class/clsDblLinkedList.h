#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDblLinkedList {


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
		Node* Current = Head;
		while (Current) {
			Node* Next = Current->Next;
			delete Current;
			Current = Next;
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
	}

	void InsertAtEnd(T value) {
		Node* newNode = new Node(value);

		if (!Head) {
			Head = newNode;
			return;
		}

		Node* Current = Head;

		while (Current->Next) {
			Current = Current->Next;
		}

		Current->Next = newNode;
		newNode->Previous = Current;
	}
	
	void InsertAfter(Node* OriginalNode, T value) {
		
		Node* newNode = new Node(value);
		
		if (!OriginalNode)
			return;


		newNode->Previous = OriginalNode;
		newNode->Next = OriginalNode->Next;
		
		if (OriginalNode->Next) {
			OriginalNode->Next->Previous = newNode;

		}

		OriginalNode->Next = newNode;


		
	}
};