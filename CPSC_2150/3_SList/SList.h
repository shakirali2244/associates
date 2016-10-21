#ifndef SLIST_H
#define SLIST_H
// Build and manipulate a two level skip list.
// Use it for sorting and count comparisons and traversals.
// CPSC 2150, Assignment #3,
#include <string>
#include <fstream>

const int MAXLEVEL = 2;

template<typename T>
struct Node{
	T key;
	int level;
	Node<T>** next;
};



// assumptions:
// the copy constructor, overloaded assignment operator and the destructor have
// been properly defined for the type T
// the following operators have been define for type T
// < the binary comparison operator for less than
// == the binary comparison operator for equality
// << the operator for output with the first operand as an output stream
template <typename T>
class SList {
	public:
		Node<T>* cons(T key, int level, Node<T>** next);
		SList();

		// insert an element in ascending order
		// Note: the operator <and the == operator must be defined for the type T
		void insert(T x);

		// return true if x is found in the list, false otherwise
		// if the number of comparisons made is needed,
		// call getComparisons() after found is called
		// postcondition: the number of comparisons have been counted
		bool found(T x);

		// returns the number of traversals done in order to build the list
		// the (resulting) list is sorted in ascending order
		// the number of traversals depends on the number of calls to insert
		int getTraversals() const;

		// returns the number of comparisons done when a search operation (found)
		// is called every time that found is called, the number of comparisons
		// is reset to zero and the number comparisons is calculated anew
		int getComparisons() const;

		// output all the elements of the list in order (i.e. in ascending order)
		// separate the elements with the defined delimeter
		// which has an intial value of " \n"
		// (may be changed with setOutputDelimeter)
		// the output operator << has been overloaded and defined
		// to work with an element
		// of type T
		void printAllInOrder(std::ostream&) const;

		// delimeter used in printAllInOrder when outputing
		// the elements of the list
		void setOutputDelimeter(std::string delimeter);

		// return the number of elements in the skip list
		int numberOfElements() const;

		// delete/deallocate all the lists allocated so far
		// and initialize the instance variables to their original
		// initialization values
		void reset();

		// overloaded assignment operator
		SList<T>& operator = (const SList&);

		// copy constructor
		SList(const SList&);

		// destructor
		~SList();

		// for debugging purpose, print top list .....
		// (not a real 'interface' function)
		void dumpTopList(std::ostream& out);

		Node<T>* getheader()const{
			return header;
		}

		Node<T>* gettail()const{
					return tail;
		}

	private:
		//SList<T> list;
		Node<T>* header;
		Node<T>* tail;


};
#endif // SLIST_H
