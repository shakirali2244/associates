#include <iostream>


using namespace std;

class Node{
	public:
		int val; // the contents of the node
		int name;
		Node* left;
		Node* right;
		int size;
	
	Node (){
		left = nullptr;
		right = nullptr;
	}
	
	Node (int val,int name){ 
		this->val  = val;
		this->name = name;
		left = nullptr;
		right = nullptr;
	}		
};

int name = 0;
int size = 0;

void Queue(Node* &tail, int val){
	size++;
	name++;
	if (size-1 == 0){ //insert val t0 first node
		tail->val = val;
		tail->name = name;
		//cout << "adding to first " << val  << endl;
	}else{ // add newer node to the left and add links
		//cout << "adding to left " << val  << endl;
		Node* tmp = new Node(val,name);
		tmp->right = tail;
		tmp->right->left = tmp;
		tail = tmp;
		//list = tmp;
	}
}

void Queue(Node* &tail, Node* val){
	size++;
	if (size-1 == 0){ //insert val t0 first node
		tail = val;
		//cout << "adding to first " << val->val  << endl;
	}else{ // add newer node to the left and add links
		//cout << "adding to left " << val->val  << endl;
		val->right = tail;
		val->right->left = val;
		tail = val;
		//list = tmp;
	}
}

Node* Deque(Node* &head){
	if(size == 0){
		return nullptr;
	}
	Node* tmp = head;
	head = head-> left;
	
	tmp->left = nullptr;
	tmp->right = nullptr;
	size--;
	
	return tmp;
	
}

		
		

void printList(Node *list){
	Node* tmp = list; //copy reference to head so that it is not modified by mistake
	while(tmp != nullptr){
		cout << "P" << tmp->name << "("  << tmp->val << "),";
		tmp = tmp->left; //traverse
	}
	cout << endl;
}