#include "Array.h"

#include <iostream>
//#include <limits>
//#include <ios>
using namespace std;
Array::Array(){
	index = 0;
	head = 0;
	free = NULLPOINTER;
	list = new Node[9999];
	list[index] = Node {'\0', NULLPOINTER};
}

bool Array::isEmpty(){
	return (list == nullptr);
}

int Array::length(){
	int ret = 0;
	int i = 0;
	while(i != NULLPOINTER){
		ret++;
		i = list[i].next;
	}
	return ret;
}

bool Array::cons(char x){
	if ((length() <=1 && list[head].item == '\0') || head == NULLPOINTER){
		if (head == NULLPOINTER){
			head++;
		}
		list[head] = Node{x, NULLPOINTER};
		index++;
		return true;
	}
	if (free < head && free != NULLPOINTER){
		int tmp = free;
		free = list[free].next;
		cout << "free , head " << free << head << endl;
		list[tmp] = Node{x, head};
		head = tmp;
	}else{
		int curr = head;
		shift(head,x);
		return true;
	}
}
/*
	if(free != NULLPOINTER && free != 0){
		int tmp = free;
		free = list[free].next;
		list[tmp].item = x;
		int tmp2= list[tmp-1].next;
		list[tmp-1].next = tmp;
		list[tmp].next = tmp2;
		return true;
	}else if (free == 0){
		int tmp = free;
		free = list[free].next;
		list[tmp].item = x;
		list[tmp].next = head;
		head = tmp;
*/
void Array::shift(int in, char x){
	if (list[in].next == NULLPOINTER){
		list[in].next = index;
		char tmp = list[in].item;
		list[in].item = x;
		list[index] = Node{tmp , NULLPOINTER};
		index++;
		return;
	}
	if (in+1 == free){
		char tmpC = list[in].item;
		char nxt = list[in].next;
		list[in].next = in+1;
		list[in].item = x;
		free = list[free].next;
		list[in+1].item = tmpC;
		list[in+1].next = nxt;
		return;
	}
	char tmp = list[in].item;
	cout << tmp  << endl ;
	list[in].item = x;
	shift(list[in].next,tmp);
}
	
	

bool Array::append(char a){
	if ( a == '\0'){
		return false;
	}
	if ((length() <=1 && list[head].item == '\0') || head == NULLPOINTER){
		if (head == NULLPOINTER){
			head++;
		}
		free =  NULLPOINTER;
		list[head] = Node{a, NULLPOINTER};
		index++;
		return true;
	}else{
		list[index] = Node {a,NULLPOINTER};
		int tmp = head;
		while(list[tmp].next != NULLPOINTER){
			tmp = list[tmp].next;
		}
		list[tmp].next = index;
		index++;
		return true;
	}
}

/*bool Array::append(char a, Node* head){
	if(head-> next == nullptr){
		head->next = cons(a,nullptr);
		return true;
	}
	else{
		return true && append(a,head->next);
	}
}*/

bool Array::remove(char a){
	if(a == '\0'){
		return false;
	}
	if (length() == 0){
		return false;
	}
	int i = head;
	while(i != NULLPOINTER){
		if (list[i].item == a){			
			int j = i;
			if (i == head){
				int tmp = head;
				head = list[head].next;
				list[tmp].item = '\0';
				list[tmp].next = NULLPOINTER;
				addtoFree(tmp);
				return true;
			}else{
				int tmp = list[i].next;
				while (j >=0){
					if(list[j].next == i){
						list[j].next = tmp;
						break;
					}
					j--;
				}
				list[i].item = '\0';
				list[i].next = NULLPOINTER;
				addtoFree(i);
				return true;
			}
		}
		i = list[i].next;
	}
	return false;
}

void Array::addtoFree(int index){
	if(free == NULLPOINTER){
		free = index;
		return;
	}
	if (index < free){
		list[index].next = free;
		free = index;
	}else{
		int prev = free;
		int curr = list[free].next;
		bool spotFound = false;
		while(curr != NULLPOINTER){
			if(index < curr){
				list[prev].next = index;
				list[index].next = curr;
				spotFound = true;
				break;
			}
			prev = curr;
			curr = list[curr].next;
		}
		if(!spotFound){
			list[prev].next = index;
		}
	}
	return;
}
				

/*bool Array::remove(char a, Node* head, Node* previous){
	if( head == nullptr ){
		return false;
	}
	//std::cout << "... "<< head->info << " " << (head -> info == a) << std::endl;
	if(head -> item == a){
		Node* tmp = head->next;
		previous -> next = tmp;
		delete head;
		head = nullptr;
		return true;
	}else {
		return remove(a, head->next, head);
	}
}
*/

void Array::reverse(){
	if (length() <= 1) return;
	if (length() == 2){
		Node* tmp = list;
		list = list->next;
		list->next = tmp;
		return;
		char tmp = list[head].item;
		head = list[head].next;
	}
	
	Node* previous = list;
	Node* head = previous -> next;
	Node* front= head->next;
	
	previous->next = nullptr;
	while(head->next != nullptr){
		head->next = previous;
		Node* tmp = front->next;
		front->next = head; 
		previous = head;
		head = front;
		front = tmp;
	}
	list = head;
	return;
}

bool Array::search(char a){
	if (a == '\0'){
		return false;
	}
	int i = head;
	while(i != NULLPOINTER){
		if( a == list[i].item ){
			return true;
		}
		//cout << list[i].item << endl;
		i = list[i].next;
	}
	return false;
}
/*bool Array::search(char a, Node* head){
	if(head == nullptr){
		return false;
	}else if(head->item == a){
		return true;
	}else{
		return search(a,head->next);
	}
}*/

char Array::getFirst(){
	return list[head].item;
}
 /*
void Array::printList(std::ostream& fout) {
	#ifndef NDEBUG
	printList(fout, list);
	#endif
}*/
/*
void Array::'\0'(){
	if (length() <= 1) return;
	if (length() == 2){
		Node* tmp = list;
		list = list->next;
		list->next = tmp;
		return;
	}
	
	Node* previous = list;
	Node* head = previous -> next;
	Node* front= head->next;
	
	previous->next = nullptr;
	while(head->next != nullptr){
		head->next = previous;
		Node* tmp = front->next;
		front->next = head; 
		previous = head;
		head = front;
		front = tmp;
	}
	list = head;
	return;
}
*/	
void Array::printList(std::ostream& fout) {
	fout << "[ ";
	int tmp = head;
	while (tmp != NULLPOINTER){
		fout << "{"<<tmp<<"}" <<  list[tmp].item ;
		if (list[tmp].next != NULLPOINTER)
		      fout << ", ";
		tmp = list[tmp].next;
	}
	fout << " ]\n";
	fout << " Free indices [ ";
	tmp = free;
	while (tmp != NULLPOINTER){
		fout << tmp; 
		if (list[tmp].next != NULLPOINTER)
		      fout << ", ";
		tmp = list[tmp].next;
	}
	fout << " ]\n";
	
}
	
		

/*

CList::Node* CList::cons(int x, Node* p){
   return new Node{x, p};
}

void CList::readList(std::istream& fin){
   //deleteList(list);
   list = readBackwardList(fin);
}

CList::Node* CList::readBackwardList(std::istream& fin) {
   Node* p = nullptr;
   Node *tail = p;
   int x;
   while(fin >> x){
      p = cons(x, p);
      if (tail == nullptr){
         tail = p;
      }
   }
   tail->next = p;
   //reset the stream out of fail state
   fin.clear();
   //consume characters encountered to the end of the line
   fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   return p;
}

void CList::printList(std::ostream& fout) {
   printList(fout, list);
}
void CList::printList(std::ostream& fout, Node* p) {
   fout << "[ ";
   p = p->next;
   while (p != list){
      fout << p -> info << " ";
      p = p -> next;
   }
   fout << " ]\n";
}


void CList::deleteList(Node* &p){
   std::cerr << "\n  HUMONGOUS MEMORY LEAK -- worth failing the lab \n";
   p = nullptr;
}
*/
