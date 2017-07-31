#include "DoublyLinkedList.h"


int main(){
	Node<char>* a = new Node<char>; //creates an empty node with no value
	genDLLaz(a);
	Node<char>* b = new Node<char>; //creates an empty node with no value
	genDLLaz(b);
	Node<char>* c = new Node<char>; //creates an empty node with no value
	genDLLaz(c);
	Node<char>* d = new Node<char>; //creates an empty node with no value
	genDLLaz(d);
	
	cout << "file" << " | " << "move-to-front"<< " | " << "count" << endl;
	cout << "normal.txt" << " | " << findmtf(a,"normal.txt") << " | " << findcnt(b,"normal.txt") << endl;
	cout << "repeated.txt" << " | " << findmtf(c,"repeated.txt") << " | " << findcnt(d,"repeated.txt") << endl;
	
	
	/*Node<char>* e = new Node<char>; //creates an empty node with no value
	genDLLaz(e);
	
	findtrnsp(e,"normal.txt");
	*/
	//printList(a); // print a and everything to the left
}