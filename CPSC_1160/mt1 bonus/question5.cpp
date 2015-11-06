// Shakir Ali , 100268078
//CPSC 1160, Midterm 1 BONUS question 5
//program inserts the unsorted array in a sorted one
//limitations - 
// bugs  -  no known bugs
// references  - insertion sort algorithm printArray from previous assignment

#include <iostream>
#include <cstdlib>

using namespace std;

int insert(int A[],int nA, const int B[], int nB);
void printArray(int B[], int n);


int main(){
	
	
	const int MAX_ELEMS = 20;
	
	// testing empty array and nA + nB < MAX_ELEMS
	const int nA = 0;
	int A[MAX_ELEMS] = {};
	
	cout << "A \n";
	printArray(A,nA);
	cout << endl;
	
	const int nB = 19;	
	int B[nB];	
	//fill B with 0-19 randomly
	for (int i =0 ; i < nB; i++){
		B[i] = rand() %20;
	}
	
	cout << "B  \n";
	printArray(B,nB);
	cout << endl;
	
	int nAnew = insert(A,nA,B,nB);
	
	cout << "A after insertion \n";
	printArray(A,nAnew);
	cout << endl;
	
	cout << "------------------- \n";
	
	// testing A with an odd size and first elem of B larger than
	const int nc= 7;
	int C[MAX_ELEMS] = {4,5,7,8,9,10,12};
	
	cout << "A \n";
	printArray(C,nc);
	cout << endl;
	
	const int nd = 13;	
	int D[nd];	
	D[0] = 66;
	//fill D with 0-19 randomly from index 1
	for (int i =1 ; i < nd; i++){
		D[i] = rand() %20;
	}
	
	cout << "B  \n";
	printArray(D,nd);
	cout << endl;
	
	int nAnew2 = insert(C,nc,D,nd);
	
	cout << "A after insertion \n";
	printArray(C,nAnew2);
	cout << endl;
	
	// testing A with an even size and negative integers and B with negative integeres
	const int ne= 6;
	int E[MAX_ELEMS] = {-10,-8,-6,-5,-4,2};
	
	cout << "A \n";
	printArray(E,ne);
	cout << endl;
	
	const int nf = 14;	
	int F[nf];	
	//fill D with -1 to -20 randomly
	for (int i = 0  ; i < nf; i++){
		F[i] = -(rand() %20 +1);
	}
	
	cout << "B  \n";
	printArray(F,nf);
	cout << endl;
	
	int nAnew3 = insert(E,ne,F,nf);
	
	cout << "A after insertion \n";
	printArray(E,nAnew3);
	cout << endl;
	
	
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////
// insert unsorted array in a sorted array
//precondition:
//A is sorted nA is size of A, nB is size of B
// postcondition:
//inserts the values of be in A and returns size of new A
int insert(int A[],int nA, const int B[], int nB){
	int temp;
	//append arr B to A
	for (int i = nA; i < nA+nB; i++){
		A[i] = B[i-nA];
	}
	//do insertion sort but starting from first appended element
	for( int i=nA; i< nB+nA; i++){
		int j = i;
		while (j > 0 && A[j] < A[j-1]){
			  temp = A[j];
			  A[j] = A[j-1];
			  A[j-1] = temp;
			  j--;
			  }
	}
	return nA+nB;
}
////////////////////////////////////////////////////////////////////////////////////////////////////

// print array in a pretty way
//precondition:
//n is the length of array
// postcondition:
// prints 4 elements per row
void printArray(int B[], int n){
	const int MAX_COL = 4;
	for (int p = 0 ; p <  n; p ++ ){
			cout << B[p];
			if (!(p== n-1))
				cout << ",";
			if ((p+1)%MAX_COL==0)
				cout << endl;
	}
}