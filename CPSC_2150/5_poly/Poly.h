#include <iostream>

using namespace std;

struct Term {
 int coeff;
 int deg_x;
 int deg_y;
 Term* next;
};

class Poly{
public:
	Poly();
	Term* cons(int coeff, int x, int y, Term* next);
	Term* add(int coeff, int x, int y);
	int getSize(Term* in);
	Term* getHead();
	void setHead(Term* head);
	void sortHelper();
	Term* mergeSort(Term* in);
	Term* merge(Term* left, Term* right);
	void diffX();
	void diffY();
	friend ostream& operator << (ostream& out,const Poly A);
	friend Poly operator +(Poly A, Poly B);
private:
	Term* head;
};
