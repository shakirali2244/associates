// Shakir Ali , 100268078
//CPSC 1160, Assignment 3
//program that simulates and checks the birthday paradox .
//program cannot accept letters as inputs 
//no bugs 
//no references

#include <iostream>
#include <cstdlib>

using namespace std;

void generateBirthdays (int birthdays[], int N);
bool verifySameBirthdays (const int birthdays[], int N);
void simlationForRange(int start);

int main(){
   
	int N; //Total number of people in the room
	int T; //Number of times the user wants to repeat generating people in room 
		// with random birthdays for checking probablity of 2 people with same birthdays
	const int MAX_PEOPLE = 4000; // only 4000 people can fit inside a room 
   const int MIN_TRIES = 3000; // minimum tries is 3000 so that our C/T is as accruate
	
	cout << "Enter number of people in the room " << endl;
	cin >> N;
	
	cout << "Enter number of tries (more than 3000) you want to generate random people  " << endl;
	cin >> T;
	
   if ( N > MAX_PEOPLE || T < MIN_TRIES ) {
		cout << "There Cannot be more than 4000 people in the room OR less than 3000 tries " << endl;
		return 0;
	}
   
	int birthdays[MAX_PEOPLE]; //birthdays is an int array which stores 1 to 365 indicating the birthday of a person.
   
   cout << "Taking number of people as " << N << endl;
	
	int C = 0; //C is the counter which would give count of number of times atleast 2 people had 
			//same birthdays out of different tries
	
	for (int i = 0 ; i < T ; i++){
		generateBirthdays(birthdays, N); //fill in the array with 1 to 365
		if (verifySameBirthdays(birthdays, N)) { //check if 2 people have same birthday
			C+=1; 
		}
	}
	
	cout << "if N = " << N << ", C/T = " << double(C)/double(T) << endl;
   
   int start; 
   cout << "enter the start for range for running the simulation for which would be N for the simulation" << endl;; 
   cin >> start;
   
   simlationForRange(start); //start simulation
   
	return 0;
	
}

// generates array with random birthdays for total number of people
//precondition:
//N is the length of the birthdays array
// postcondition:
// stores random values of birthdays in the passed array
void generateBirthdays (int birthdays[],int totalPeople){
	for (int i = 0; i < totalPeople ; i++){
		birthdays[i]=rand() % 365 + 1;
	}
	return;
}

// array to check if at least two people have same birthdays
//precondition:
//N is the length of the birthdays array
// postcondition:
// returns true or false weather at least two people have same birthdays
bool verifySameBirthdays (const int birthdays[],int totalPeople){
	for (int i = 0; i < totalPeople ; i++){
		for (int j = 0; j < totalPeople; j++) {
			if (i != j && birthdays[i] == birthdays [j])
				return true;
		}
	}
	return false;
}

//function to run a simulation of the probablity check for birthday paradox for a range of values for N
//precondition:
// start is an integer
//postcondition:
//prins values of N and corresponding values of C/T 
void simlationForRange(int start){
   const int MAX_PEOPLE = 4000;
   const int MIN_TRIES = 3000;
   for (int i = start ; i <= 30 ; i++){
      cout << endl;
      cout << "Taking number of people as " << i << endl;
      int birthdays[MAX_PEOPLE]; //max number of people can be 4000
      int C = 0;
      for (int j = 0 ; j < MIN_TRIES ; j++){ // there will be 3000 tries 
		   generateBirthdays(birthdays, i);
		   if (verifySameBirthdays(birthdays, i)) {
		   	C+=1;
            //cout << birthdays[j] << endl;
		   }
	   }
	   cout << "if N = " << i << ", C/T = " << double(C)/double(MIN_TRIES) << endl;
   }
}