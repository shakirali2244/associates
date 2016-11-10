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

ostream& operator << (ostream& out, const Poly a){
	
	if (a.head == nullptr){
		return out;
	}
	if (a.head->coeff < 0){
		out << " -";
	}else{
		out << " +";
	}
	out << a.head->coeff;
	if (a.head->deg_x != 0){
		out << "x^" << a.head->deg_x;
	}
	if (a.head->deg_y != 0){
		out << "y^" << a.head->deg_y;
	}
	
	return out;
	
}