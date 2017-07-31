#include <queue>
#include<iostream>
#include <fstream>
#include "HuffNode.h"


using namespace std;

const int ASCII_RANGE = 128;




int* countChars(/*std::priority_queue<HuffNode> &in*/ string filename){
	
	 int* probs = new int[ASCII_RANGE]; 
	
	for (int i = 0;i < ASCII_RANGE; i++){
		probs[i] = 0;
	}
	 ifstream fin;
         fin.open(filename, ios::in);	
         // temp store to count the occurence of ASCII characters
         char tmp;
         while (!fin.eof() ) {
			fin.get(tmp);
			    int index = int(tmp);
			    probs[index] += 1;
		
		}
	return probs;
	}
	
std::priority_queue<HuffNode> BuildHuffTree(int* probs){
	std::priority_queue<HuffNode> ret;
	for (int i = 32;i < ASCII_RANGE; i++){
		HuffNode a;
		a.val = char(i);
		a.freq = probs[i];
		ret.push(a);
	}
	
	while(ret.size() >= 2){
		HuffNode parent;
		
		HuffNode* left = new HuffNode;
		left->val = ret.top().val;
		left->freq = ret.top().freq;
		left->left = ret.top().left;
		left->right = ret.top().right;
		
		ret.pop();
		
		HuffNode* right = new HuffNode;
		right->val = ret.top().val;
		right->freq = ret.top().freq;
		right->left = ret.top().left;
		right->right = ret.top().right;
		
		ret.pop();
		
		parent.left = left;
		parent.right = right;
		
		parent.freq = left->freq + right->freq;
		
		
		ret.push(parent);
		
	}
	
	return ret;
}

void print(HuffNode* in){
	
	if (in == nullptr)
		return;
	cout << in->freq << " " ;
	
	if (in->val != '\n'){
		cout << in->val << endl;
	}else{
		cout << endl;
	}
	
	cout << "/" << " \\" << endl;
	
	print(in->left);
	print(in->right);
	
}

	

int main(){
	
	int* probs;
	std::priority_queue<HuffNode> huffTree;
	
	//step 1
	string filename ="./input.txt";
	probs = countChars(filename);
	
	/*for (int i = 32;i < ASCII_RANGE; i++){
		cout << "(" << char(i) << ") " << probs[i] << endl;
	}*/
	
	// step 2
	huffTree = BuildHuffTree(probs);
	
	HuffNode tmp;
	
	tmp.val = huffTree.top().val;
	tmp.freq = huffTree.top().freq;
	tmp.left = huffTree.top().left;
	tmp.right = huffTree.top().right;
	
	print(&tmp);
	while(!huffTree.empty()){
		cout << "(" <<  huffTree.top().val<< ") " << huffTree.top().freq << endl;
		 huffTree.pop();
	}
	
	
	

   
}