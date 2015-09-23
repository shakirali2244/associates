//program that checks the birthday paradox .
// Shakir Ali , CPSC 1160, Assignment 2
#include <iostream>
#include <cstdlib>

void generateBirthdays (int birthdays[], int N);
// generates array with random birthdays for total number of people
//precondition:
//N is the length of the birthdays array
// postcondition:
// stores random values of birthdays in the passed array

bool verifySameBirthdays (const int birthdays[], int N);
// array to check if at least two people have same birthdays
//precondition:
//N is the length of the birthdays array
// postcondition:
// returns true or false weather at least two people have same birthdays

int main(){
	using namespace std;
	int N; //Total number of people in the room
	int T; //Number of times the user wants to repeat generating people in room 
		// with random birthdays for checking probablity of 2 people with same birthdays
	const int MAX_PEOPLE = 4000;
	
	cout << " Enter number of people in the room " << endl;
	cin >> N;
	
	if ( N > MAX_PEOPLE ) {
		cout << "There Cannot be more than 4000 people in the room " << endl;
		return 0;
	}
	
	cout << " Enter number of tries you want to generate random people " << endl;
	cin >> T;
	
	int birthdays[MAX_PEOPLE];
	
	int C = 0; //C is the counter which would give count of number of times atleast 2 people had 
			//same birthdays out of different tries
	
	for (int i = 0 ; i < T ; i++){
		generateBirthdays(birthdays, N);
		for ( int i = 0; i < N; i++){
			cout << birthdays[i] << endl;
		}
		if (verifySameBirthdays(birthdays, N)) {
			C+=1;
			cout << "found a match " << endl; 
		}
		
		cout << " ----------------" << endl;
	}
	
	cout << " N and C/T is " << N << " " << double(C)/double(T) << endl;
	return 0;
	
}

void generateBirthdays (int birthdays[],int totalPeople){
	for (int i = 0; i < totalPeople ; i++){
		birthdays[i]=rand() % 366 + 1;
	}
	return;
}

bool verifySameBirthdays (const int birthdays[],int totalPeople){
	for (int i = 0; i < totalPeople ; i++){
		for (int j = 0; j < totalPeople; j++) {
			if (i != j && birthdays[i] == birthdays [j])
				return true;
		}
	}
	return false;
}
	