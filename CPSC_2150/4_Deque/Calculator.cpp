#include "Calculator.h"
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int Calculator::parse(string in){
	int size = in.length();
	for(int i=0; i<size; i++){
		char cur = in[i];
		cout << cur << endl;
		string tmp = "";
		if(cur >= '0' && cur <= '9'){
			while(cur >= '0' && cur <= '9'){
				tmp += cur;
				i++;
				cur= in[i];
			}
			d.pushFront(std::stoi(tmp));
			i--;
		}
		else if(cur == ' '){

		}
		else if(cur == '='){
			return d.popFront()->key;
		}
		else {
			if (cur == '+'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre + pos;
				d.pushFront(ans);
			}
			else if (cur == '-'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre - pos;
				d.pushFront(ans);
			}
			else if (cur == '*'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre * pos;
				d.pushFront(ans);
		     }

			if (cur == '/'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre / pos;
				d.pushFront(ans);
			}
			if (cur == '^'){
				int pos = d.popFront()->key;
				int pre = d.popFront()->key;
				int ans = pre ^ pos;
				d.pushFront(ans);
			}
		}
	}
	return -1;
}

void Calculator::calculate(string f){
	freopen("input", "r", stdin);
	   string line;
	   while(getline(cin, line)){
		   cout <<"read \n";
		   int ans = parse(line);
		   cout << line << " " << ans << endl;
	   }
}

