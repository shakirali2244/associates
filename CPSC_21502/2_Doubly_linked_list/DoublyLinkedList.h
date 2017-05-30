//class simulating a Doubly Linked list
// Shakir Ali 23rd May 2017


#include<cstdlib>
#include<iostream>
#include<fstream>

using namespace std;

template<typename T>
class Node{
	public:
		T val; // the contents of the node
		int count;
		Node* left;
		Node* right;
	
	Node (){
		left = nullptr;
		right = nullptr;
		count = 0;
	}
	
	Node (T val){ 
		this->val  = val;
		count = 0;
		left = nullptr;
		right = nullptr;
	}
	
		
};

//fill up DLL with n random values in range 1 to n
// n - number of elements needed
// list - pointer to the head of the DLL
void genDLL(int n, Node<int>* list);

//print DLL contents
// list - pointer to DLL to be printed
void printList(Node<int>* list);

int findmtf(Node<char>* &list, string filename);

int findcnt(Node<char>* &list, string filename);

void genDLLaz(Node<char> * list);

void genDLL(int n, Node<int> * list){
	bool flag = true; // flag to help fill the first element
	for(int i =0; i < n; i++){
		int val = (rand() % n*2 )  - n;
		
		if (flag){ //insert val t0 first node
			list->val = val;
			flag = false;
			cout << "adding to first " << val  << endl;
		}else{ // add newer node to the left and add links
			cout << "adding to left " << val  << endl;
			Node<int>* tmp = new Node<int>(val);
			tmp->right = list;
			tmp->right->left = tmp;
			list = tmp;
		}
	}
}

void genDLLaz(Node<char> * list){
	bool flag = true; // flag to help fill the first element
	for(int i =97; i < 123; i++){
		
		if (flag){ //insert val t0 first node
			list->val = (char) i;
			flag = false;
			//cout << "adding to first " << (char) i  << endl;
		}else{ // add newer node to the left and add links
			//cout << "adding to left " << (char) i  << endl;
			Node<char>* tmp = new Node<char>((char) i);
			tmp->right = list;
			tmp->right->left = tmp;
			list = tmp;
		}
	}
}

void printList(Node<char> *list){
	Node<char>* tmp = list; //copy reference to head so that it is not modified by mistake
	while(tmp != nullptr){
		cout << tmp->val << "-" << tmp->count << endl;
		tmp = tmp->left; //traverse
	}
}

int findmtf(Node<char>* &list, string filename){
	int count=1;
	bool found = true; // flag to help fill the first element
	char ch;
	fstream fin(filename, fstream::in);
	while (fin >> noskipws >> ch) {
		if((int) ch <= 122 && (int) ch >= 97) {
			Node<char>* temp = list;
			while(temp->val != ch){
				temp = temp->left;
				count++;
			}
			if(found && temp != list && temp->left != nullptr){
				temp->right->left = temp->left;
				temp->left->right =  temp ->right;
				temp->right = nullptr;
				temp->left = list;
				list -> right = temp;
				list = temp;
			} else if(found && temp != list){
				temp->right->left = temp->left;
				temp->right = nullptr;
				temp->left = list;
				list -> right = temp;
				list = temp;
			}
		}
	}
	return count;
}

int findcnt(Node<char>* &list, string filename){
	char ch;
	int count=1;
	fstream fin(filename, fstream::in);
	while (fin >> noskipws >> ch) {
		if((int) ch <= 122 && (int) ch >= 97) {
			Node<char>* temp = list;
			while(temp->val != ch){
				temp = temp->left;
				count++;
			}
			temp->count++;
			Node<char>* traverse_helper = list;
			
			while(traverse_helper->count >= temp->count && traverse_helper!=nullptr){
				traverse_helper = traverse_helper->left;
				count++;
			}
			
			if(temp != list && temp->left != nullptr){
				temp->right->left = temp->left;
				temp->left->right =  temp ->right;
				//temp->right = nullptr;
				temp->right = traverse_helper;
				temp->left = traverse_helper->left;
				traverse_helper->left->right = temp;
				traverse_helper->left = temp;
			} else if( temp != list && temp->left == nullptr){
				temp->right->left = temp->left;
				temp->right = traverse_helper;
				temp->left = traverse_helper->left;
				traverse_helper->left->right = temp;
				traverse_helper->left = temp;
			}
		}
	}
	return count;
}

void findtrnsp(Node<char>* list, string filename){
	char ch;
	fstream fin(filename, fstream::in);
	while (fin >> noskipws >> ch) {
		if((int) ch <= 122 && (int) ch >= 97) {
			Node<char>* temp = list;
			while(temp->val != ch){
				temp = temp->left;
			}
			cout << ch << endl;
			
			
			if(temp != list && temp->left != nullptr){
				
				if(temp->right == nullptr ){
					cout << ch << "ERROR";
					return;
				}
				
				Node<char>* aux1 = temp->right;
				Node<char>* aux2 = temp->left;
				
				temp->right = aux1->right;
				if(temp->right != nullptr)
					temp->right->left = temp;
				temp->left = aux1;

				aux1->left = aux2;
				aux1->right = temp;
				
				aux2->right = aux1;
			} else if(temp != list){
				if(temp->right == nullptr ){
					cout << ch << "ERROR";
					return;
				}
				Node<char>* aux1 = temp->right;
				//Node<char>* aux2 = temp->left;
				
				temp->right = aux1->right;
				if(temp->right != nullptr)
					temp->right->left = temp;
				temp->left = aux1;
				
				aux1->left = nullptr;
				aux1->right = temp;
			}
		}
	}
}
	
