#include "Hash.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

Hash::Hash(){
}

int Hash::h(int x) {
	return x % SIZE;
}

bool Hash::search(int x, HashTable T, bool linear, int& counter){
	if(linear)
		return searchLin(x,T, counter);
	else
		return searchQad(x,T, counter);
}

bool Hash::insert(int x, HashTable T, bool linear){
	if(linear)
		return insertLin(x,T);
	else 
		return insertQad(x,T);
}

bool Hash::searchLin(int x, HashTable T, int& counter){
	if(x == -1){
		return false;
	}
	int index = h(x);
	int originalInd = index;
	int* tmp = T.gethead();
	counter = 1;
	while(tmp[index] != x){
		counter ++;
		if(tmp[index] == -1){
			//cout<< "not foundn linear  " <<  counter << endl;
			return false;
		}
		index++;
		if(index >= SIZE-1){
			index = 0;
		}
		if(index == originalInd){
			//cout<< "not foundn linear  " <<  counter << endl;
			return false;
		}
	}
	//cout << counter << endl;
	return true;
}

bool Hash::insertLin(int x, HashTable T){
	int counter = 0;
	if(searchLin(x,T,counter)){
		return false;
	}
	int index = h(x);
	int originalInd = index;
	int* tmp = T.gethead();
	if(tmp[index] == -1){
		tmp[index] = x;
		return true;
	}
	while(true){
		if(tmp[index] == -1){
			tmp[index] = x;
			return true;
		}
		index++;
		if(index >= SIZE-1){
			index = 0;
		}
		if(index == originalInd){
			return false;
		}
	}
	//cout << "while not deciding, table full" << endl;
	return false;
}

bool Hash::searchQad(int x, HashTable T, int &counter){
	if(x == -1){
		return false;
	}
	int index = h(x);
	int indexOri = index;
	int* tmp = T.gethead();
	counter = 0;
	for(int i = 1; i < SIZE; i++){
		if(tmp[index] == -1){
			cout<< "not found quad  " <<  counter << endl;
			return false;
		}
		counter++;		
		if(tmp[index] == x){
			cout <<  counter << endl;
			return true;
		}
		index = indexOri + (i*i);
	}
	cout<< "not found quad  " <<  counter << endl;
	return false;
}

bool Hash::insertQad(int x, HashTable T){
	int counter = 0;
	if(searchQad(x,T,counter)){
		return false;
	}
	int index = h(x);
	int indexOri = index;
	int* tmp = T.gethead();
	for(int i = 1; i < SIZE; i++){
		if(tmp[index] == -1){
			tmp[index] = x;
			return true;
		}
		cout<< "index = " << index;
		index = indexOri + (i*i);
	}
	cout << "qad, table ended" << endl;
	return false;
}

void Hash::getKey(HashTable T, bool linear){
	srand(time(0));
	int total = 0;
	while(total < 1000){
		int r = rand() % RAND_MAX;
		r *=  pow( 2, (rand() % 15 +1));
		if (insert(r,T,linear)){
			total++;
		}
	}
}

void Hash::print(HashTable T){
	int* tmp = T.gethead();
	cout << "[ ";
	for(int i = 0; i<SIZE; i++){
		if (tmp[i] != -1)
			cout << tmp[i] << " ";
	}
	cout << " ],";
}
			
		
		
	
	

	