#include <iostream>
#include "Poly.h"

using namespace std;


int main(){
	Poly a;
	Poly b;
	a.add(5,2,1);
	a.add(-2,4,5);
	a.add(5,6,7);
	b.add(-5,2,1);
	b.add(6,-4,5);
	b.add(5,6,7);
	b.add(0,6,-7);
	b.add(11,11,11);
	cout << " a = " << a;
	cout << " b = " << b;
	
	a.sortHelper();
	b.sortHelper();
	
	Poly C = a+b;
	cout << " a = " << a;
	cout << " b = " << b;
	cout << " c = " << C;
	
	a.diffX();
	b.diffY();
	

	cout << " a = " << a;
	cout << " b = " << b;
	
	return 1;
}

