#include <iostream>
#include "clsDblLinkedList.h"


using namespace std;

int main() {

	
	clsDblLinkedList<float> myList;

	myList.InsertAtBeginning(1);
	myList.InsertAtBeginning(2);
	myList.InsertAtBeginning(3);
	myList.InsertAtBeginning(4);
	myList.InsertAtBeginning(5);

	clsDblLinkedList<float>::Node* N1 = myList.Find(3);

	cout << (N1 ? "Found" : "Not Found") << endl;

	myList.Print();

	cout << "Inserting 3.5 after 3:" << endl;
	myList.InsertAfter(N1, 3.5);
	myList.Print();
	cout << "Inserting 0 at the end:" << endl;
	myList.InsertAtEnd(0);
	myList.Print();

	cout << "Deleting the 4 from the linked list" << endl;
	clsDblLinkedList<float>::Node* N2 = myList.Find(4);
	myList.DeleteNode(N2);
	myList.Print();

	cout << "The size of the linked list is: " << myList.Size() << endl;

	cout << "Is the list empty ? " << endl;

	cout << (myList.isEmpty() ? "Yes" : "No") << endl;

	
	cout << "The linked list before reverse: " << endl;
	myList.Print();
	cout << "The linked list after reverse: " << endl;
	myList.Reverse();
	myList.Print();

	clsDblLinkedList <float> ::Node* N3 = myList.GetNode(5);
	cout << (N3 ? "Found!" : "Not Found") << endl;
	cout << myList.getItem(3) << endl;

	cout << "Updating item at index 3 to 200: " << endl;
	myList.UpdateItem(3, 200);

	cout << "List after updating: " << endl;

	myList.Print();
	cout << "Executing Clear: " << endl;
	myList.clear();

	cout << "The size of the linked list is: " << myList.Size() << endl;
	return 0;
}