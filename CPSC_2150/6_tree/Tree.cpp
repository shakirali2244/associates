#include <iostream>
#include "Tree.h"



Tree::Tree(){
	tree = nullptr;
}

Node* Tree::cons(double coeff, double expo, Node* left, Node* right);\{
	return new Node {coeff, expo, left, right};
}

void Tree::add(double coeff, double expo){
	Node entry = cons(coeff, expo, nullptr, nullptr);
	if (tree = nullptr){
		tree = entry;
		return;
	}
	Node* util = tree;
	
	while(util!= nullptr){
		if (util->expo < entry->expo){
			
	
friend ostream& operator << (ostream& out,const Tree A);
friend istream& operator >> (istream& out,const Tree A);
friend Poly operator +(Tree A, Tree B);