#include "Calculator.h"
#include<cstdlib>
#include<string>
#include<iostream>
#include<cmath>

using namespace std;

// constructor
//precondition:
// -
//postcondition:
// creates a calculator instance with empty deque
Calculator::Calculator(){
	Deque tmp; 
	d = tmp; // call deque assignment operator
}

// copy constructor
//precondition:
// in is not null reference
//postcondition:
// creates an instance with a deep copy of deque of in
Calculator::Calculator(const Calculator& in){
	d = in.d; // call deque assignment operator for deep copy
}

// destructor
//precondition:
// -
//postcondition:
// calls deque destructor
Calculator::~Calculator(){
	//calls deque destructor
}

// the calculator function which returns answer from provided string or throws
//precondition:
// s is not empty
//postcondition:
// return int total of the expression or throws on syntax or math error 
int Calculator::parse(string in){
	int size = in.length();
	for(int i=0; i<size; i++){
		char cur = in[i];
		string tmp = "";
		//parse single or more digit number and push to deque
		if(cur >= '0' && cur <= '9'){
			while(cur >= '0' && cur <= '9'){
				tmp += cur;
				i++;
				cur= in[i];
			}
			//fall back one place to check adjoint operator
			cur = in[i-1];
			if(cur >= '0' && cur <= '9'){
				i--;
			}
			d.pushFront(std::stoi(tmp));
		}
		// do nothing on space
		else if(cur == ' '){
		}
		//pop final answer
		else if(cur == '='){
			if (d.size() != 1){
				throw "INVALID expression, Too many numbers";
			}
			return d.popFront()->key;
		}
		//else pop oprands and do oprations push or throw error
		else {
			if (cur == '+'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre + pos;
				d.pushFront(ans);
			}
			else if (cur == '-'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre - pos;
				d.pushFront(ans);
			}
			else if (cur == '*'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre * pos;
				d.pushFront(ans);
		     }

			if (cur == '/'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				if(pos == 0){
					throw "Math error, cannot divide by 0";
				}
				int ans = pre / pos;
				d.pushFront(ans);
			}
			if (cur == '^'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = (int) pow( pre, pos);
				d.pushFront(ans);
			}
		}
	}
	throw "Empty input";
	return -1;
}

// printer
//precondition:
// -
//postcondition:
// calls calculate and prints the answer
void Calculator::calculate(string f){
	 int ans = parse(f);
	 cout << f << ans << endl;
}

// constructor
//precondition:
// B is not null
//postcondition:
// copies the fields of B to this
Calculator& Calculator::operator =(const Calculator B){
	if(this == &B){
		return *this; //take care of a = a;
	}
	d = B.d; //deep copy deque
	return *this;
}

