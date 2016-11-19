#include <iostream>
#include "Tree.h"

using namespace std;

Tree::Tree(){
	tree = cons(0,0,nullptr,nullptr);
}	

void Tree::copyHelper(Node* tree){
	if(tree!= nullptr){
		add(tree->coeff, tree->expo);
		copyHelper(tree->left);
		copyHelper(tree->right);
	}
}
	

Tree::Tree(const Tree &obj){
	copyHelper(obj.getTree());
}
	
	
Node* Tree::cons(int coeff, int expo, Node* left, Node* right){
	return new Node {coeff, expo, left, right};
}

Node* Tree::getTree() const{
	return tree;
}

bool Tree::isZero(){
	return isZero(tree);
}

bool Tree::isZero(Node* tree){
	if(tree != nullptr){
		return (tree->coeff == 0) && isZero(tree->left) && isZero(tree->right);		
	}else{
		return true;
	}
}

void Tree::add(int coeff, int expo){
	Node* entry = cons(coeff, expo, nullptr, nullptr);
	if (tree == nullptr){
		tree = entry;
		return;
	}
	Node* util = tree;
	
	while(util!= nullptr){
		if (util->expo < entry->expo ){
			if(util->left != nullptr){
				util=util->left;
			}else{
				util->left=entry;
				break;
			}
		}
		else if (util->expo > entry->expo ){
			if(util->right != nullptr){
				util=util->right;
			}else{
				util->right=entry;
				break;
			}
		} else{
			util->coeff = util->coeff + entry->coeff;
			break;
		}
	}
}

void Tree::deleteTree(){
	deleteTreeHelper(tree);
}

void Tree::deleteTreeHelper(Node* &tree){
	if(tree != nullptr){
		Node* left = tree->left;
		Node* right = tree->right;
		delete tree;
		tree = nullptr;
		deleteTreeHelper(left);
		deleteTreeHelper(right);
	}
}

void Tree::printHelper(ostream& out, Node* top) const{
	if(top != nullptr){
		if(top->coeff != 0){
			printHelper(out, top->left);
			if(top->coeff  >= 0){
				out << " +";
			}else{
				out << " ";
			}
			cout << top->coeff << "x^" <<top->expo;
		}
		printHelper(out,top->right);
	}
}
	
int Tree::evaluate(int x){
	return evaluateHelper(tree,x);
}
	
int Tree::evaluateHelper(Node* tree, int x){
	if (tree != nullptr){
		int tmp = tree->expo;
		int ret = tree->coeff;
		for( int i = 0; i < tmp; i++){
			ret *= x;
		}
		return ret + evaluateHelper(tree->right,x) + evaluateHelper(tree->left,x);
	}else{
		return 0;
	}
}

int Tree::degree(){
	Node* tmp = tree;
	if (tmp == nullptr) return 0;
	while(tmp->left != nullptr){
		tmp = tmp->left;
	}
	return tmp->expo;
}

int Tree::degreeCoeff(){
	Node* tmp = tree;
	if (tmp == nullptr) return 0;
	while(tmp->left != nullptr){
		tmp = tmp->left;
	}
	return tmp->coeff;
}

	
	
ostream& operator << (ostream& out,const Tree A){
	A.printHelper(out,A.tree);
	return out;
}	

void Tree::addHelper(Tree &C, Node*b){
	if(b!=nullptr){
		C.add(b->coeff,b->expo);
		addHelper(C,b->left);
		addHelper(C,b->right);
	}
}

Tree& operator +(const Tree A, const Tree B){
	Tree C(A);
	Node* right = B.tree;
	C.addHelper(C,right);
	return C;
}
	
	
	