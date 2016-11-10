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
	friend ostream& operator << (ostream& out,const Poly A);
private:
	Term* head;

};
