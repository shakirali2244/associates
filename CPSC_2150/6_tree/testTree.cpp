#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
	Tree t;
	
	cout <<  t.isZero() <<endl;
	//cout <<  t1.isZero() <<endl;
	t.add(0,1);
	t.add(6,2);
	t.add(-5,1);
	t.add(1,4);
	
	//t1.add(1,-4);
	//t1.add(-5,6);
	
	//Tree A = ;
	
	
	Tree t1(t);
	
	cout << t1.getTree()->coeff;
	
	//cout << t << endl << t1 << endl << endl;	
	//cout << t.evaluate(2) << " "<<  t.evaluate(-5)  << endl;
	
	//cout << t.degree() << " "<<  t.degreeCoeff()  << endl;
	
	//t.deleteTree();
	
	//
	
}
	