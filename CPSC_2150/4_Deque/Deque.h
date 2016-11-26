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
		// constructor
		//precondition:
		// -
		//postcondition:
		// creates an empty deque
		Deque();

		// copy constructor
		//precondition:
		// in is not null reference
		//postcondition:
		// calls recursive copier to create deep copy of linked list
		Deque(const Deque &in);

		// destructor
		//precondition:
		// -
		//postcondition:
		// calls clear()
		~Deque();

		// new helper for Node*
		//precondition:
		// -
		//postcondition:
		// creates a new node with passed params
		Node* cons(int key, Node* next);

		// empty checker
		//precondition:
		// -
		//postcondition:
		// returns bool if empty or not
		bool isEmpty();

		// pushes key to front of the deque
		//precondition:
		// -
		//postcondition:
		// pushes and updates tail and head 
		void pushFront(int key);

		// pushes key to back of the deque
		//precondition:
		// -
		//postcondition:
		// pushes and updates tail and head
		void pushBack(int key);

		// pops key from front of the deque
		//precondition:
		// -
		//postcondition:
		// pops and updates head or throws
		Node* popFront();
		
		// pops key from back of the deque
		//precondition:
		// -
		//postcondition:
		// pops and updates head and/or tail or throws
		Node* popBack();

		// peeks at key at the front of the deque
		//precondition:
		// -
		//postcondition:
		// peeks or throws
		Node* peekFront();

		// peeks at key at the back of the deque
		//precondition:
		// -
		//postcondition:
		// peeks or throws
		Node* peekBack();

		// accessor for head
		//precondition:
		// -
		//postcondition:
		// retruns reference to head
		Node* getHead();

		// recursive helper 
		//precondition:
		// -
		//postcondition:
		// copies linked list starting from in to head and retruns head
		Node* copyRecursiveHelper(Node* in);

		// frees up memory
		//precondition:
		// -
		//postcondition:
		//deletes every node from the linked list
		void clear();

		// size checker for deque
		//precondition:
		// -
		//postcondition:
		// returns size for deque
		int size();

		// assignment operator overloaded
		//precondition:
		// B is not null
		//postcondition:
		// copies the list from b on self
		Deque& operator =(const Deque B);
	private:
		Node* head;
		Node* tail;
};


