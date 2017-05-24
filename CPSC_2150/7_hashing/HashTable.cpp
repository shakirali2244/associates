#include "HashTable.h"

// Default Constructor
// precondition
// -
// postcondition
// makes a dynamic array of size SIZE and fills it up with -1
HashTable::HashTable(){
	table = new int[SIZE]; //dynamic array of ints
	for( int i =0; i < SIZE; i++ ){
		table[i] = -1;
	}
}

// getter for the member dynamic array
// precondition
// -
// postcondition
// returns the array reference
int* HashTable::gethead(){
	return table;
}