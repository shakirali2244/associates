#include "BTree.h"
#include "BTreeNode.h"
#include <fstream>



using namespace std;



int main(int argc, char *argv[]){
	
	/*
	BTree t;
	t.insert(4);
	t.print(cout);
	t.insert(3);
	t.print(cout);
	t.insert(2);
	t.print(cout);
	t.insert(1);
	t.print(cout);
	t.insert(11);
	t.print(cout);
	t.insert(6);
	t.print(cout);
	t.insert(50);
	
	t.print(cout);
	*/
	std::ifstream input(argv[1]);
	BTree t;
	std::string line;
	if(input.is_open()){
		while(getline(input, line)){
		int input = std::stoi(line);
		t.insert(input);
		t.print(cout);
		
		}
	}
	
		
	
	
	input.close();
	

	
	
	
}