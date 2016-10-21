#include "Template.h"
#include <iostream>

using namespace std;
int main(){
	Template l1;
	Template l2;
	cout << l2.getFirst() << endl;
	l2.append('a');
	l2.append('b');
	l2.append('a');
	l2.append('4');
	l2.append('a');
	l2.printList(cout);
	//l2.reverse();
	l2.printList(cout);
	l2.remove('a');
	cout << "l2.search('a')" << l2.search('a') << endl;
	l2.printList(cout);
	l2.remove('a');
	cout << "l2.search('a')" << l2.search('a') << endl;
	l2.printList(cout);
	cout << "l2.remove('a')" << l2.remove('a') << endl;
	cout << "l2.remove('a')" << l2.remove('a') << endl;
	cout << "l2.search('a')" << l2.search('a') << endl;
	//cout << "l1.isEmpty() = " << l1.isEmpty() <<" l1.length() = " <<  l1.length() << endl;
	cout << "l2.isEmpty() = " << l2.isEmpty() <<" l2.length() = " <<  l2.length() << endl;	
	return 0;
}
