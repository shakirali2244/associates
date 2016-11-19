#include <iostream>

using namespace std;
struct Node{
	int coeff;
	int expo;
	Node* left;
	Node* right;
};


class Tree{
public:
	// constructor for creating an empty polynomial
	//precondition:
	//-
	//postcondition:
	// creates the Tree Object
	Tree();

	// Destructor
	//precondition:
	// -
	//postcondition:
	// clears memory
	~Tree();

	// Copy Constructor
	//precondition:
	// obj is not a null reference
	//postcondition:
	// Creates a new object same as the passed
	Tree(const Tree& obj);

	// Helper function for recursive call for copy constructor
	//precondition:
	// -
	//postcondition:
	// copies the tree into this's tree
	void copyHelper(Node*);

	// Creates a new node
	//precondition:
	// coeff and expo are not null reference
	//postcondition:
	// returns new node 
	Node* cons(int coeff, int expo, Node* left, Node* right);

	// getter for root of the tree
	//precondition:
	// -
	//postcondition:
	// returns tree private field
	Node* getTree()const;

	// Adds the term to the tree accordingly
	//precondition:
	// coeff and expo are not null reference 
	//postcondition:
	// creates a new node or adds the coefficient
	void add(int coeff, int expo);

	// isZero() recursive helper
	//precondition:
	// -
	//postcondition:
	// returns bool value if current trem is zero coefficient
	bool isZero(Node* tree);

	// checks if the polynomial is a zero ppolynomial
	//precondition:
	// -
	//postcondition:
	// returns bool value if poly is zero
	bool isZero();

	// deletes the binary tree and frees the memory
	//precondition:
	// -
	//postcondition:
	// -
	void deleteTree();

	// deleteTree() recursive helper
	//precondition:
	// tree is not a null reference
	//postcondition:
	// -
	void deleteTreeHelper(Node* &tree);

	// returns the degree for the polynomial
	//precondition:
	// -
	//postcondition:
	// -
	int degree();

	// returns the coefficient for the degree provided
	//precondition:
	// -
	//postcondition:
	// returns 0 if not found
	int degreeCoeff(int expo);

	// evaluates the polynomial for provided value of x
	//precondition:
	// -
	//postcondition:
	// returns the integer evaluation
	int evaluate(int x);

	// recursive helper for evluate
	//precondition:
	// -
	//postcondition:
	// -
	int evaluateHelper(Node* tree,int x);

	// recursive helper for << operator
	//precondition:
	// out and top are not null reference
	//postcondition:
	// -
	void printHelper(ostream& out, Node* top) const;

	// overloading << operator
	//precondition:
	// out and A are not null reference
	//postcondition:
	// -
	friend ostream& operator << (ostream& out,const Tree &A);

	// overloading >> operator
	//precondition:
	// out and A are not null reference
	//postcondition:
	// -
	friend istream& operator >> (istream& out, Tree &A);

	// helper function for + operator
	//precondition:
	// t and top are not null reference
	//postcondition:
	// -
	void addHelper(Tree &t, Node* top);

	// overloading + operator
	//precondition:
	// A and B are not null reference
	//postcondition:
	// returns new instance of result Tree
	friend Tree operator +(Tree &A, Tree &B);

	// overloading = operator
	//precondition:
	// B is not null reference
	//postcondition:
	// copies the B tree deeply
	Tree& operator = (const Tree &B);

private:
	Node* tree;
};
	
	
	

	