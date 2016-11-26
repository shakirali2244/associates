/*
 * Deque.cpp
 *
 *  Created on: Oct 20, 2016
 *      Author: sali09
 */
#include "Deque.h"
#include <iostream>

using namespace std;

// new helper for Node*
//precondition:
// -
//postcondition:
// creates a new node with passed params
Node* Deque::cons(int key, Node* next){
	return new Node{key, next};
}

// constructor
//precondition:
// -
//postcondition:
// creates an empty deque
Deque::Deque(){
	head = nullptr;
	tail = nullptr;
}

// destructor
//precondition:
// -
//postcondition:
// calls clear()
Deque::~Deque(){
	clear();
}

// copy constructor
//precondition:
// in is not null reference
//postcondition:
// calls recursive copier to create deep copy of linked list
Deque::Deque(const Deque &in){
	head = copyRecursiveHelper(in.head);

	//special case if in is empty take care of tail
	if(in.head == nullptr){
		tail = nullptr;
	}
}
	
// empty checker
//precondition:
// -
//postcondition:
// returns bool if empty or not
bool Deque::isEmpty(){
	return (head==nullptr);
}

// pushes key to front of the deque
//precondition:
// -
//postcondition:
// pushes and updates tail and head
void Deque::pushFront(int key){
	Node* tmp = cons(key, head);
	head = tmp;
	//update tail special case
	if (size() == 1){
		tail = tmp;
	}
}

// pushes key to back of the deque
//precondition:
// -
//postcondition:
// pushes and updates tail and head
void Deque::pushBack(int key){
	Node* tmp = cons(key, nullptr);
	if(isEmpty()){
		tail = tmp;
		head = tmp;
	}else{
		tail->next = tmp; //connect last to new
		tail = tmp; //new is tail now
	}
}

// pops key from front of the deque
//precondition:
// -
//postcondition:
// pops and updates  head or throws
Node* Deque::popFront(){
	if(isEmpty()){
		throw "INVALID expression, Not enough numbers";
		return head;
	}
	Node* tmp = head;
	head = head->next; //update head
	return tmp;
}

// pops key from back of the deque
//precondition:
// -
//postcondition:
// pops and updates head and/or tail or throws
Node* Deque::popBack(){
	if(isEmpty()){
		throw "INVALID expression, Not enough numbers";
		return head;
	}
	//special case
	if(size() == 1){
		Node* tmp = head;
		head = nullptr;
		tail = nullptr;
		return tmp;
	}	

	//get previous to tail
	Node* tmp1 = head;
	while(tmp1->next != tail){
		tmp1 = tmp1->next;
	}
	Node* tmp = tmp1->next;
	tmp1->next = nullptr;	//unlink
	tail = tmp1; //update tail
	return tmp;
}

// peeks at key at the front of the deque
//precondition:
// -
//postcondition:
// peeks or throws
Node* Deque::peekFront(){
	if(head == nullptr){
		throw "INVALID expression, Not enough numbers";
	}
	return head;
}

// peeks at key at the back of the deque
//precondition:
// -
//postcondition:
// peeks or throws
Node* Deque::peekBack(){
	if(tail == nullptr){
		throw "INVALID expression, Not enough numbers";
	}
	return tail;
}

// frees up memory
//precondition:
// -
//postcondition:
//deletes every node from the linked list
void Deque::clear(){
	if (head == nullptr){
		return;
	}
	//special case
	if(size() == 1){
		Node* tmp = head;
		head = nullptr;
		tail = nullptr;
		delete tmp;
	}
	
	//clean linked list
	Node* tmp = head;
	while(tmp != nullptr){
		Node* nxt = tmp->next;
		delete tmp;
		tmp = nxt;
	}
	head = nullptr;
	tail = nullptr;
	
}


// size checker for deque
//precondition:
// -
//postcondition:
// returns size for deque
int Deque::size(){
	if(isEmpty()){
		return 0;
	}
	int ret = 0;
	Node* tmp = head; //treverser
	while(tmp !=nullptr){
		ret++;
		tmp = tmp->next;
	}
	return ret;
}

// accessor for head
//precondition:
// -
//postcondition:
// retruns reference to head
Node* Deque::getHead(){
	return head;
}


// recursive helper 
//precondition:
// -
//postcondition:
// copies linked list starting from in to head and retruns head
Node* Deque::copyRecursiveHelper(Node* in){
	if ( in == nullptr ){ //base case
		return in;
	}
	if (in->next == nullptr){ //take care of tail
		tail = in;
	}
	Node* head =  cons( in->key,copyRecursiveHelper( in->next )); //recursion
	return head;
}

// assignment operator overloaded
//precondition:
// B is not null
//postcondition:
// copies the list from b on self
Deque& Deque::operator =(const Deque B){
	if(this == &B){
		return *this; //check a = a;
	}
	clear(); //empty current deque 
	head = copyRecursiveHelper(B.head);
	return *this;
}




