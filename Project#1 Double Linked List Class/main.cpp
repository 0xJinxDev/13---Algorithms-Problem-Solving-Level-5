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


	return 0;
}