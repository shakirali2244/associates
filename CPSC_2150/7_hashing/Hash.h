#include "HashTable.h"
#ifndef HASH_H
#define HASH_H


class Hash{
	public:
		// Default Constructor
		// precondition
		// -
		// postcondition
		// creates a Hash class with private fields 
		Hash();
	
		// hash function
		// precondition
		// -
		// postcondition
		// creates a Hash class with private fields 
		int h(int x);
	
		int ht(int x);
	
		// helper function for calling respective searching function
		// precondition
		// x is number to be searched, counter is not a null reference, linear is true when linear probing is required
		// postcondition
		// makes a call to the respective search function
		bool search(int x, HashTable T, bool linear, int &counter);
	
		// helper function for calling respective insert function
		// precondition
		//  x is number to be inserted, linear is true when linear probing is required
		// postcondition
		// makes a call to the respective insert function
		bool insert(int x,HashTable T, bool linear);
		
		// searches x in the table T using linear probing and counts the comparisions
		// precondition
		// counter is not null reference, x is int to be searched T is not empty
		// postcondition
		// returns bool if x is in table T 
		bool searchLin(int x, HashTable T, int& counter);
		
		// inserts x in the table T using linear probing
		// precondition
		//  x is int to be inserted T is not empty
		// postcondition
		// inserts x in the table if it is not there already returns bool if insertion happens
		bool insertLin(int x, HashTable T);
		
		// searches x in the table T using quadratic probing and counts the comparisions
		// precondition
		// counter is not null reference, x is int to be searched T is not empty
		// postcondition
		// returns bool if x is in table T 
		bool searchQad(int x, HashTable T,  int& counter);
		
		// inserts x in the table T using quadratic probing
		// precondition
		//  x is int to be inserted T is not empty
		// postcondition
		// inserts x in the table if it is not there already returns bool if insertion happens
		bool insertQad(int x, HashTable T);
		
		// searches x in the table T using double hashing and counts the comparisions
		// precondition
		// counter is not null reference, x is int to be searched T is not empty
		// postcondition
		// returns bool if x is in table T 
		bool searchDub(int x, HashTable T,  int& counter);
		
		// inserts x in the table T using d0uble hashing
		// precondition
		//  x is int to be inserted T is not empty
		// postcondition
		// inserts x in the table if it is not there already returns bool if insertion happens
		bool insertDub(int x, HashTable T);
		
		// fills up the array with 1000 random values
		// precondition
		//  -
		// postcondition
		// fills up the table
		void getKey(HashTable T, bool linear);
		
		// fills up the array with 1000 random values using double hashing
		// precondition
		//  -
		// postcondition
		// fills up the table
		void getKeyDub(HashTable T);
		
		//prints the table if needed
		// precondition
		// -
		// postcondition
		// prints the table values other than -1 to stdout
		void print(HashTable T);
	private:
		//Size of the Table 
		const int SIZE = 1999;
		//number of elements in the table
		const int LOADED = 1000;
};
#endif
		
		