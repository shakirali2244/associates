#include "Hash.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// Default Constructor
// precondition
// -
// postcondition
// creates a Hash class with private fields 
Hash::Hash(){
	//empty constructor
}

// hash function
// precondition
// -
// postcondition
// creates a Hash class with private fields 
int Hash::h(int x) {
	return x % SIZE; //as asked in the assignment sheet
}

int Hash::ht(int x) {
	int sum=0;
	int tmp = x;
	while(tmp>0){
		sum  += tmp%10;
		tmp=tmp/10;
	}
	x=x/10;
	x=x+sum;
	return x % SIZE; //as asked in the assignment sheet
}

// helper function for calling respective searching function
// precondition
// x is number to be searched, counter is not a null reference, linear is true when linear probing is required
// postcondition
// makes a call to the respective search function
bool Hash::search(int x, HashTable T, bool linear, int &counter){
	if(linear)
		return searchLin(x,T, counter);
	else
		return searchQad(x,T, counter);
}

// helper function for calling respective insert function
// precondition
//  x is number to be inserted, linear is true when linear probing is required
// postcondition
// makes a call to the respective insert function
bool Hash::insert(int x, HashTable T, bool linear){
	if(linear)
		return insertLin(x,T);
	else 
		return insertQad(x,T);
}

// searches x in the table T using linear probing and counts the comparisions
// precondition
// counter is not null reference, x is int to be searched T is not empty
// postcondition
// returns bool if x is in table T 
bool Hash::searchLin(int x, HashTable T, int& counter){
	if(x == -1){ //since x hast to be > 0 as asked in the assignment
		return false;
	}
	int index = h(x); //got the start index
	int originalInd = index; //remember the start index
	int* tmp = T.gethead();
	counter = 1;
	//traverse through the array and return respectively
	while(tmp[index] != x){ //check if x is on the table
		if(tmp[index] == -1){ //meaning x is not in the table
			return false;
		}
		index++;
		if(index >= SIZE-1){ //if we reach the end go to the start
			index = 0;
		}
		if(index == originalInd){ //if we checked everything and still not there
			return false;
		}
		counter++;
	}
	return true;
}

// inserts x in the table T using linear probing
// precondition
//  x is int to be inserted T is not empty
// postcondition
// inserts x in the table if it is not there already returns bool if insertion happens
bool Hash::insertLin(int x, HashTable T){
	int counter = 0;
	//check if x is already in the table and proceed if not 
	if(searchLin(x,T,counter)){
		return false;
	}
	int index = h(x); //get the start index
	int originalInd = index; //remember the start index
	int* tmp = T.gethead();
	if(tmp[index] == -1){ //check the start index if anything is already there
		tmp[index] = x; //insert at index if empty
		return true;
	}
	//eventually one if would be true
	while(true){
		if(tmp[index] == -1){//check the index if anything is already there
			tmp[index] = x; //insert at index if empty
			return true;
		}
		index++;
		if(index >= SIZE-1){//if we reach the end go to the start
			index = 0;
		}
		if(index == originalInd){//if we checked entire table for empty spot and no spot left
			return false;
		}
	}
	return false;
}

// searches x in the table T using quadratic probing and counts the comparisions
// precondition
// counter is not null reference, x is int to be searched T is not empty
// postcondition
// returns bool if x is in table T 
bool Hash::searchQad(int x, HashTable T, int &counter){
	if(x == -1){//since x hast to be > 0 as asked in the assignment
		return false;
	}
	int index = h(x);//get the start index
	int indexOri = index;//remember the start index
	int* tmp = T.gethead();
	for(int i = 1; i < SIZE; i++){ //do not cross SIZE iterations meaning , if we do x is not on the table
		counter++;	
		if(tmp[index] == -1){//meaning x is not in the table
			return false;
		}
		if(tmp[index] == x){ //check if x is on the table
			return true;
		}
		//quadratic probeing formula
		index = (indexOri + (i*i))% SIZE;
	}
	return false; //if the table is full and x is not on
}

// inserts x in the table T using quadratic probing
// precondition
//  x is int to be inserted T is not empty
// postcondition
// inserts x in the table if it is not there already returns bool if insertion happens
bool Hash::insertQad(int x, HashTable T){
	int counter = 0;
	//check if x is already in the table and proceed if not 
	if(searchQad(x,T, counter)){
		return false;
	}
	int index = h(x); //get the start index
	int indexOri = index; //remember the start index
	int* tmp = T.gethead();
	for(int i = 1; i <= SIZE; i++){ //do not cross SIZE iterations meaning table is probably full
		if(tmp[index] == -1){//check the index if anything is already there
			tmp[index] = x; //insert if empty
			return true;
		}
		//quadratic probeing formula
		index = (indexOri + (i*i)) % SIZE;
	}
	return false; //crossed the SIZE number of iterations
}

// searches x in the table T using double hashing and counts the comparisions
// precondition
// counter is not null reference, x is int to be searched T is not empty
// postcondition
// returns bool if x is in table T 
bool Hash::searchDub(int x, HashTable T,int &counter){
	if(x == -1){//since x hast to be > 0 as asked in the assignment
		return false;
	}
	int index = h(x);//get the start index
	int htt = ht(x); //get second hash
	int indexOri = index;//remember the start index
	int* tmp = T.gethead();
	for(int i = 1; i < SIZE; i++){ //do not cross SIZE iterations meaning , if we do x is not on the table
		counter++;	
		if(tmp[index] == -1){//meaning x is not in the table
			return false;
		}
		if(tmp[index] == x){ //check if x is on the table
			return true;
		}
		//double hashing formula
		index = (indexOri + i*htt) % SIZE;
	}
	return false; //if the table is full and x is not on
}

// inserts x in the table T using d0uble hashing
// precondition
//  x is int to be inserted T is not empty
// postcondition
// inserts x in the table if it is not there already returns bool if insertion happens
bool Hash::insertDub(int x, HashTable T){
	int counter = 0;
	//check if x is already in the table and proceed if not 
	if(searchDub(x,T, counter)){
		return false;
	}
	int index = h(x);//get the start index
	int htt = ht(x); //get second hash
	int indexOri = index;//remember the start index
	int* tmp = T.gethead();
	for(int i = 1; i < SIZE; i++){ //do not cross SIZE iterations meaning , if we do x is not on the table
		counter++;	
		if(tmp[index] == -1){//meaning x is not in the table
			tmp[index] = x;
			return true;
		}
		//double hashing formula
		index = (indexOri + i*htt) % SIZE;
	}
	return false; //if the table is full and x is not on
}



// fills up the array with 1000 random values
// precondition
//  -
// postcondition
// fills up the table
void Hash::getKey(HashTable T, bool linear){
	srand(time(0)); //generate a seed based on time so that its unique
	int total = 0;
	while(total < LOADED){ //fill the table with LOADED entries i.e 1000
		// r >= 0  and r < 2^30
		int r = rand() % RAND_MAX; //get a random value between 0 to 2^15 -1
		r *=  pow( 2, (rand() % 15 +1)); //multiply it with upto 2^15  to get r between 0 and 2^30 to get what is asked
		if (insert(r,T,linear)){ //if insert was true meaning r did not exist in the table
			total++;
		}
	}
}

void Hash::getKeyDub(HashTable T){
	srand(time(0)); //generate a seed based on time so that its unique
	int total = 0;
	while(total < LOADED){ //fill the table with LOADED entries i.e 1000
		// r >= 0  and r < 2^30
		int r = rand() % RAND_MAX; //get a random value between 0 to 2^15 -1
		r *=  pow( 2, (rand() % 15 +1)); //multiply it with upto 2^15  to get r between 0 and 2^30 to get what is asked
		if (insertDub(r,T)){ //if insert was true meaning r did not exist in the table
			total++;
		}
	}
	
}

//prints the table if needed
// precondition
// -
// postcondition
// prints the table values other than -1 to stdout
void Hash::print(HashTable T){
	int* tmp = T.gethead();
	cout << "[ ";
	for(int i = 0; i<SIZE; i++){ // dont cross SIZE
		if (tmp[i] != -1)
			cout << tmp[i] << " ";
	}
	cout << " ]" << endl;
}
			
		
		
	
	

	