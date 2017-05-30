//class simulating a Doubly Linked list
// Shakir Ali 23rd May 2017


#include<cstdlib>
#include<iostream>

using namespace std;

template<typename T>
class Node{
	public:
		T val; // the contents of the node
		Node* left;
		Node* right;
	
	Node (){
		left = nullptr;
		right = nullptr;
	}
	
	Node (T val){ 
		this->val  = val;
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

void genDLL(int n, Node<int> * list){
	bool flag = true; // flag to help fill the first element
	for(int i =0; i < n; i++){
		int val = (rand() % n ) + 1;
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

void printList(Node<int> *list){
	Node<int>* tmp = list; //copy reference to head so that it is not modified by mistake
	while(tmp != nullptr){
		cout << "  |  " << tmp->val << endl;
		tmp = tmp->left; //traverse
	}
}
