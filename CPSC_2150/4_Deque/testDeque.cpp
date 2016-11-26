/*
 * testDeque.cpp
 *
 *  Created on: Oct 20, 2016
 *      Author: sali09
 */
#include "Deque.h"
#include <iostream>

using namespace std;
//comprehensive tests on deque functions
int main(){
	Deque d1;
	try{
		cout << "d1.popBack() = INVALID" << endl;
		cout << d1.popBack()->key << endl ;
	}catch( char const* e) {
		cout << e << endl;
	}
	Deque d2;
	Deque d3(d2);
	
	try{
		cout << "d3.peekBack() = INVALID" << endl;
		cout << d3.peekBack()->key << endl ;
	}catch( char const* e) {
		cout << e << endl;
	}
	
	cout << "d3.isEmpty() =  1" << endl << d3.isEmpty() << endl;
	
	d1.pushFront(-2);
	d1.pushFront(44);
	d1.pushFront(1);
	d1.pushBack(5);
	d1.pushBack(44);
	d1.pushBack(11);
	d1.pushBack(2);
	
	d3.pushFront(66);
	d3.pushBack(-22);
	
	d2.pushBack(1);
	d2.pushFront(2);
	
	cout << "d1.peekFront() = 1"  << endl << d1.peekFront()->key << endl;
	cout << "d1.popFront() = 1"  << endl << d1.popFront()->key << endl ;
	cout << "d1.popBack() = 2"  << endl << d1.popBack()->key << endl;
	cout << "d1.peekBack() = 11"  << endl << d1.peekBack()->key << endl;
	cout << "d2.peekFront() = 2"  << endl << d2.peekFront()->key << endl;
	cout << "d2.popFront() = 2"  << endl << d2.popFront()->key << endl;
	cout << "d2.peekBack() = 1"  << endl << d2.peekBack()->key << endl;
	cout << "d2.popBack() = 1"  << endl << d2.popBack()->key << endl;
	cout << "d2.size() = 0" << endl << d2.size() << endl;
	try{
		cout << "d2.peekFront() = INVALID" << endl;
		cout << d2.peekFront()->key << endl ;
	}catch( char const* e) {
		cout << e << endl;
	}
	Deque d4 = d3 = d3;
	
	
	cout << "d3.popFront() = 66"  << endl << d3.popFront()->key << endl ;
	cout << "d3.size() = 1" << endl << d3.size() << endl;
	cout << "d4.size() = 2" << endl << d4.size() << endl;
	cout << "d3.peekFront() = -22" << endl << d3.peekFront()->key << endl ;
	cout << "d4.peekFront() = 66" << endl << d4.peekFront()->key << endl ;
	cout << "d4.popFront() = 66" << endl << d4.popFront()->key << endl ;
	cout << "d4.popFront() = -22" << endl << d4.popFront()->key << endl ;
	try{
		cout << "d4.popFront() = INVALID" << endl;
		cout << d4.popFront()->key << endl ;
	}catch( char const* e) {
		cout << e << endl;
	}
	
	
}



