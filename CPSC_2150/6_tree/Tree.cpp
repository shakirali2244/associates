#include <iostream>
#include "Tree.h"

using namespace std;

// constructor for creating an empty polynomial
//precondition:
//-
// postcondition:
// creates the Tree Object
Tree::Tree(){
	tree = cons(0,0,nullptr,nullptr); //create zero polnommial
}	

// Helper function for recursive call for copy constructor
//precondition:
// -
//postcondition:
// copies the tree into this's tree
void Tree::copyHelper(Node* in){
	if(in!= nullptr){ //base case
		copyHelper(in->left);
		add(in->coeff, in->expo);  //add new term
		copyHelper(in->right);
	}
}

// Copy Constructor
//precondition:
// obj is not a null reference
//postcondition:
// Creates a new object same as the passed
Tree::Tree(const Tree &obj){
	tree = cons(0,0,nullptr,nullptr); //crete zero poynomial
	copyHelper(obj.getTree()); //call recirsive helper
	
}
	
// Creates a new node
//precondition:
// coeff and expo are not null reference
//postcondition:
// returns new node 
Node* Tree::cons(int coeff, int expo, Node* left, Node* right){
	return new Node {coeff, expo, left, right};
}

// getter for root of the tree
//precondition:
// -
//postcondition:
// returns tree private field
Node* Tree::getTree() const{
	return tree;
}

// checks if the polynomial is a zero ppolynomial
//precondition:
// -
//postcondition:
// returns bool value if poly is zero
bool Tree::isZero(){
	return isZero(tree); //recursive call
}

// isZero() recursive helper
//precondition:
// -
//postcondition:
// returns bool value if current trem is zero coefficient
bool Tree::isZero(Node* tree){
	if(tree != nullptr){
		return (tree->coeff == 0) && isZero(tree->left) && isZero(tree->right);	 //using AND with recursion
	}else{
		return true; //base case;
	}
}

// Adds the term to the tree accordingly
//precondition:
// coeff and expo are not null reference 
//postcondition:
// creates a new node or adds the coefficient
void Tree::add(int coeff, int expo){
	Node* entry = cons(coeff, expo, nullptr, nullptr);
	if (tree == nullptr){ //create new node if tree was null
		tree = entry;
		return;
	}
	Node* util = tree;

	//implementing the add algorithm for a BST
	while(util!= nullptr){  
		if (util->expo < entry->expo ){
			if(util->left != nullptr){
				util=util->left;
			}else{
				util->left=entry;
				break;
			}
		}
		else if (util->expo > entry->expo ){
			if(util->right != nullptr){
				util=util->right;
			}else{
				util->right=entry;
				break;
			}
		} else{ //simplyfy if exponent same
			util->coeff = util->coeff + entry->coeff;
			break;
		}
	}
}

// deletes the binary tree and frees the memory
//precondition:
// -
//postcondition:
// -
void Tree::deleteTree(){
	deleteTreeHelper(tree); //recursive helper
}


// deletes the binary tree and frees the memory
//precondition:
// -
//postcondition:
// -
void Tree::deleteTreeHelper(Node* &tree){
	if(tree != nullptr){ //base case
		Node* left = tree->left; //save copies 
		Node* right = tree->right; //save copies
		delete tree;
		tree = nullptr;
		deleteTreeHelper(left); //recursive call
		deleteTreeHelper(right); //recursive call
	}
}

// evaluates the polynomial for provided value of x
//precondition:
// -
//postcondition:
// returns the integer evaluation	
int Tree::evaluate(int x){
	return evaluateHelper(tree,x); //recursive call
}
	
// recursive helper for evluate
//precondition:
// -
//postcondition:
// -
int Tree::evaluateHelper(Node* tree, int x){
	if (tree != nullptr){ 
		int tmp = tree->expo;
		int ret = tree->coeff;
		for( int i = 0; i < tmp; i++){
			ret *= x;
		}
		return ret + evaluateHelper(tree->right,x) + evaluateHelper(tree->left,x); //recursive call
	}else{ //base case
		return 0;
	}
}

// returns the degree for the polynomial
//precondition:
// -
//postcondition:
// -
int Tree::degree(){
	Node* tmp = tree;
	if (tmp == nullptr) return 0;
	while(tmp->left != nullptr){ //keep treversing since sorted tree
		tmp = tmp->left;
	}
	return tmp->expo;
}

// returns the coefficient for the degree provided
//precondition:
// -
//postcondition:
// returns 0 if not found
int Tree::degreeCoeff( int expo){
	Node* tmp = tree;
	if (tmp == nullptr) return 0;
	while(tmp != nullptr){
		if(expo > tmp->expo){ //go left if need expo larger
			tmp = tmp-> left;
		}else if(expo < tmp->expo){ //vice versa 
			tmp = tmp->right;
		}else{
			return tmp->coeff; // return if found
		}
	}
	return 0; //return zero
}	

// helper function for + operator
//precondition:
// t and top are not null reference
//postcondition:
// -
void Tree::addHelper(Tree &C, Node*b){
	if(b!=nullptr){ //base case
		C.add(b->coeff,b->expo);
		addHelper(C,b->left); //recursive call
		addHelper(C,b->right); //recursive call
	}
}

// overloading + operator
//precondition:
// A and B are not null reference
//postcondition:
// returns new instance of result Tree
Tree operator +(Tree &A, Tree &B){
	Tree t3(A); //deep copy first tree
	t3.addHelper(t3,B.getTree()); //add second tree
	return t3;
}

// recursive helper for << operator
//precondition:
// out and top are not null reference
//postcondition:
// -
void Tree::printHelper(ostream& out, Node* top) const{
	if(top != nullptr){
		printHelper(out, top->left); //will print left ones first hence in decending order
		if(top->coeff != 0){
			if(top->coeff  > 0){
			out << " +";
			}else{
				out << " ";
			}
			cout << top->coeff ;
			if (top->expo != 0){
				cout << "x^" <<top->expo;
			}
		}
		printHelper(out,top->right);
	}
}

// overloading << operator
//precondition:
// out and A are not null reference
//postcondition:
// -
ostream& operator << (ostream& out,const Tree &A){
	A.printHelper(out,A.getTree()); //recursive helper
	return out;
}

// overloading >> operator
//precondition:
// out and A are not null reference
//postcondition:
// -
istream& operator >> (istream& in, Tree &A){
	cout << "enter number of terms \n";
	int terms;
	in >> terms;
	for (int i=0; i<terms; i++){
		int coeff = 0;
		int expo = 0;
		in>>coeff;
		in>>expo;
		A.add(coeff,expo); //call add to create terms
	}
	return in;
}

// overloading = operator
//precondition:
// B is not null reference
//postcondition:
// copies the B tree deeply
Tree& Tree::operator =(const Tree &B){
	if(this == &B){
		return *this;
	}
	deleteTree();
	copyHelper(B.getTree());
	return *this;
}

// Destructor
//precondition:
// -
//postcondition:
// clears memory
Tree::~Tree(){
	deleteTree();
}
	
	
	
	
	