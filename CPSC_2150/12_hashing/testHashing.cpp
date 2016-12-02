// Test program for the HashTable
// Gladys Monagan  CpSc 2150
// expects input from standard out 
// could run as testHashing < table.txt
// but it's better to pass the filename of the file that has the table
// and then to interactively add or remove from the table
// right now the file name is "table.txt"
// November 25, 2016

#include "Person.h"
#include "HashTable.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


// the hashing function takes an int key and the size of the
// table m, and returns an integer
int hash_fct(int k, int m) {
      return k % m;
}

// simple version to test, using cin, retrieve, insert, remove from the hashTable
void testHashTableFunctions(HashTable& hTable) {
   const int CHARS_TO_IGNORE_STUCK_IN_BUFFER = 100;
   // need a loop here....
   cout << "\nEnter key of person that you want retrieved: ";
   int xKey;
   cin >> xKey;
   Person prs;
   if (hTable.retrieve(xKey, prs)) {
      cout << endl << prs << " was retrieved from the hash table\n";
   }
   else {
      cout << "\n"; 
      cout << xKey << " was not a valid key for anyone in the hash table\n";
   } 

   string name;
   cout << "\n\nEnter an id (int) followed by a single name that you want to insert: \n";
   cout << "    quit inserting by entering first a non-numeric character\n";
   while (cin >> xKey >> name){
      if (hTable.insert(Person{xKey,name})) {
         cout << "table is now  ...............\n" << hTable;
      }
      else {
         cout << "inserting " << xKey << " " << name << " failed\n";
      }
         cout << "another id (int) followed by a single name (string): ";
   }
   cin.clear();
   cin.ignore(CHARS_TO_IGNORE_STUCK_IN_BUFFER, '\n');
  
   cout << "\nEnter key of person that you want removed: ";
   cin >> xKey;
   if (hTable.remove(xKey)) {
      cout << "\nAn item with the key " ;
      cout << xKey << " was removed successfully\n";
   }
   else {
      cout << xKey << " could not be removed\n";
   }      
   cout << "after removal: " << hTable;
}

int main() {
   const int FIRST_M = 11; // a prime number is best
   
   // define the simplest hash function
   int (*hf)(int,int);
   hf = hash_fct;
   
   // create a hash table and print it out reading the data from table.txt
   HashTable hTable(hf, FIRST_M);
   //hTable.readTableFromStream(std::cin);
   hTable.readTable("table.txt");
   cout << hTable;
   
   testHashTableFunctions(hTable);
   
   // call the constructor and print the "new table"
   HashTable newTable(hTable); 
   cout << "\ncopied table (result of calling the copy constructor): \n";
   cout << newTable;
  
   return 0;
}

