// Implementation of a Little Person class
// used to test the HashFunction
// Gladys Monagan, CpSc 2150

#include <iostream>
#include "Person.h"

// use the data type's default values
Person::Person(): id(int()), name(string()) {
}

Person::Person(int i, string str): id(i), name(str) {
}

// output the Person prs onto out (e.g. cout)
std::ostream& operator<< (std::ostream& out, const Person& prs) {
   out << "id: " << prs.id << "\t";
   out << "name: " << prs.name << "\t";
   return out;
}
