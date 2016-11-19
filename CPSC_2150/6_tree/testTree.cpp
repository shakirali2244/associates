// Shakir Ali , 100268078
//CPSC 2150, Assignment 6
//Polynomial in Binary Search Tree
//
// bugs  -  degreeCoeff returns 0 if degree not found
// references  - Text Book /

#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
	Tree t1;
	Tree t2;
	cin >> t1;
	cin >> t2;
	
	int eval;
	int degreeCoeff;
	cin >> eval;
	cin >> degreeCoeff;
	
	cout << " Polynomials are as follows  \n";
	cout  << t1 t<< endl << t2 << endl;
	cout  << " isZero = " << endl << t1.isZero() << endl;
	cout  << " isZero = " << endl << t2.isZero() << endl;
	cout  << " evaluate("<<eval<<") = " << endl << t1.evaluate(eval)<< endl;
	cout  << " evaluate("<<eval<<") = " << endl << t2.evaluate(eval) << endl;
	cout  << " degree = " << endl << t1.degree() << endl;
	cout << " degree = " << endl << t2.degree() << endl;
	cout  <<  "degreeCoeff("<<degreeCoeff << ") = " << endl << t1.degreeCoeff(degreeCoeff) << endl; 
	cout  <<  "degreeCoeff("<<degreeCoeff << ") = " << endl << t2.degreeCoeff(degreeCoeff) << endl; 
	Tree tmp =  t1+t2;
	cout << " t1 + t2 = "<< endl;
	cout << tmp;
	cout << endl;	
}
	