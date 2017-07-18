// Shakir Ali 100268078
// CPSC 2150 Assignment 5
//program to maintain a hash table of a dictionary and find anagrams
//references -
//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
//https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class Anagram{
	public:
		string word;
		string key;
		Anagram(string in){
			word = in;
			key = in;
			sort(key.begin(),key.end()); //sort key alphabatically
		}
		Anagram(){ // empty string to help make pretend empty bucket
			word = "";
			key = "";
		}
};