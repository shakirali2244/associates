#include <iostream>

using namespace std;

struct Term {
 int coeff;
 int deg_x;
 int deg_y;
 Term* next;
};

class Poly{
public:
	// constructor
	//precondition:
	// -
	//postcondition:
	// init head to nullptr
	Poly();

	// Creates a new node for linked list
	//precondition:
	// coeff, x, and y cannot be null reference
	//postcondition:
	// returns a new dynamically allocated Node for list
	Term* cons(int coeff, int x, int y, Term* next);

	// Adds a new term to the front of the Linked list
	//precondition:
	// -
	//postcondition:
	//  head is changed to the newer term
	Term* add(int coeff, int x, int y);

	// gets the size of the array
	//precondition:
	// -
	//postcondition:
	//  number of terms is returned as an int
	int getSize(Term* in);

	// getter for head for friend functions
	//precondition:
	// -
	//postcondition:
	//  head is returned
	Term* getHead();

	//Helper for calling merge sort
	//precondition:
	// -
	//postcondition:
	// Current polynomial is modified to a sorted one
	void sortHelper();

	// Merge Sort
	//precondition:
	// -
	//postcondition:
	// divides the lists into individual terms and calls merge returns final head
	Term* mergeSort(Term* in);

	//Merge the list
	//precondition:
	// left and right CANNOT BE NULL
	//postcondition:
	// merges the list and returns the head
	Term* merge(Term* left, Term* right);

	// Differentiates the current instance wrt x
	//precondition:
	// -
	//postcondition:
	//  polynomial is changed to the differentiate
	void diffX();

	// Differentiates the current instance wrt y
	//precondition:
	// -
	//postcondition:
	//  polynomial is changed to the differentiate
	void diffY();

	//overload << operator
	//precondition:
	// out is not a null reference
	//postcondition:
	// prints the polynomial with endl at the end
	friend ostream& operator << (ostream& out,const Poly A);

	//+ operator
	//precondition:
	// - 
	//postcondition:
	// adds the polynomials
	friend Poly operator +(Poly A, Poly B);
private:
	Term* head;
};
