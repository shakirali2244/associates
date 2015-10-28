// Shakir Ali , 100268078
//CPSC 1160, Assignment 4
//program that calculates time required to sort array
//
// bugs  -  merge sort has a typing bug
// references  - Class notes / 

#include <iostream>
#include <cstdlib>
#include <ctime>


void selectionSort(int A[], int n);

void quickSort(int A[], int n);
void quickSort( int a[], int first, int last );
int pivot(int A[], int first, int last);

void mergeSort(int A[], int W[], int n);
void mergeSort(int A[], int low, int high, int W[]);
void merge(int A[], int lstart, int lend, int rstart, int rend,int W[]);


void swap(int A[], int m, int i);
void fillRand(int  B[], int n);

void printArray(int A[], int n);





int main(){
	const int RAND_SIZE = 17; //size of rand arrays
	
	int B [RAND_SIZE]; //declare array for rand ints
	int W [RAND_SIZE];  //declare W array for merge sort
	
fillRand(B,RAND_SIZE); //fill the array
	
	//print the unsorted array
	std::cout << std::endl << "Random generated Array: " <<std::endl;
	printArray(B,RAND_SIZE);
	const clock_t begin_time = clock(); //start counting
	
		//fillRand(B,RAND_SIZE); //fill the array
		mergeSort(B,W,RAND_SIZE); //sort the array
	
	//selectionSort(B,RAND_SIZE); //pass to sort function
	//mergeSort(B,W,RAND_SIZE); //pass to sort function
	std::cout << float( clock () - begin_time ) ; //stop counting and print the time taken
	
	//print the sorted array
	std::cout << std::endl << "sorted"<< std::endl;
	printArray(B,RAND_SIZE);
	
	
	}
	
// sorts the array using selection sorting algorithm
//precondition:
//n is length of the array
// postcondition:
// sorts the array in ascending order
void selectionSort(int A[], int n){
	int m;
	for (int i=0; i < n-1; i++){
		m = i;//set m to the current index of array
		for (int j=i+1; j < n; j++){
			if (A[j] < A[m])
				m=j;
			}
		if (m != i)
			swap(A,i,m); //call swap if lesser value found
	}
			
}

// sorts the array using quickSort sorting algorithm
//precondition:
//n is length of the array
// postcondition:
// sorts the array in ascending order
void quickSort(int A[], int n){
	quickSort(A,0,n-1); //call  helper
}
	
// helper recursive function for quicksort
//precondition:
//n is length of the array
// postcondition:
// sorts the array in ascending order	
void quickSort( int a[], int first, int last ) {
	int p;
	if(first < last){ //we fix the problem from class here , by removing the unwanted base cases
		p = pivot(a, first, last); //get the partition index and sort
		quickSort(a, first, p-1); 
		quickSort(a, p+1, last);
	}
}

//returns the partion index and sorts recursive function
//precondition:
//first it min and last is max index
// postcondition:
// returns the pivot to partiion the array
int pivot(int A[], int first, int last) {
	int  p = first;
	int pivotElement = A[first]; //value at pivot
 
	for(int i = first+1 ; i <= last ; i++){
		if(A[i] <= pivotElement){
		    p++;
		    swap(A,i,p);
		}
	}
	swap(A,p,first);
	return p;
}

// sorts the array using mergeSort sorting algorithm
//precondition:
//n is length of the array
// postcondition:
// sorts the array in ascending order
void mergeSort(int A[], int W[], int n){
	mergeSort(A,0,n-1,W); //call helper
}

// helper recursive function for mergeSort
//precondition:
//low is first index and high is the last index
// postcondition:
// divides array recursively and calls merge
void mergeSort(int A[], int low, int high, int W[]){
	if (low == high) return;
	int mid = (low+high)/2;
	mergeSort(A,low,mid,W); //split and recursive call
	mergeSort(A,mid+1,high,W); //split and recursive call
	merge(A,low,mid,mid+1,high,W); //sort and merge
}

//merger for the merge sort algorithm
//precondition:
//lstart is start of left partition and lend is end and same for right
// postcondition:
// decides the position of elements from parts and puts them to W and copies to A
void merge(int A[], int lstart, int lend, int rstart, int rend,int W[]){
	int i = lstart, j = rstart, k = lstart;
	
	while(i <=lend && j <= rend){ //fill W accordingly
		if (A[i] < A[j])
			W[k++] = A [i++];
		 else 
			W[k++] = A[j++];
	 }
	 while(i<=lend){ //take care of tail
		 W[k++] = A[i++];
	 }
	 while(j <= rend){  //take care of tail
		 W[k++] = A[j++];
	 }
	 for (i = lstart; i < rend; i++){ //copy to A
		 A[i]=W[i];
	 }
 }
	
// Swaps the values at i and m in array A
//precondition:
//i and m are less then length of array
// postcondition:
// swaps the values at those positions
void swap(int A[], int m, int i){
	int temp = A[i];
	A[i] = A[m];
	A[m] = temp;
}

// fills the array with random numbers
//precondition:
//n is length of the array
// postcondition:
// fills the array with random
void fillRand(int  B[], int n){
	int LARGEST_15_BIT_NUMBER = 32767; //largest 15 bit number as asked in assignment
	srand (time(NULL)); //generate seed
	for (int i=0; i < n; i++){ 
		int num = rand() % LARGEST_15_BIT_NUMBER +1; 
		B[i]=num; //fill with int data type
	}
}

// print array in a pretty way
//precondition:
//n is the length of array
// postcondition:
// prints 4 elements per row
void printArray(int B[], int n){
	int MAX_COL = 4;
	for (int p = 0 ; p <  n; p ++ ){
			std::cout << B[p];
			if (!(p== n-1))
				std::cout << ",";
			if ((p+1)%MAX_COL==0)
				std::cout << std::endl;
	}
}
	
	
	
	
	

	
	
	

