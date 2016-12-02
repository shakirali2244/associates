#include "HashTable.h"


HashTable::HashTable(){
	table = new int[SIZE];
	for( int i =0; i < SIZE; i++ ){
		table[i] = -1;
	}
}

int* HashTable::gethead(){
	return table;
}