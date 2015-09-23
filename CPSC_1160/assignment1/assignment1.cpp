//program that is a CLI to calculate inflation rate
// Shakir Ali , CPSC 1160, Assignment 1
#include <iostream>
#include <iomanip> /* cout::fixed, cout::setprecision  */
#include <math.h>   /* isinf */

double inflationRate (double lastYearPrice, double currentYearPrice);
// computes inflationrate
//precondition:
// input are double
// postcondition:
// returns inflation rate for that year


int main(){
	using namespace std;
   
   //setting all couts to fixed number of decimal places
   std::cout << std::fixed; 
   std::cout << std::setprecision(2);
	
	string choice ="Y";
	double lastYearPrice;
	double currentYearPrice;
	
	cout <<  "Do you want to calculate inflation rate? (y/n)" << endl;
	cin >> choice ;
   
   //while loop to calculate inflation until user wants
	while (choice == "Y" || choice == "y") {
		cout << "Enter Price of the product from last year in CAD" << endl;
		cin >> lastYearPrice;
      
      //I didnt know we can ignore NaN for this assignment so just added a failsafe anyways
		if (cin){       
			cout << "Enter Price of the product for current year in CAD" << endl;
			cin >> currentYearPrice;
         
			if(cin){
				double rate = inflationRate(lastYearPrice,currentYearPrice);
            
            //Print According to the return value
            if (isinf(rate))  // for 1/0 case which case
               cout << "Inflation rate for the product tends to Infinity" << endl;
            else if (rate != rate) //for 0/0 case which is not a number
               cout << "Inflation rate for the product is an Indeterminate" << endl;
            else 
               cout << "Inflation rate for the product is " << rate << "%" << endl;
            
			}else{            //will enter if lastYearPrice was NaN
				cin.clear();   //clear the error bit on cin
				cin.ignore();  // ignore more lines generated form error to clean cin for next iteration of while
				cout << "INVALID INPUT!!" ; //dont calculate inflation reate since invalid input , carry on with next product
			}
         
		}else{
			cin.clear();
			cin.ignore();
			cout << "INVALID INPUT!!" ;
		}
		cout << "-------------------------------------------------------------" << endl; 
		cout <<  "Do you want to calculate inflation rate for another product? (y/n)" << endl;
		cin >> choice ;
	}
   
   
	return 0;
}

double inflationRate (double lastYearPrice, double currentYearPrice){
	double rate = ((currentYearPrice - lastYearPrice)/lastYearPrice)*100;
	return rate;
}
