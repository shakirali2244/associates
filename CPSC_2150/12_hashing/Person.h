// Little Person class header file
// used to test the HashFunction
// Gladys Monagan, CpSc 2150,
#ifndef PERSON_H
#define PERSON_H

#include <iostream> 
using std::ostream;
using std::string;
class Person {
   public:
      // the default constructor with the default values for int and string
      Person();
   
      // create a person with id (student #, SIN) i and name str
      Person(int i, string str);
   
      // return the unique key id of the person 
      int getKey() const {return id;}
      
      // return a copy of the person's name
      string getName() const {return name;}
      
      // output overloading the << operator
      // the format is
      //    id:  xxx \t   name : yyyy\t
      friend ostream& operator<< (ostream&, const Person&);
   private:
      int id;
      string name;
};
#endif 
