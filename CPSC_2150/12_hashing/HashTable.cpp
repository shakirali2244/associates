// Gladys Monagan, CpSc 2150
// Implement a HashTable 
// November 26, 2016

//#define NDEBUG
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <cassert>
#include "HashTable.h"
#include "Person.h"

using std::endl;
using std::cout;
using std::cerr;
      
// constructor:
// make the hashing function the function passed by the user
// and let the user determine the original size of the table
HashTable::HashTable(int(*hf)(int,int), int first_m) {
   table = new Node*{first_m};
   m = first_m;
   //initialize the counter of items to 0
   n = 0;
   initializeLists(table, m);
   //hashing function hf is set to local function hashing
   hashing = hf;
}

void HashTable::initializeLists(Node** t, int size) {
   for (int i=0; i<size; i++)
   t[i] = nullptr;
}

// make a new node and link it to p, return a pointer to the new Node
// C++ note: we need to indicate specifically that Node is from HashTable as the return type
HashTable::Node* HashTable::cons(ItemType x, Node* p) {
   // to the CPSC2150 student: to be done with instructor
   return new Node{ x, p};
}

// helper function
// determine if the key is in the list already
bool HashTable::member(int key, Node* p) {
   Node* tmp = p;
   while(tmp != nullptr){
      if (p->item.getKey() == key)
         return true;
      tmp = tmp->next;
   }
   return false;
}

// if the key of x is already in the this->table, return false
// otherwise insert ItemType x into the i'th element of the this->table
// increment n which is the number of items in table
// the maximum load factor should be MAX_LOAD_FACTOR
bool HashTable::insert(ItemType x) {
   for(int i = 0; i < m; i++){
      if(table[i]->key < x.getKey())
         if (member(x.getKey(), table[i]))
            return false;
   }
   
   return true;
}

// retrieve into x the item given its key 
// if there is no item with the key, return false
bool HashTable::retrieve(int key, ItemType& x) {
   for(int i = 0; i < m; i++){
      if (
   return true;
}

// remove a node with key x.getKey() from the table[i]
// reduced the number of items n in table
// return value explaining if removal was successful
bool HashTable::remove(int key) {
   // to the CPSC2150 student: needs to be coded
   return true;
}

// delete all the linked lists of table
// and then delete the array of pointers hTable
// an_m is the size of hTable and an_n is the number of items in hTable
// we expect an_n to become 0 as we delete item by item
// we do a quick check to make sure that an_n becomes 0 with "assert"
// postcondition: 
//    all the memory of hTable is deallocated
//    returned is the number of elements left in the table (it should always be 0)
int HashTable::deleteTable(Node** hTable, int an_m, int an_n) {
   // to the CPSC2150 student: needs to be coded
}

// double the size of the current table and for a correct 
// solution add some prime ....so the table is not even
// insert each element one by one (after rehashing) and increment
// the private variable m 
// the private variable n might be incremented each time that insert is
// called but by the end of enlargeTable, it should be the same as
// before the call to enlargeTable
void HashTable::enlargeTable() {
   // to the CPSC2150 student: needs to be coded
}

// destructor
// return all the unused memory and set the number of elements 
// in the table to the number returned by deleteTable
// we expect deleteTable to return 0 which is the number of elements left in this->table
HashTable::~HashTable() {
   #ifndef NDEBUG
   cerr << "NDEBUG: calling the destructor %%%%%%%%%%%%%%\n";
   #endif
   this->n = deleteTable(this->table, this->m, this->n);
}

// overloaded assignment operator
// note that rtSide already exists
HashTable& HashTable::operator = (const HashTable& rtSide) {
   #ifndef NDEBUG
   cerr << "NDEBUG: into the overloaded assignment operator++++++++\n";
   #endif
   if (this == &rtSide) 
      return *this;
   // deallocate the previous table that existed in *this
   
   // to the CPSC2150 student: needs to be coded
   
   return *this;
} 

// copy constructor
HashTable::HashTable(const HashTable& h) {
   #ifndef NDEBUG
   cerr << "NDEBUG: into the copy constructor....\n";
   #endif
   // to the CPSC2150 student: needs to be coded
}  

// assume that the << operator has been defined for ItemType
// give the number of items in the hash table at the beginning
// and then output each item in the table
ostream& operator<< (ostream& out, const HashTable& hTable) {
   out << "the hash table of "<< hTable.n << " items\n";
   #ifndef NDEBUG
   out << "NDEBUG: allocated m = " << hTable.m << "\n";
   #endif
   for (int i=0; i < hTable.m; i++) {
      #ifndef NDEBUG
      bool notNULL = (hTable.table[i] != nullptr);
      if (notNULL)
         out << "hTable[" << i <<"]--------------------- \n";
      #endif
      for (HashTable::Node* p = hTable.table[i]; p!=nullptr; p=p->next) 
         out << p->item << endl;
   }
   out << "\n";
   return out;
}

// given a fileName, read an id and a string from the file
// if the fileName is not available for reading, report the error and
// exit the complete program
void HashTable::readTable(string fileName) {
   std::ifstream fin;
   fin.open(fileName.c_str());
   if (!fin) {
      cerr << "could not open file to read " << fileName;
      cerr << "... hasta la vista\n";
      exit(2);
   }
   readTableFromStream(fin);
   fin.clear(); // reset the fail bit
   fin.close();
}

// if the item is found in the table, ignore it and print
// an error message to cerr
// assume that the input comes in pairs
void HashTable::readTableFromStream(std::istream& in) {
   int id;
   string str;
   while (in >> id >> str) {
      ItemType item(id, str);
      if (!insert(item)) {
         cerr << "id " << id << " is already in the table thus it's ignored"; 
      }
   }
}


