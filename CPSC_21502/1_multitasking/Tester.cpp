#include "List.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	Node* a = new Node;
	Node* tail = a;
	
	
	cout << "receiving ";
	Queue(tail,800);
	cout << "P1(800) " ;
	printList(a);
	
	int finished = 0;
	int added = 0;
	
	int n = 7;
	int init = 1;
	
	while (n >0){
		
		int probab = (rand() % 4) + 1;
		//cout << probab << endl;
		
		if (probab != 1){
			cout << init<< " processing ";
			Node* q = Deque(a);
			cout << "P"<<q->name<<"("<<q->val<<") ";
			q->val -= 100;
			if(q->val != 0){
				Queue(tail,a,q);
				printList(a);
			}else{
				finished++;
			}
			init++;
			n--;
			
		}else{
			cout << "receiving ";
			int time = rand() % 5 + 1;
			Queue(tail,time*100);
			cout << "P" << tail ->name << "(" << tail->val << ") ";
			printList(a);
			added++;
		}
	}
	
	init --;
	cout << init << "slices," << added << " sent to CPU, " << finished << " terminated, " << getSize(tail) << "still in cpu " << endl;
	cout << (float)init/(float)(init + added)*(float)100 << " % of CPU time was spent processing jobs "<< endl;
	cout << (float)added/(float)(init + added)*(float)100 << " % of CPU time was spent on adding new jobs"<< endl;
	
			
	
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