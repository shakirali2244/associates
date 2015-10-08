// Shakir Ali , 100268078
//CPSC 1160, Assignment 3
//program that sorts an array
//program cannot regenerate rand array with diffrerent numbers
// bugs  - fillRand fill same numbers as before
//no references

#include <iostream>
#include <cstdlib>
#include <time.h>


void sort(int  A[], int n);
void sortRec(int  A[], int n);
void sortRec(int  A[], int n, int index);
void fillRand(int  B[], int n);


using namespace std;


int main(){
	const int SIZE = 4; //size of test array
	const int RAND_SIZE = 17; //size of rand array
	
	int A [SIZE] = {5,5,1,5}; //fill test array 
	sort(A, SIZE); //pass to sort function
	
	int B [RAND_SIZE]; //declare array for rand ints
	
	fillRand(B,RAND_SIZE); //fill the array
	
	
	//print the unsorted array
	cout << endl << "Random generated Array: " <<endl;
	for (int p = 0 ; p < RAND_SIZE; p ++ ){
			cout << B[p];
			if (!(p==RAND_SIZE-1))
				cout << ",";
			if ((p+1)%4==0)
				cout << endl;
	}
	
	sort(B,RAND_SIZE); //pass to sort function
	
	//recursive part
	
	int C[SIZE] = {6,5,1,5}; //refill test array since older was sorted
	sortRec(C, SIZE); //pass to recursive sort function
	
	fillRand(B,RAND_SIZE); //refill the rand since last was sorted 
	
	//print the unsorted array
	cout << endl << "Random generated array: " <<endl;
	for (int p = 0 ; p < RAND_SIZE; p ++ ){
			cout << B[p];
			if (!(p==RAND_SIZE-1))
				cout << ",";
			if ((p+1)%4==0)
				cout << endl;
	}
	
	sortRec(B,RAND_SIZE); //pass to recursive sort function
	
	
	
}

// sorts the array using custom algorithm and prints when done
//precondition:
//n is length of the array
// postcondition:
// prints the sorted version and returns nothing
void sort(int A[], int n){
	 //go up until halfway point for i
	for (int i = 0 ; i < n/2 ; i++){
		for (int k = i; k < n-1; k++){ //k is i and  has range (0 to  n-1)
			if(A[k+1] < A[k]){  //compare and swap if needed
				int temp = A[k];
				A[k] = A[k+1];
				A[k+1] = temp;
			}
		}
		for (int l = n-i-2; l  > 0 ; l--){ //l is i and has range (0 to  n - 2)
			if(A[l] < A[l-1]){ //compare and swap if needed
				int temp = A[l];
				A[l] = A[l-1];
				A[l-1] = temp;
			}
		}
	}
	
	//print the sorted array
	cout << endl << "Sorted array :" << endl ;
	for (int p = 0 ; p < n; p ++ ){
			cout << A[p];
			if (!(p==n-1))
				cout << ",";
			if ((p+1)%4==0)
				cout << endl;
		}
	cout << endl;		
}

// passes the array to an overloaded recursive function
//precondition:
//n is length of the array
// postcondition:
// calls overloaded recursive function
void sortRec(int A[], int n){
	return sortRec(A,n,0); //pass to helper function
}

// sorts the array using custom algorithm and prints when done
//precondition:
//n is length of the array
// postcondition:
// prints the sorted version and returns nothing
void sortRec(int A[], int n,int index){
	if (index >= n/2){ //if passed index was greater than halfway point, print and return
		//print the sorted array
		cout << endl << "Sorted array :" << endl ;
		for (int p = 0 ; p < n; p ++ ){
			cout << A[p];
			if (!(p==n-1))
				cout << ",";
			if ((p+1)%4==0)
				cout << endl;
		}
		cout << endl;	
		return;
	}
	
	for (int k =index; k < n-1; k++){ //k is i and  has range (0 to  n-1)
			if(A[k+1] < A[k]){ //compare and swap if needed
				int temp = A[k];
				A[k] = A[k+1];
				A[k+1] = temp;
			}
		}
	for (int l = n-index-2; l  > 0 ; l--){ //l is i and has range (0 to  n - 2)
		if(A[l] < A[l-1]){ //compare and swap if needed
			int temp = A[l];
			A[l] = A[l-1];
			A[l-1] = temp;
		}
	}
	sortRec(A,n,index+1); //call again with index+1
}

// fills the array with random numbers
//precondition:
//n is length of the array
// postcondition:
// fills the array with random
void fillRand(int  B[], int n){
	srand (time(NULL)); //generate seed
	for (int i=0; i < n; i++){ 
		int num = rand() % RAND_MAX +1; 
		B[i]=num; //fill with int data type
	}
}
	
	
	
	
	

	
	
	

