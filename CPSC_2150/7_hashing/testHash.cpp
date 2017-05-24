//CPSC 2150 assignment 7
// Shakir Ali, 100268078
//references 
// Wikipedia pages on Linear probing and Quadratic probing
//bugs
// bug in second hash function i.e. it is not perfect and casuing wierd averages for case 2


#include "Hash.h"
#include "HashTable.h"
#include <iostream>
#include <cmath>


using namespace std;

//Size of the Table 
const int SIZE = 1999;

//number of elements in the table
const int LOADED = 1000;

//number of experiments to conduct i.e 100 different table
const int EXPERIMENTS  = 100;

//cross platform 1 second sleep, const cpu iteratins to get 1 second on the machine so that random seed is fresh, PLEASE TUNE
const int CPU_SEC = 500000000;


int main(){
	//library function class
	Hash test;
	
	//table for linear probing
	HashTable TL;
	
	//table for quadratic probing
	HashTable TQ;
	
	//table for double hashing
	HashTable TD;
	
	//fill the table 
	test.getKey(TL,true);
	
	//fill the table
	test.getKey(TQ,false);
	
	//fill the table
	test.getKeyDub(TD);
	
	int* tmpL = TL.gethead();
	int* tmpQ = TQ.gethead();
	int* tmpD = TD.gethead();
	
/*	//case (i) when x is in T for linear probing
	for(int j = 0; j< EXPERIMENTS; j++){ //do 100 experiments
		int counterarr[LOADED]; //record the counter values for each experiment for LOADED cases i.e. 1000
		int counterInd = 0;
		for(int i = 0; i < SIZE; i++){
			if(tmpL[i] != -1){
				int counter = 0;
				test.search(tmpL[i],TL,1, counter);
				counterarr[counterInd] = counter; //add the conter value for average 
				counterInd++;
			}
		}
		
		//get the average to stdout
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  << average << endl;
		
		//empty the table
		for (int i = 0; i < SIZE; i++){
			tmpL[i] = -1;
		}
		
		//wait 1 second
		for (int i = 0; i < CPU_SEC; i++){
		}
		
		//fill the array with fresh random values
		test.getKey(TL,1);
	}
*/	
/*	
	//case (i) when x is in T for quadratic probing
	for(int j = 0; j< EXPERIMENTS; j++){//do 100 experiments
		int counterarr[LOADED]; //record the counter values for each experiment for LOADED cases i.e. 1000
		int counterInd = 0;
		for(int i = 0; i < SIZE; i++){
			if(tmpQ[i] != -1){
				int counter = 0;
				test.search(tmpQ[i],TQ,false,counter);
				counterarr[counterInd] = counter; //add the conter value for average 
				counterInd++;
				}
		}
		//get the average to stdout
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  << average << endl;
		
		//empty the table
		for (int i = 0; i < SIZE; i++){
			tmpQ[i] = -1;
		}
		
		//wait 1 second
		for (int i = 0; i < CPU_SEC; i++){
		}
		
		//empty the table
		for (int i = 0; i < SIZE; i++){
			tmpQ[i] = -1;
		}
		
		//fill the array with fresh random values
		test.getKey(TQ,false);
	}
*/
/*	//case (2) when x is not in T for linear probing
	for(int j = 0; j< EXPERIMENTS; j++){//do 100 experiments
		int counterarr[LOADED]; //record the counter values for each experiment for LOADED cases i.e. 1000
		int counterInd = 0;

		while(counterInd < LOADED){
			int counter = 0;
			int r = rand() % RAND_MAX;
			r *=  pow( 2, (rand() % 15 +1));
			if(!(test.search(r,TL,1, counter))){
				counterarr[counterInd] = counter;//add the conter value for average 
				counterInd++;
			}
		}
		//get the average to stdout
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  << average << endl;
		
		//empty the table
		for (int i = 0; i < SIZE; i++){
			tmpL[i] = -1;
		}
		
		//wait 1 second
		for (int i = 0; i < CPU_SEC; i++){
		}
		
		//fill the array with fresh random values
		test.getKey(TL,1);
	}
*/
/*	//case (2) when x is not in T for quadratic probing
	for(int j = 0; j< EXPERIMENTS; j++){//do 100 experiments
		int counterarr[LOADED]; //record the counter values for each experiment for LOADED cases i.e. 1000
		int counterInd = 0;
		while(counterInd<LOADED){
			int counter = 0;
			int r = rand() % RAND_MAX;
			r *=  pow( 2, (rand() % 15 +1));
			if(!(test.search(r,TQ,false,counter))){
				counterarr[counterInd] = counter;//add the conter value for average 
				counterInd++;
			}
		}
		//get the average to stdout
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  << average << endl;
		
		//empty the table
		for (int i = 0; i < SIZE; i++){
			tmpQ[i] = -1;
		}
		
		//wait 1 second
		for (int i = 0; i < CPU_SEC; i++){
		}
		
		//fill the array with fresh random values
		for (int i = 0; i < SIZE; i++){
			tmpQ[i] = -1;
		}
		
		//fill the array with fresh random values
		test.getKey(TQ,false);
	}
*/
/*=	//case (1) when x is in T for double hashing
	for(int j = 0; j< EXPERIMENTS; j++){//do 100 experiments
		int counterarr[LOADED]; //record the counter values for each experiment for LOADED cases i.e. 1000
		int counterInd = 0;
		for(int i = 0; i < SIZE; i++){
			if(tmpD[i] != -1){
				int counter = 0;
				test.searchDub(tmpD[i],TD,counter);
				counterarr[counterInd] = counter; //add the conter value for average 
				counterInd++;
				}
		}
		//get the average to stdout
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  << average << endl;
		
		//empty the table
		for (int i = 0; i < SIZE; i++){
			tmpD[i] = -1;
		}
		
		//wait 1 second
		for (int i = 0; i < CPU_SEC; i++){
		}
		
		//empty the table
		for (int i = 0; i < SIZE; i++){
			tmpD[i] = -1;
		}
		
		//fill the array with fresh random values
		test.getKeyDub(TD);
	}
*/	
     //case (2) when x is not in T for double hashing
	for(int j = 0; j< EXPERIMENTS; j++){//do 100 experiments
		int counterarr[LOADED]; //record the counter values for each experiment for LOADED cases i.e. 1000
		int counterInd = 0;
		while(counterInd<LOADED){
			int counter = 0;
			int r = rand() % RAND_MAX;
			r *=  pow( 2, (rand() % 15 +1));
			if(!(test.searchDub(r,TD,counter))){
				counterarr[counterInd] = counter;//add the conter value for average 
				counterInd++;
			}
		}
		//get the average to stdout
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  << average << endl;
		
	}

	
}
	
	