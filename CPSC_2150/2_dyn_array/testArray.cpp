#include <iostream>
#include "Array.h"

using namespace std;
int main(){
	Array l1; 
	cout << "l1.isEmpty() = " << l1.isEmpty() <<" l1.length() = " <<  l2.length() << endl;
	l2.remove('a');
	
	
	Array l2;
	l2.cons('x');
	l2.printList(cout);
	l2.remove('x');
	l2.printList(cout);
	
	l2.append('a');
	l2.append('b');
	l2.append('a');
	l2.printList(cout);
	
	l2.append('4');
	l2.append('a');
	l2.printList(cout);
	l2.remove('x');
	l2.printList(cout);
	//l2.reverse();
	l2.cons('f');

	cout << "l2.search('4')" << l2.search('4') << endl;
	l2.printList(cout);
	//l2.remove('a');
	cout << "l2.search('a')" << l2.search('a') << endl;
	l2.printList(cout);
	//cout << "l2.remove('a')" << l2.remove('a') << endl;
	//cout << "l2.remove('a')" << l2.remove('a') << endl;
	cout << "l2.search('a')" << l2.search('a') << endl;
	//cout << "l1.isEmpty() = " << l1.isEmpty() <<" l1.length() = " <<  l1.length() << endl;
	cout << "l2.isEmpty() = " << l2.isEmpty() <<" l2.length() = " <<  l2.length() << endl;	
	return 0;
}
