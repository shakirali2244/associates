#include "Poly.h"
#include <iostream>
 using namespace std;

// constructor
//precondition:
// -
//postcondition:
// init head to nullptr
Poly::Poly(){
	head = nullptr;
}

// Creates a new node for linked list
//precondition:
// coeff, x, and y cannot be null reference
//postcondition:
// returns a new dynamically allocated Node for list
Term* Poly::cons(int coeff, int x, int y, Term* next){
	return new Term{coeff,x,y, next};
}

// Adds a new term to the front of the Linked list
//precondition:
// -
//postcondition:
//  head is changed to the newer term
Term* Poly::add(int coeff, int x, int y){
	Term* tmp = cons(coeff,x,y,head);
	head = tmp;
	return head;
}

// gets the size of the array
//precondition:
// -
//postcondition:
//  number of terms is returned as an int
int Poly::getSize(Term* input){
	if(input == nullptr){
		return 0;
	}
	int ret = 0; //counter
	Term* tmp = input;
	
	while(tmp!= nullptr){
		ret ++;
		tmp = tmp-> next;
	}
	return ret;
}

// Differentiates the current instance wrt x
//precondition:
// -
//postcondition:
//  polynomial is changed to the differentiate
void Poly::diffX(){
	if (head == nullptr) return;
	Term* util = head;
	while(util != nullptr){
		if(util->deg_x != 0){ //assuming non negative degrees differentiate term by term
			util->coeff *= util->deg_x ;
			util->deg_x -= 1;
		}else{
			util->coeff = 0;
		}
		util=util->next;
	}
}

// Differentiates the current instance wrt y
//precondition:
// -
//postcondition:
//  polynomial is changed to the differentiate
void Poly::diffY(){
	if (head == nullptr) return;
	Term* util = head;
	while(util != nullptr){
		if(util->deg_y != 0){ //assuming non negative degrees differentiate term by term
			util->coeff *= util->deg_y ;
			util->deg_y -= 1;
		}else{
			util->coeff = 0;
		}
		util=util->next;
	}
}
		
// getter for head for friend functions
//precondition:
// -
//postcondition:
//  head is returned
Term* Poly::getHead(){
	return head;
}

//Helper for calling merge sort
//precondition:
// -
//postcondition:
// Current polynomial is modified to a sorted one
void Poly::sortHelper(){
	head = mergeSort(head);
}

// Merge Sort
//precondition:
// -
//postcondition:
// divides the lists into individual terms and calls merge returns final head
Term* Poly::mergeSort(Term* in){
	//dont change if 0 or 1 terms
	if(in == nullptr) return in;
	
	//mid term reference
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
	//break the list as part of the algorithm
	util->next = nullptr;
	//sort left and right recursively
	Term* left = mergeSort(in);
	Term* right = mergeSort(newTerm);
	//merge sorted lists
	return merge(left, right);
}

//Merge the list
//precondition:
// left and right CANNOT BE NULL
//postcondition:
// merges the list and returns the head
Term* Poly::merge(Term* left, Term* right){
	//final head to be returned
	Term* ret;
	if(left->deg_x > right->deg_x){
		ret = left;
	
	}else if(left->deg_x == right->deg_x){
		if(left->deg_y > right->deg_y){
			ret = left;
		} else if(left->deg_y == right->deg_y){ //if same the add them
			ret = left;
			left->coeff += right->coeff;
			right->coeff = 0;
		}else{ //if right is larger we need to swich positions and ret before we start traversing
			ret = right;
			right = left;
			left = ret;
		}
	}else{ //if right is larger we need to swich positions and ret before we start traversing
		ret = right;
		right = left;
		left = ret;
	}	
	
	//if right is larger we need to swich positions and ret
	while(left->next != nullptr){
		if(left->next->deg_x < right->deg_x){ //if right front is larger attach it to the left and break left next the make it right
			Term* tmp = left->next;
			left->next = right;
			right = tmp;
		}else if((left->next->deg_x == right->deg_x) && (left->next->deg_y < right->deg_x)){ //if right front is larger attach it to the left and break left next the make it right
			Term* tmp = left->next;
			left->next = right;
			right = tmp;
		} else if ((left->next->deg_x == right->deg_x) && (left->next->deg_y == right->deg_y)){ // if they are the same , add them
			left->coeff += right->coeff;
			right->coeff = 0;
		}
		
		left=left->next;
	}
	
	//concat remaining right list which only has larger values left now
	if (left->next == nullptr){
		left->next = right;
	}
	
	return ret;
}

//+ operator
//precondition:
// - 
//postcondition:
// adds the polynomials
Poly operator +(Poly A, Poly B){
	
	
	Term* left = A.getHead();
	Term* right = B.getHead();
	
	Poly C;
	
	if (left== nullptr && right == nullptr){
		return C;
	}
	
	 // if one of them is empty just keep adding the other
	if(left == nullptr){
		while(right != nullptr){
			C.add(right->coeff,right->deg_x,right->deg_y);
			right = right->next;
		}
		C.sortHelper();
		return C;
	}
	// if one of them is empty just keep adding the other
	if(right == nullptr){
		while(left != nullptr){
			C.add(left->coeff,left->deg_x,left->deg_y);
			left=left->next;
		}
		C.sortHelper();
		return C;
	}
	
	//sort them since is required by the following code
	A.sortHelper();
	B.sortHelper();
	
	//get the sorted head
	left = A.getHead();
	right = B.getHead();
	
	// add in ascending order between the first terms and after traversing until once finishes
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
			int tmp = left->coeff+right->coeff;
			if(tmp != 0){
				C.add(tmp,left->deg_x,left->deg_y);
			}
			left=left->next;
			right=right->next;
		}
	}
	//keep adding the tail if they are not the same size
	while(left != nullptr){
			C.add(left->coeff,left->deg_x,left->deg_y);
			left=left->next;
	}
	//keep adding the tail if they are not the same size
	while(right != nullptr){
			C.add(right->coeff,right->deg_x,right->deg_y);
			right = right->next;
	}
	//finally Sort the returning Polynomial
	C.sortHelper();
	return C;

}

//overload << operator
//precondition:
// out is not a null reference
//postcondition:
// prints the polynomial with endl at the end
ostream& operator << (ostream& out, const Poly a){
	
	if (a.head == nullptr){
		out << endl;
		return out;
	}
	Term* util = a.head;
	//print everything neatly as asked by the assignment
	while(util != nullptr){
		if (util->coeff < 0){
			out << " " <<util->coeff;
			if (util->deg_x != 0){
			out << " x^" <<util->deg_x;
			}
			if (util->deg_y != 0){
 				out << " y^" <<util->deg_y;
			}
			util=util->next;
		}else if (util->coeff > 0){
			out << " + " << util->coeff;
			if (util->deg_x != 0){
			out << " x^" <<util->deg_x;
			}
			if (util->deg_y != 0){
				out << " y^" <<util->deg_y;
			}
			util=util->next;
		} else{
			util=util->next;
		}
		
		
	}
	out << endl;
	return out;
	
}