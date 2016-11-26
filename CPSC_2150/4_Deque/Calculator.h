/*
 * Calculator.h
 *
 *  Created on: Oct 26, 2016
 *      Author: Shakir
 */

#include<iostream>
#include "Deque.h"

using namespace std;

class Calculator{
public:
	// constructor
	//precondition:
	// -
	//postcondition:
	// creates a calculator instance with empty deque
	Calculator();

	// copy constructor
	//precondition:
	// in is not null reference
	//postcondition:
	// creates an instance with a deep copy of deque of in
	Calculator(const Calculator& in);

	// destructor
	//precondition:
	// -
	//postcondition:
	// calls deque destructor
	~Calculator();

	// the calculator function which returns answer from provided string or throws
	//precondition:
	// s is not empty
	//postcondition:
	// return int total of the expression or throws on syntax or math error 
	int parse(string s);

	// printer
	//precondition:
	// -
	//postcondition:
	// calls calculate and prints the answer
	void calculate(string filename);

	// constructor
	//precondition:
	// B is not null
	//postcondition:
	// copies the fields of B to this
	Calculator& operator =(const Calculator B);
private:
	Deque d;
};
