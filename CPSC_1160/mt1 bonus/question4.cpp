// Shakir Ali , 100268078
//CPSC 1160, Midterm 1 BONUS question 4
//program checks if string is proper with numbers and ','
//limitations - compiler gives one warning for a non reachable case
// bugs  -  no known bugs
// references  - areDigits is from midterm answer

#include <iostream>

using namespace std;

bool isDigit(char a);
bool areDigits(const string& str, int low, int high);
bool isProper(const string& str);
bool isProper(const string& str,int low,int high);



int main(){
	//testing all three functions
	cout<< '7' << " isDigit " <<isDigit('7') << endl;
	cout<< 'a' << " isDigit "  <<isDigit('a')<< endl;
	cout<< '0' << " isDigit "  <<isDigit('0')<< endl;
	cout<< "12345,0,3 " << " areDigits "  <<areDigits("12345",0,3)<< endl;
	cout<< "a,0,0 " << " areDigits "  <<areDigits("a",0,0)<< endl;
	cout<< "g12345H,1,5 " << " areDigits "  <<areDigits("g12345H",1,5)<< endl;
	cout<< ",0,0 " << " areDigits "  <<areDigits("",0,0)<< endl;
	cout <<"10,000 isProper " << isProper("10,000") << endl;
	cout <<"5,444,333,222,111 isProper " << isProper("5,444,333,222,111") << endl;
	cout <<"123,456 isProper " << isProper("123,456") << endl;
	cout <<"456 isProper " << isProper("456") << endl;
	cout <<"6 isProper " << isProper("6") << endl;
	cout <<"aaa,bbb isProper " << isProper("aaa,bbb") << endl;
	cout <<"12.345 isProper " << isProper("12.345") << endl;
	cout <<",123 isProper " << isProper(",123") << endl;
	cout <<"12, isProper " << isProper("12,") << endl;
	cout <<",12, isProper " << isProper(",12,") << endl;
	cout <<", isProper " << isProper(",") << endl;
	cout <<" isProper " << isProper("") << endl;
}


//checks if char is a single base10 digit
//precondition
//char is not empty
//postcondition
//returns true or false if the char is a digit
bool isDigit(char a){
	int t = a - '0';
	return (t<10 && t > -1);
}

//checks if passed string has digits from low to high index
//precondition
// the data types are correct
//postcondition
//returns true or false based on range chars isDigit or not
bool areDigits(const string& str, int low, int high){
	if(str.length() == 0)
		return true;
	if(low > high)
		return true;
	else
		return isDigit(str[low]) && areDigits(str,low+1,high);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//checks if passed string isProper number with ,
//precondition
// str is string data type
//postcondition
//calls the helper functions and returns if string is proper
bool isProper(const string& str){
	return isProper(str,0,str.length()-1);
}

//helper function for isProper
//precondition
// high >= low
//postcondition
//returns true or false with recursive calls done correctly and data checked
bool isProper(const string& str,int low,int high){
	if(str.length() == 0)
		return true;
	if(low == high)
		return isDigit(str[high]);
	else if(high > low){
		if((str.length() - high)%4 ==0)
			return (str[high] == ',') && isProper(str,low,high-1);
		
		else
			return isDigit(str[high]) && isProper(str,low,high-1);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////
			