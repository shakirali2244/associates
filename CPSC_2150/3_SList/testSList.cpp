/*
 * testSList.cpp
 *
 *  Created on: Oct 19, 2016
 *      Author: Shakir
 */

#include "SList.h"
#include "SList.cpp"
#include <iostream>

using namespace std;

int main(){
	SList<int> tmp;
	Node<int>* test = tmp.getheader();
	int level = 0;
	tmp.insert(3);
	tmp.insert(2);
	tmp.insert(3);
	tmp.insert(5);
	tmp.insert(7);
	tmp.insert(33);
	tmp.insert(77);
	tmp.insert(44);
	while(test != nullptr){
		cout << test->key << endl;
		test = test->next[level];
	}
	return 0;
}


