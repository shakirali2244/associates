#include "DoublyLinkedList.h"


int main(){
	Node<int>* a = new Node<int>; //creates an empty node with no value
	genDLL(10,a); // fill up a to the left
	printList(a); // print a and everything to the left
}