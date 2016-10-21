#include "SList.h"
#include <stdlib.h>
using namespace std;

template<typename T>
Node<T>* SList<T>::cons(T key, int level, Node<T>** next){
	return new Node<T>{key, level, next};
}

template<typename T>
SList<T>::SList(){
	Node<T>** headerN = new Node<T>*[MAXLEVEL];
	Node<T>** footerN = new Node<T>*[MAXLEVEL];

	for(int i= 0; i<MAXLEVEL; i++){
		headerN[i] = nullptr;
		footerN[i] = nullptr;
	}
	header = cons(0,MAXLEVEL,headerN);
	tail = cons(100,MAXLEVEL,footerN);

	for(int i= 0; i<MAXLEVEL; i++){
		header->next[i] = tail;
	}
}


template<typename T>
 void SList<T>::insert(T x){
	if(header == nullptr){
		return;
	}
	Node<T>* tmp = header;
	int level = 1;
	if((rand() % 2) == 1){
		level++;
	}
	int startlevel = 2;
	while(tmp->next != nullptr && (tmp->next[startlevel-1])->key <= x){
		tmp=tmp->next[0];
		if (tmp->level > 1 && ){

		}
	}
	Node<T>** newerN = new Node<T>*[level];
	Node<T>* newer = cons(x, level , newerN);
	Node<T>* front = tmp->next[0];
	for (int i=0; i< tmp->level ; i++){
		tmp->next[i] = newer;
	}
	for (int i=0; i< newer->level ; i++){
		newer->next[0] = front;
	}
	Node<T>** next = new Node<T>*[level];
	for (int i=0; i< level ; i++){
		next[i] = front;
	}
 }

template<typename T>
bool SList<T>::found(T x){
	return true;
}

template<typename T>
int SList<T>::getTraversals() const{
	return 1;
}

template<typename T>
int SList<T>::getComparisons() const{
	return 1;
}

template<typename T>
void SList<T>::printAllInOrder(std::ostream&) const{

}
template<typename T>
void SList<T>::setOutputDelimeter(std::string delimeter){

}
template<typename T>
int SList<T>::numberOfElements() const{
	return 1;
}
template<typename T>
void SList<T>::reset(){

}

template<typename T>
SList<T>& SList<T>::operator = (const SList& obj){
	return nullptr;
}

template<typename T>
SList<T>::SList(const SList& obj){

}


template<typename T>
SList<T>::~SList(){

}
template<typename T>
void dumpTopList(std::ostream& out){

}



