#ifndef HASHTABLE_H
#define HASHTABLE_H


class HashTable{
	public:
		// Default Constructor
		// precondition
		// -
		// postcondition
		// makes a dynamic array of size SIZE and fills it up with -1
		HashTable();
	
		// getter for the member dynamic array
		// precondition
		// -
		// postcondition
		// returns the array reference
		int* gethead();
	private:
		//The reference to dynamic array
		int* table;
		//Size of the Table 
		const int SIZE = 1999;
};
			
#endif		
	