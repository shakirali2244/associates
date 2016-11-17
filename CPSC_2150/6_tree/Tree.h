#include <iostream>

struct Node{
	double coeff;
	double expo;
	Node* left;
	Node* right;
}


class Tree{
public:
	Tree();
	Node* cons(double coeff, double expo, Node* left, Node* right);
	void add(double coeff, double expo);
	friend ostream& operator << (ostream& out,const Tree A);
	friend istream& operator >> (istream& out,const Tree A);
	friend Poly operator +(Tree A, Tree B);
private:
	Node tree;
}
	
	
	

	