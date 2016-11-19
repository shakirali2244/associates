#include <iostream>

using namespace std;
struct Node{
	int coeff;
	int expo;
	Node* left;
	Node* right;
};


class Tree{
public:
	Tree();
	Tree(const Tree& obj);
	void copyHelper(Node*);
	Node* cons(int coeff, int expo, Node* left, Node* right);
	Node* getTree()const;
	void add(int coeff, int expo);
	bool isZero(Node* tree);
	bool isZero();
	void deleteTree();
	void deleteTreeHelper(Node* &tree);
	int degree();
	int degreeCoeff();
	int evaluate(int x);
	int evaluateHelper(Node* tree,int x);
	void printHelper(ostream& out, Node* top) const;
	friend ostream& operator << (ostream& out,const Tree A);
	friend istream& operator >> (istream& out,const Tree A);
	void addHelper(Tree &t, Node*);
	friend Tree& operator +(const Tree A,const Tree B);

private:
	Node* tree;
};
	
	
	

	