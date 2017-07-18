#include "Anagram.h"
#include<iostream>
#include <fstream>
#include <string>



using namespace std;

// SIZE of the hash table
const int SIZE = 199961;


//https://stackoverflow.com/questions/8317508/hash-function-for-a-string
//https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
unsigned int hash(Anagram ana){
	string in = ana.key;
	//cout << in << endl;
	unsigned int total = 983;
	 for (int i=0; i<in.length(); i++)
	  {
		int c = in.at(i) + 0;
		total = (total*101) ^ (c * 433);
	  }
	  
	  return (total%SIZE) - 1;
  }
	
	

int main(int argc, char *argv[]){
	
	
	
	// HEAP stored 200k sized Anagram arary
	Anagram *table = new Anagram[SIZE];
	
	ifstream infile("dictionary.txt");
	string dict_word;
	
	int dict_words = 0;
	int collisions_l = 0;
	int collisions_ave = 0;
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
				
				#ifdef COL
				cout << "adding at " << index << endl;
				#endif
				
				table[index] = tmp;
			} else{
				int collisions = 0; 
				collisions++;
				
				#ifdef COL
				cout << "collision at " << index << endl;
				#endif
				
				if (index == SIZE-1){
					index = 0;
				} else{
					index++;
				}
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
				
				table[index] = tmp;
				collisions_ave += collisions;
				if (collisions_l < collisions){
					collisions_l = collisions;
				}
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
	cout << " dict_words =" << dict_words 
	<< " largest collision = " << collisions_l 
	<< " average collisions = "<< (float) collisions_ave/dict_words
	<< " total collisions = " << collisions_ave << endl;
	
	if (argc != 3){
		cout << "provide inputfilename and outputfilename";
		return 0;
	} else{
		ifstream input(argv[1]);
		ofstream output;
		output.open(argv[2]);
		string line;
		while(getline(input, line)){
			if (!(line.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos) && line != ""){
				transform(line.begin(), line.end(), line.begin(), ::tolower);
				Anagram anagram = Anagram(line);
				int probe_col = 0;
				int anas = 0;
				int index = hash(anagram);
				bool flag = true;
				output << line;
				cout << line;
				string tmp = "";
				while(flag){
					if(table[index].key == ""){
						probe_col++;
						flag = false;
					}else{
						if (table[index].key == anagram.key){
							anas++;
							tmp.append(" ");
							tmp. append(table[index].word);
							cout << " " << table[index].word;
						}
					}
					index++;
				}
				output << " " << anas << " " << tmp << probeendl;
				cout << endl;
			}
		}
		output.close();
	}
	
			
	
	
	return 0;
}