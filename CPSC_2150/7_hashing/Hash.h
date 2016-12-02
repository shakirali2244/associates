#include "HashTable.h"
#ifndef HASH_H
#define HASH_H


class Hash{
	public:
		Hash();
		int h(int x);
		bool search(int x, HashTable T, bool linear, int& counter);
		bool insert(int x,HashTable T, bool linear);
		bool searchLin(int x, HashTable T, int& counter);
		bool insertLin(int x, HashTable T);
		bool searchQad(int x, HashTable T, int& counter);
		bool insertQad(int x, HashTable T);
		void getKey(HashTable T, bool linear);
		void print(HashTable T);
	private:
		int LIMIT = 1073741824;
		int SIZE = 1999;
};
#endif
		
		