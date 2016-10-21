/*
 * Deque.h
 *
 *  Created on: Oct 20, 2016
 *      Author: sali09
 */

struct Node{
	int key;
	Node* next;
};

class Deque{
	public:
		Deque();
		Node* cons(int key, Node* next);
		bool isEmpty();
		void pushFront();
		void pushBack();
		Node* popFront();
		Node* popBack();
		Node* peekfront();
		Node* peekback();
		void clear();
		int size();
	private:
		Node* head;
		Node* tail;
}


