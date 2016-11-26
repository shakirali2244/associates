#include "Calculator.h"
#include<iostream>

// tester for calculator with input.txt
int main(){
	string tmp;
	getline(cin, tmp);
	
	while(tmp.compare("quit")){
		Calculator a;
		Calculator b = a = a;
		Calculator c(b);
		try{
			c.calculate(tmp);
		}catch( char const* e) {
			cout  << e << endl;
		}
		getline(cin, tmp);
	}
		
	
	return 0;
}
