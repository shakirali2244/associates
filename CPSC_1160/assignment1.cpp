//program that calculates x to the power of n .
// Shakir Ali , CPSC 1160, Assignment 1
#include <iostream>

double inflationRate (double lastYearPrice, double currentYearPrice);
// computes inflationrate
//precondition:
// input are double
// postcondition:
// returns inflation rate for that year


int main(){
	using namespace std;
	
	string choice ="Y";
	double lastYearPrice;
	double currentYearPrice;
	
	cout <<  "Do you want to calculate inflation rate? (y/n)" << endl;
	cin >> choice ;
	
	while (choice == "Y" || choice == "y") {
		cout << "Enter Price of the product from last year in CAD" << endl;
		cin >> lastYearPrice;
		if (cin){
			cout << "Enter Price of the product for current year in CAD" << endl;
			cin >> currentYearPrice;
			if(cin){
				cout << "Inflation rate for the product is " << inflationRate(lastYearPrice,currentYearPrice) << "%" << endl;
			}else{
				cin.clear();
				cin.ignore();
				cout << "INVALID INPUT!!" ;
			}
		}else{
			cin.clear();
			cin.ignore();
			cout << endl; 
			cout << "INVALID INPUT!!" ;
		}
		cout << endl << endl; 
		cout <<  "Do you want to calculate inflation rate for another product? (y/n)" << endl;
		cin >> choice ;
	}
	return 0;
}

double inflationRate (double lastYearPrice, double currentYearPrice){
	double rate = (currentYearPrice - lastYearPrice)/lastYearPrice*100;
	return rate;
}
