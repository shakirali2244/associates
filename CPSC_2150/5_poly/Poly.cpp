#include "Poly.h"
#include <iostream>
 using namespace std;


Poly::Poly(){
	head = nullptr;
}

Term* Poly::cons(int coeff, int x, int y, Term* next){
	return new Term{coeff,x,y, next};
}

Term* Poly::add(int coeff, int x, int y){
	Term* tmp = cons(coeff,x,y,head);
	head = tmp;
	return head;
}

int Poly::getSize(Term* input){
	if(input == nullptr){
		return 0;
	}
	int ret = 0;
	Term* tmp = input;
	
	while(tmp!= nullptr){
		ret ++;
		tmp = tmp-> next;
	}
	return ret;
}

void Poly::diffX(){
	if (head == nullptr) return;
	Term* util = head;
	while(util != nullptr){
		if(util->deg_x != 0){
			util->coeff *= util->deg_x ;
			util->deg_x -= 1;
		}else{
			util->coeff = 0;
		}
		util=util->next;
	}
}

void Poly::diffY(){
	if (head == nullptr) return;
	Term* util = head;
	while(util != nullptr){
		if(util->deg_y != 0){
			util->coeff *= util->deg_y ;
			util->deg_y -= 1;
		}else{
			util->coeff = 0;
		}
		util=util->next;
	}
}
		

Term* Poly::getHead(){
	return head;
}

void Poly::sortHelper(){
	head = mergeSort(head);
}

Term* Poly::mergeSort(Term* in){
	if(in == nullptr) return in;
	
	Term* util = in;
	
	if(in->next == nullptr){
		return in;
	}
	
	int mid = getSize(in)/2;
	
	int tmp =0;
	while(tmp < mid -1){
		util = util->next;
		tmp++;
	}
	
	Term* newTerm = util->next;
	util->next = nullptr;
	cout << "left = " << in->coeff << " right = " << newTerm->coeff << endl;
	Term* left = mergeSort(in);
	Term* right = mergeSort(newTerm);
	//return nullptr;
	return merge(left, right);
}


Term* Poly::merge(Term* left, Term* right){
	cout << "merging \n";
	Term* ret;
	if(left->deg_x > right->deg_x){
		ret = left;
	
	}else if(left->deg_x == right->deg_x){
		if(left->deg_y > right->deg_y){
			ret = left;
		}else{
			ret = right;
			right = left;
			left = ret;
		}
	}else{
		ret = right;
		right = left;
		left = ret;
	}	
	while(left->next != nullptr){
		if(left->next->deg_x < right->deg_x){
			Term* tmp = left->next;
			left->next = right;
			right = tmp;
		}else if((left->next->deg_x == right->deg_x) && (left->next->deg_y < right->deg_x)){
			Term* tmp = left->next;
			left->next = right;
			right = tmp;
		}
		
		left=left->next;
	}
	
	//concat remaining right list which only has larger values left now
	if (left->next == nullptr){
		left->next = right;
	}
	
	return ret;
}

void Poly::setHead(Term* in){
	head = in;
}

Poly operator +(Poly A, Poly B){
	
	
	Term* left = A.getHead();
	Term* right = B.getHead();
	
	Poly C;
	
	if (left== nullptr && right == nullptr){
		return C;
	}
	
	
	if(left == nullptr){
		while(right != nullptr){
			C.add(right->coeff,right->deg_x,right->deg_y);
			right = right->next;
		}
		C.sortHelper();
		return C;
	}
	
	if(right == nullptr){
		while(left != nullptr){
			C.add(left->coeff,left->deg_x,left->deg_y);
			left=left->next;
		}
		C.sortHelper();
		return C;
	}
	
	A.sortHelper();
	B.sortHelper();
	
	left = A.getHead();
	right = B.getHead();
	
	while(left != nullptr && right != nullptr){
		if(left->deg_x > right->deg_x){
			C.add(left->coeff,left->deg_x,left->deg_y);
			left = left->next;
		}else if(left->deg_x < right->deg_x){
			C.add(right->coeff,right->deg_x,right->deg_y);
			right = right->next;
		}else if(left->deg_y > right->deg_y){
			C.add(left->coeff,left->deg_x,left->deg_y);
			left = left->next;
		}else if(left->deg_y < right->deg_y){
			C.add(right->coeff,right->deg_x,right->deg_y);
			right = right->next;
		}else{
			C.add(left->coeff+right->coeff,left->deg_x,left->deg_y);
			left=left->next;
			right=right->next;
		}
	}
	
	while(left != nullptr){
			C.add(left->coeff,left->deg_x,left->deg_y);
			left=left->next;
	}
	
	while(right != nullptr){
			C.add(right->coeff,right->deg_x,right->deg_y);
			right = right->next;
	}
	
	return C;

}


	
	
	
	

ostream& operator << (ostream& out, const Poly a){
	
	if (a.head == nullptr){
		return out;
	}
	Term* util = a.head;
	while(util != nullptr){
		if (util->coeff < 0){
			out << util->coeff;
			if (util->deg_x != 0){
			out << "x^" <<util->deg_x;
			}
			if (a.head->deg_y != 0){
				out << "y^" <<util->deg_y;
			}
			util=util->next;
		}else if (util->coeff > 0){
			out << " +" << util->coeff;
			if (util->deg_x != 0){
			out << "x^" <<util->deg_x;
			}
			if (a.head->deg_y != 0){
				out << "y^" <<util->deg_y;
			}
			util=util->next;
		}else {
			util=util->next;
			//do nothing 0 term
		}
		
		
	}
	
	out << endl;
	
	return out;
	
}