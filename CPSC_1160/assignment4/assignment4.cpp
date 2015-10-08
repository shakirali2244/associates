// Shakir Ali , 100268078
//CPSC 1160, Assignment 3
//program that sorts an array
//program cannot accept letters as inputs 
//no bugs 
//no references

#include <iostream>
#include <cstdlib>
#include <time.h>


void sort(int  A[], int n);
void fillRand(int  (&B)[17], int n);


using namespace std;


int main(){
	const int SIZE = 4;
	const int RAND_SIZE = 17;
	
	int A [SIZE] = {5,5,1,5};
	sort(A, SIZE);
	
	int B [RAND_SIZE];
	
	fillRand(B,RAND_SIZE);
	
	cout << endl << "Random generated array Array: " <<endl;
	for (int p = 0 ; p < RAND_SIZE; p ++ ){
			cout << B[p];
			if (!(p==RAND_SIZE-1))
				cout << ",";
			if ((p+1)%4==0)
				cout << endl;
	}
	
	sort(B,RAND_SIZE);
	
}


void sort(int A[], int n){
	for (int i = 0 ; i < n/2 ; i++){
		for (int k = i; k < n-1; k++){
			if(A[k+1] < A[k]){
				int temp = A[k];
				A[k] = A[k+1];
				A[k+1] = temp;
			}
		}
		//for (int p = 0 ; p < n; p ++ ){
		//	cout << A[p] << ",";
		//}
		//cout << endl;
		for (int l = n-i-2; l  > 0 ; l--){
			if(A[l] < A[l-1]){
				int temp = A[l];
				A[l] = A[l-1];
				A[l-1] = temp;
			}
		}
		//for (int q = 0 ; q < n; q ++ ){
		//	cout << A[q] << ",";
		//}
		//cout << endl;
	}
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

void fillRand(int  (&B)[17], int n){
	srand (time(NULL));
	for (int i=0; i < n; i++){
		int num = rand() % RAND_MAX +1;
		B[i]=num;
	}
}
	
	
	
	
	

	
	
	

