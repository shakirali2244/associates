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
			sort(key.begin(),key.end());
		}
		Anagram(){
			word = "";
			key = "";
		}
};