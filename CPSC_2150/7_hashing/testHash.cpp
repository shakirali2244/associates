#include "Hash.h"
#include "HashTable.h"
#include <iostream>


using namespace std;

int SIZE = 1999;
const int LOADED = 1000;
int EXPERIMENTS  = 100;
int main(){
	Hash test;
	HashTable TL;
	HashTable TQ;
	
	//test.getKey(TL,1);
	test.getKey(TQ,0);
	
	
	//int* tmpL = TL.gethead();
	
	int* tmpQ = TQ.gethead();
	
	
	/*for(int j = 0; j< EXPERIMENTS; j++){
		int counterarr[LOADED];
		int counterInd = 0;
		for(int i = 0; i < SIZE; i++){
			if(tmpL[i] != -1){
				int counter = 0;
				test.search(tmpL[i],TL,1, counter);
				counterarr[counterInd] = counter;
				counterInd++;
			}
		}
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  << average << endl;
		for (int i = 0; i < SIZE; i++){
			tmpL[i] = -1;
		}
		for (int i = 0; i < 500000000; i++){
		}
		test.getKey(TL,1);
	}*/
	/*
	for(int j = 0; j< EXPERIMENTS; j++){
		int counterarr[LOADED];
		int counterInd = 0;
		test.print(TQ);
		for(int i = 0; i < SIZE; i++){
			if(tmpQ[i] != -1){
				int counter = 0;
				test.search(tmpQ[i],TQ,0, counter);
				counterarr[counterInd] = counter;
				counterInd++;
			}
		}
		double average = 0;
		double sum = 0;
		for (int i = 0; i < LOADED; i++){
			sum+= (double)counterarr[i];
		}
		average = sum/(double) LOADED;
		cout  <<"average =  "  <<average << endl;
		for (int i = 0; i < SIZE; i++){
			tmpQ[i] = -1;
		}
		//for (int i = 0; i < 500000000; i++);
		test.getKey(TQ,0);
	}*/
	/*
	int* tmpQ = TQ.gethead();
	test.print(TQ);
	int counter = 0;
	for(int i = 0; i < SIZE; i++){
		if(!(tmpQ[i] == -1)){
			test.search(tmpQ[i],TQ,0,counter);
		}
	}
	*/
	
	//test.print(TQ);
}
	
	