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
	int parse(string s);
	void calculate(string filename);
private:
	Deque d;

};
