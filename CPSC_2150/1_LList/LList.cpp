#include "LList.h"
#include <iostream>
//#include <limits>
//#include <ios>

LList::LList(){
	list = nullptr;
}

bool LList::isEmpty(){
	return (list == nullptr);
}

int LList::length(){
	int ret = 0;
	Node* head = list;
	while(head != nullptr){
		ret++;
		head = head ->next;
	}
	return ret;
}

LList::Node* LList::cons(char x, Node* p){
   return new Node{x, p};
}

bool LList::append(char a){
	return append(a,list);
}

bool LList::append(char a, Node* head){
	if (length() == 0){
		list = cons(a, nullptr);
		return true;
	}
	if(head-> next == nullptr){
		head->next = cons(a,nullptr);
		return true;
	}
	else{
		return true && append(a,head->next);
	}
}

bool LList::remove(char a){
	if (list != nullptr && list->next != nullptr){
		if (list->info != a)
			return remove(a, list->next, list);
		else{
			Node* tmp = list;
			list = list->next;
			delete tmp;
			tmp = nullptr;
			return true;
		}
			
	}else{
		if(list != nullptr && list->info == a){
			delete list;
			list = nullptr;
			return true;
		}else{
			return false;
		}
	}
}

bool LList::remove(char a, Node* head, Node* previous){
	if( head == nullptr ){
		return false;
	}
	//std::cout << "... "<< head->info << " " << (head -> info == a) << std::endl;
	if( head -> info == a){
		Node* tmp = head->next;
		previous -> next = tmp;
		delete head;
		head = nullptr;
		return true;
	}else {
		return remove(a, head->next, head);
	}
}

bool LList::search(char a){
	return search(a, list);
}

bool LList::search(char a, Node* head){
	if(head == nullptr){
		return false;
	}else if(head->info == a){
		return true;
	}else{
		return search(a,head->next);
	}
}

char LList::getFirst(){
	if(list != nullptr) return list->info;
	else return '\0';
}
	

void LList::printList(std::ostream& fout) {
   printList(fout, list);
}

void LList::reverse(){
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
		
		
		
		
	
void LList::printList(std::ostream& fout, Node* p) {
   fout << "[ ";
   while (p != nullptr){
      fout << p -> info;
      if (p->next != nullptr)
	      fout << ", ";
      p = p -> next;
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