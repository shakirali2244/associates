#include<string>
#include<algorithm>
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
};