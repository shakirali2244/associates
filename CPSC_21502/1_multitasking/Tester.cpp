#include "List.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	Node* a = new Node;
	Node* tail = a;
	
	
	cout << "receiving ";
	Queue(tail,800);
	cout << "P1(800)" ;
	printList(a);

	
	int n = 20;
	
	for (int i = 0; i < n; i++){
		
		int probab = (rand() % 4) + 1;
		cout << probab << endl;
		
		if (probab != 1){
			cout << "processing ";
			Node* q = Deque(a);
			cout << "P"<<q->name<<"("<<q->val<<") ";
			q->val -= 100;
			Queue(tail,q);
			printList(a);
		}else{
			cout << "receiving ";
			Queue(tail,800);
			cout << "P1(800)" ;
			printList(a);
		}
	}
			
	
	/*Queue(tail,400);
	Queue(tail,300);
	Queue(tail,400);
        Queue(tail,500);
	Queue(tail,800);
	
	printList(a);
	
	Node* q = Deque(a);
	Node* w = Deque(a);
	Node* e = Deque(a);
	Node* r = Deque(a);
	
	
	cout << q->val << endl;
	cout << w->val  << endl;
	cout << e->val  << endl;
	cout << r->val  << endl;
	
	printList(a);
	
	Queue(tail,q);
	Queue(tail,w);
	
	printList(a);
	
	Deque(a);Deque(a);
	
	printList(a);
	
	Deque(a);
	
	printList(a);
	*/
	
	
	
}