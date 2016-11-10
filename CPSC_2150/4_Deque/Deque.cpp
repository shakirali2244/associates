/*
 * Deque.cpp
 *
 *  Created on: Oct 20, 2016
 *      Author: sali09
 */
#include "Deque.h"


Node* Deque::cons(int key, Node* next){
	return new Node{key, next};
}

Deque::Deque(){
	head = nullptr;
	tail = nullptr;
}
bool Deque::isEmpty(){
	return (head==nullptr);
}
void Deque::pushFront(int key){
	Node* tmp = cons(key, head);
	head = tmp;
	if (size() == 1){
		tail = tmp;
	}
}
void Deque::pushBack(int key){
	Node* tmp = cons(key, nullptr);
	if(isEmpty()){
		tail = tmp;
		head = tmp;
	}else{
		tail->next = tmp;
	}
}
Node* Deque::popFront(){
	if(isEmpty()){
		throw "empty";
		return head;
	}
	Node* tmp = head;
	head = head->next;
	return tmp;

}

Node* Deque::popBack(){
	if(isEmpty()){
		throw "empty";
		return head;
	}
	Node* tmp = tail;
	head = head->next;
	return tmp;
}
Node* Deque::peekfront(){
	return head;
}
Node* Deque::peekback(){
	return tail;
}
void Deque::clear(){
	if (head == nullptr){
		return;
	}
	if(size() == 1){
		Node* tmp = head;
		head = nullptr;
		tail = nullptr;
		delete tmp;
	}
	while(head != tail && head != nullptr){
		Node* tmp = head;
		delete tmp;
		tmp = head->next;
	}
}
int Deque::size(){
	if(isEmpty()){
		return 0;
	}
	int ret = 0;
	Node* tmp = head;
	while(head->next!=nullptr){
		ret++;
	}
	return ret;

}



