#ifndef HASHTABLE_H
#define HASHTABLE_H


class HashTable{
	public:
		HashTable();
		int* gethead();
	private:
		int *table;
		int SIZE = 1999;
};
			
#endif		
	