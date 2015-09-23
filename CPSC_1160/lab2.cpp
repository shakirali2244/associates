//program to print elements of an array properly per line
// Shakir Ali , CPSC 1160, Lab 2
#include <iostream>
#include <cstdlib>

void fillRandArray(int A[], int n, int maxNum);
// fills an array A with n random numbers ranged 0 < x <= maxNum
// precondition: n is the number of elements in the array, n = MAX_STUDENTS
// postcondition: A has n random numbers from 0 up to and including maxNum

void fillRandArrayUint(unsigned int A[], int n, int maxNum);
// fills an array A with n random numbers ranged 0 < x <= maxNum
// precondition: n is the number of elements in the array, n = MAX_STUDENTS
// postcondition: A has n random numbers from 0 up to and including maxNum

void printArray(const int A[], int n, int entriesPerLine);
// prints to standard output the n elements of A such that there are at
// most entriesPerLine in each line
// precondition: n is the number of elements in A, n = MAX_STUDENTS

void printArrayUint(const unsigned int A[], int n, int entriesPerLine);
// prints to standard output the n elements of A such that there are at
// most entriesPerLine in each line
// precondition: n is the number of elements in A, n = MAX_STUDENTS

using namespace std;

 
int main() {
   const int MAX_STUDENTS = 100;
   int totalStudents,A[MAX_STUDENTS];
   unsigned int B[MAX_STUDENTS];
   
   
   cout << "Enter the number of students: " << endl;
   cin >> totalStudents;
   if ( !cin || totalStudents > MAX_STUDENTS) {
      cout << "input NaN or number of students is more than 100 \n";
      return 0;
   }
   
   fillRandArray(A, totalStudents, 12);
   printArray(A, totalStudents, 5);
   
   
   cout << " --------------------array with values more than twice RAND_MAX---------------------- " << endl;
   
   fillRandArrayUint(B, totalStudents, RAND_MAX);
   printArrayUint(B, totalStudents, 5);
   
   
   cout << "largest number that can be produced by this g++ compiler in the env is :" <<  RAND_MAX;
   return 0;
}

void fillRandArray(int A[], int n, int maxNum){
   for (int i = 0 ; i < n ; i++){
      A[i]=rand() % (maxNum);
   }
   return;
}

void fillRandArrayUint(unsigned int A[], int n, int maxNum){
   for (int i = 0 ; i < n ; i++){
      unsigned int seededInt = rand() % maxNum + rand() % maxNum;
      A[i] = seededInt;
   }
   return;
}

void printArray(const int A[], int n, int entriesPerLine = 7){
   for (int i = 0 ; i < n ; i++){
      cout << A[i] << " ";
      if ((i+1) % entriesPerLine == 0) cout << endl;
   }
   return;
}

void printArrayUint(const unsigned int A[], int n, int entriesPerLine = 7){
   for (int i = 0 ; i < n ; i++){
      cout << A[i] << " ";
      if ((i+1) % entriesPerLine == 0) cout << endl;
   }
   return;
}
   
   
   

