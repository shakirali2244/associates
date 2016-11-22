#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Poly.h"

using namespace std;


int main(){
	Poly a;
	Poly b;
	
	ifstream myReadFile;
	myReadFile.open("3.txt");
	char output[100];
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
		myReadFile >> output;
		int coeff;
		int deg_x;
		int deg_y;
		int terms;
		terms = atoi(output);
		//cout << terms << endl;
		for(int i=0;i<terms;i++){
			myReadFile >> output;
			coeff = atoi(output);
			myReadFile >> output;
			deg_x = atoi(output);
			myReadFile >> output;
			deg_y = atoi(output);
			a.add(coeff,deg_x,deg_y);
		}
		myReadFile >> output;
		terms = atoi(output);
		//cout << terms << endl;
		for(int i=0;i<terms;i++){
			myReadFile >> output;
			coeff = atoi(output);
			myReadFile >> output;
			deg_x = atoi(output);
			myReadFile >> output;
			deg_y = atoi(output);
			b.add(coeff,deg_x,deg_y);
		}
	}
	}
	myReadFile.close();
	
	a.sortHelper();
	b.sortHelper();
	
	Poly C = a+b;
	cout << " a = " << a;
	cout << " b = " << b;
	cout << " a + b = " << C;
	
	a.diffX();
	cout << " da/dx = " << a;
	b.diffY();
	cout << " db/dy = " << b;
	return 1;
}

