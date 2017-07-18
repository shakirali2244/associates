// Shakir Ali 100268078
// CPSC 2150 Assignment 5
//program to maintain a hash table of a dictionary and find anagrams
//references -
//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
//https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity


#include "Anagram.h"
#include<iostream>
#include <fstream>
#include <string>



using namespace std;

// SIZE of the hash table
const int SIZE = 199961;
const int SEED = 983;
const int PRIME_MAGIC_1 = 101;
const int PRIME_MAGIC_2 = 433;


//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
//https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
// create a hash value ranging from 0 to SIZE -1
// uses XOR with a PRIME STARTING SEED and a PRIME multiplier to prevent overflow of uint
//precondition - ana should not contain empty string constituent members
// postcondition - returns the index position
unsigned int hash(Anagram ana){
	string in = ana.key;
	unsigned int total = SEED; //starting prime seed
	 for (int i=0; i<in.length(); i++)
	  {
		int c = in.at(i) + 0; //extract int val from char
		total = (total*PRIME_MAGIC_1) ^ (c * PRIME_MAGIC_2); // multiply and fold using XOR
	  }
	  return (total%SIZE) - 1; //return within index range of the table
  }
	
	

int main(int argc, char *argv[]){
	
	
	
	// HEAP stored 200k sized Anagram arary
	Anagram *table = new Anagram[SIZE];
	
	ifstream infile("dictionary.txt");
	string dict_word;
	
	int dict_words = 0; // total qualified words for the dictionary
	int collisions_l = 0; // largest collision/probe needed to insert a word
	int collisions_ave = 0; // total collisions , used to average later per word
	while(getline(infile, dict_word)){
		//dont allow numbers or special chars
		if (dict_word.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos){
			
			#ifdef DEBUG
			cout << "[" << dict_word << "]"  << endl;
			#endif
		// dont allow empty lines	
		} else if (dict_word != ""){ 
			dict_words++;
			#ifdef DEBUG
		        cout << dict_word << " ";
			#endif
			// toLowercase
			transform(dict_word.begin(), dict_word.end(), dict_word.begin(), ::tolower);
			//sort alphabatically
			Anagram tmp = Anagram(dict_word);
			//hash
			int index = hash(tmp);
			
			// if no collision
			if(table[index].key == ""){
				
				#ifdef COL
				cout << "adding at " << index << endl;
				#endif
				
				table[index] = tmp;
			} else{
				//if the hash was the last index aka linear probing
				int collisions = 0; 
				collisions++;
				
				#ifdef COL
				cout << "collision at " << index << endl;
				#endif
				
				if (index == SIZE-1){ //go to front index if last
					index = 0;
				} else{
					index++;
				}
				
				//more linear probing
				while (table[index].key != ""){
					collisions++;
					
					#ifdef COL
					cout << "collision at " << index << endl;
					#endif
					
					if (index == SIZE-1){
						index = 0;
					} else{
						index++;
					}
				}
				#ifdef COL
				cout << "adding at " << index << "collisions = " << collisions << endl;
				#endif
				
				//insert
				table[index] = tmp;
				collisions_ave += collisions;
				if (collisions_l < collisions){ //save the largest collision
					collisions_l = collisions;
				}
			}
			
			#ifdef DEBUG
			cout << dict_word << endl;
			#endif
		}
	}
	
	//for ( int i = 0; i<SIZE; i++){
	//	cout << i << " " << table[i].key << " "  <<  table[i].word << endl;
	//}
	
	
	// ---------------------TESTER PART--------------------------------
	//we see here that largest collisions happened are 7 which are 
	// less then log 2 (25017) which is  around 14 and an average 
	// case of less than one.
	// ------------------------------------------------------------------------
	
	cout << " dict_words =" << dict_words 
	<< " largest collision = " << collisions_l 
	<< " average collisions = "<< (float) collisions_ave/dict_words
	<< " total collisions = " << collisions_ave << endl;
	
	// program usage check
	if (argc != 3){
		cout << "ERROR usage: ./Application input.txt output.txt";
		return 0;
	} else{
		ifstream input(argv[1]);
		ofstream output;
		output.open(argv[2]);
		string line;
		while(getline(input, line)){
			//same checks as insert
			if (!(line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) && line != ""){
				transform(line.begin(), line.end(), line.begin(), ::tolower);
				Anagram anagram = Anagram(line);
				int probe_col = 0; //probing repeats
				int anas = 0; // total anagrams found
				int index = hash(anagram);
				bool flag = true; // case to break out if bucket fully searched
				output << line;
				string tmp = "";
				while(flag){
					if(table[index].key == ""){ //if not found or end of bucket reached
						probe_col++;
						flag = false;
					}else{
						// dont find the word itself
						if (table[index].key == anagram.key && table[index].word != anagram.word){ 
							anas++;
							tmp.append(" ");
							tmp. append(table[index].word);
						}
					}
					//linear probing
					if (index == SIZE-1){
						index = 0;
					} else{
						index++;
					}
				}
				output << " " << anas
				<< tmp 
				//<< " " <<  probe_col  //probing collision happened if any
				<< endl;
			}
		}
		output.close();
	}
	
	return 0;
}