#include <iostream>
const int NULLPOINTER = -1;
class Array{
	private:
		struct Node{
			char item;
			int next;
		};
		Node* list;
		int head;
		int index;
		int free;

	public:
		Array();
		bool isEmpty();
		int length();
		bool cons(char x);
		void shift(int in, char x);
		bool append(char a);
		bool remove(char a);
		void addtoFree(int index);
		bool search(char a);
		char getFirst();
		//void reverse();
		void printList(std::ostream& fout);
		//void printList(std::ostream& fout, Node* p);

		/*
		Node* cons(int x, Node* p);
		void readList(std::istream& fin);
		Node* readBackwardList(std::istream& fin);
		void deleteList(Node* &p);
		void printList(std::ostream& fout);
		void printList(std::ostream& fout, Node* p);
		*/
};
