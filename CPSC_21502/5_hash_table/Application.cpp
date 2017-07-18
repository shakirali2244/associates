#include "Anagram.h"
#include<iostream>
#include <fstream>



using namespace std;

// SIZE of the hash table
const int SIZE = 200000;


int hash(Anagram ana){
	string in = ana.key;
	//cout << in << endl;
	int total = 0;
	 for (int i=0; i<in.length(); i++)
	  {
		total = total + in.at(i);
	  }
	  
	  return (total%SIZE) - 1;
  }
	
	

int main(){
	
	// HEAP stored 200k sized Anagram arary
	Anagram *table = new Anagram[SIZE];
	
	ifstream infile("dictionary.txt");
	string dict_word;
	int dict_words = 0;
	while(getline(infile, dict_word)){
		if (dict_word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos){
			
			#ifdef DEBUG
			cout << "[" << dict_word << "]"  << endl;
			#endif
			
		} else if (dict_word != ""){ 
			dict_words++;
			#ifdef DEBUG
		        cout << dict_word << " ";
			#endif
			transform(dict_word.begin(), dict_word.end(), dict_word.begin(), ::tolower);
			Anagram tmp = Anagram(dict_word);
			int index = hash(tmp);
			if(table[index].key == ""){
				//cout << tmp.key << endl;
				cout << "adding at " << index << endl;
				table[index] = tmp;
			} else{
				cout << "collision at " << index << endl;
				if (index == SIZE-1){
					index = 0;
				} else{
					index++;
				}
				while (table[index].key != ""){
					cout << "collision at " << index << endl;
					if (index == SIZE-1){
						index = 0;
					} else{
						index++;
					}
				}
				cout << "adding at " << index << endl;
				table[index] = tmp;
			}
			
			#ifdef DEBUG
			cout << dict_word << endl;
			#endif
		}
	}
	
	for ( int i = 0; i<SIZE; i++){
		cout << i << " " << table[i].key << " "  <<  table[i].word << endl;
	}
	
	//cout << hash(Anagram("b")) << endl;
		
	
	//Anagram a("rats");
	//cout << a.word << " " << a.key << endl;
	cout << " dict_words =" << dict_words << endl;
	return 0;
}