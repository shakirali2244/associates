#include<string>
#include<iostream>
#include<cmath>

void a( const int& b);
using namespace std;
int main(){
	double d = pow(9,2);
	cout << d;
}

void a(){
	char a = 'A';
	cout << int(a) <<endl;
	bool state = true;
	cout << state <<endl;
	state = false;
	cout <<state <<endl;
	state = 99999;
	cout << state << endl;
	state = "asdasda";
	cout << state << endl;
}

void b(){
	string s = "asdsad";
	cout << s.length() << s[1] <<endl;
	
	s[1] = 'A';
	
	cout << s[1] << endl;
	
	const int MAX = 32222;
	const char A = 100;
	const int T = 'A';
	
	cout << MAX << A << T << endl; 
	const int a = 5;
	const int b = 14;
	cout << b/a<< endl <<static_cast<double>(b)/a <<
	endl <<double(b/a)<<endl;
	int c= -4;
	cout << c ;
	
		
	cout << (5<0) <<endl;
	cout << (-1<0) << endl;
	int x = 5;
	int y = 3 ;
	int z = 60;
	cout <<((z <=50));
	cerr << "ASdasd";
	cerr << "asdd";
	
	}

