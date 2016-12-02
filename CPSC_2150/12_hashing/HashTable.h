// Gladys Monagan, CpSc 2150
// Implement a HashTable 
// November 26, 2015
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Person.h"
// the hashing function depends on the key k and the size of the table m

// for today, the ItemType will be Person
// note that readTable assumes that the type read is an integer id 
// followed by a string
// adjust if you make the ItemType different from Person
typedef Person ItemType;

class HashTable{
   public:
      // the table should always have a load factor of at most MAX_LOAD_FACTOR 
      static const int MAX_LOAD_FACTOR = 2;
   
      // create a table
      // the hashing function hf returns internally the index for the table
      // it takes an integer (the key) and the current size of the key
      // a typical hashing function would be
      //     int hash_fct(int k, int m) { return k % m;}
      // first_m is the size of the table at the beginning
      HashTable(int(*hf)(int,int), int first_m); 
   
      // insert the ItemType with its key into the hash table
      // return true if the insertion was successful, false otherwise
      // if n > MAX_LOAD_FACTOR*m, the table is automatically enlarged and subsequently
      // x is inserted into the "larger" table
      // thus we never have a load factor greater than MAX_LOAD_FACTOR
      bool insert(ItemType x);
   
      // given the key, retrieve the item in the hash table that has a getKey() equal to key
      // the item retrieved is "exported" with x  
      // postcondition: x has the item with that key and returns true if found
      //  returns false is NO item in the hash table has an item.getKey()  equal to key
      bool retrieve(int key, ItemType& x);
   
      // remove from the table the item that has a matching key equal to 'key'
      // postcondition: if the removal was NOT successful (e.g the item was not in
      // the table) return false, true otherwise 
      bool remove(int key);
      
      // read from the file fileName pairs of id and name 
      // until the end of file and insert them into the hash table
      // if the fileName is not available for reading, report the error to std::cerr
      // and be rude by exiting the complete program
      // report to std::cerr if there are duplicates in the id (a duplicate id is ignored)
      void readTable(string fileName);

      // read from a stream in paris and id and a name
      // if item (the pair) is found in the table already,
      // ignore it and print an error messsage to cerr
      void readTableFromStream(std::istream& in);
      
      //destructor 
      ~HashTable();
      
      // copy constructor  
      HashTable(const HashTable&);
      
      // overloaded assignment operator 
      HashTable& operator = (const HashTable&);
      
      // output the complete hash table onto standard output (in no particular order)
      // assume that the << operator has been defined for ItemType
      friend ostream& operator<< (ostream&, const HashTable&);
      
   private:
      // internal node in a linked list of table[i]
      struct Node{
         ItemType item;
         Node *next;
      };
      
      // an array of Node* pointers
      Node** table;
      
      // the number of buckets, i.e. size of table, gets doubled as the load increases
      int m; 
      
      // the number of items stored in hash table
      int n; 
      
      // // hashing function passed as a parameter in the constructor
      int (*hashing)(int,int); 
      
      // allocate space for a new node with x in its item field and linked it to p
      static Node* cons(ItemType x, Node* p);
      
      // make this->table bigger by doubling it (making it at least MAX_LOAD_FACTOR * m) 
      void enlargeTable();
      
      // delete and free up the memory of hTable of size an_m
      // there are an_n elements in hTable
      // return the number of elements left in hTable, so we expect 0 to be returned every time!
      int deleteTable(Node** hTable, int an_m, int an_n);
      
      // is the item with key in the linked list p
      static bool member(int key, Node* p);
      
      // precondition:
      //     an item with item.getKey() equal to k is the list p
      //     p is never null
      // postcondition:
      //     node with item.getKey() equal to k is removed and the head of that list is returned
      static Node* removeFromList(int k, Node* p);
      
      // helper function to make a copy of the linked list p
      static Node* copyList(Node* p);
      
};
#endif
