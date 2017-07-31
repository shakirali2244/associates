#include<cstdlib>
#include<iostream>

using namespace std;

class Vertex{
	public:
		int val;
		Vertex(){
			val = -1;
		}
	};

class Edge{
	public:
		int weight;	
		Vertex* a;
		Vertex* b;
		Edge(){
			weight = -1;
			a = nullptr;
			b = nullptr;
		}
	};
	
class Graph{
	public:
	Vertex** ver;
	int versize;
	Edge** edg;
	int edgesize;
};

bool check(Graph* in, Vertex* ind1, Vertex* ind2);
	
Graph* makeSparseUDWG(int n){
	Graph* ret = new Graph;
	ret->versize = n;
	ret->edgesize = 0;
	ret->ver = new Vertex*[n];
	ret->edg= new Edge*[2*n];
	for(int i = 0; i < n; i ++){
		Vertex* tmp = new Vertex();
		ret->ver[i] = tmp;
	}
	
	int counter = 2*n;
	while (counter >=0){
		Vertex* val = ret->ver[(rand() % n)];
		Vertex* val2 = ret->ver[(rand() % n)];
		if (val != val2){
			if(!check(ret,val,val2)){
				Edge* tmped = new Edge();
				int weight = (rand() % n*20 )  - n*20;
				tmped->a = val;
				tmped->b = val2;
				tmped->weight = weight;
				ret->edg[ret->edgesize] = tmped;
				tmped = nullptr;
				ret->edgesize++;
			}
		}
		counter--;
	}
	return ret;
}

//need w0rk
void printGraph(Graph* g){
	Edge** e = g->edg;
	Vertex** v = g->ver;
	
	for(int i = 0; i < g->versize; i++){
		for(int j = 0; j < g->edgesize; j++){
			if(e[j]->a == v[i])
					cout << "*";
			else
					cout << " ";
		}
		cout << endl;
	}
}
		
	
bool check(Graph* in, Vertex* ind1, Vertex* ind2){
	for(int i = 0; i < in->edgesize; i++){
		if((in->edg[i]->a == ind1 && in->edg[i]->b == ind2) || (in->edg[i]->b == ind1 && in->edg[i]->a == ind2)){
				return true;
			}
			else {
				return false;
			}
	}
	return false;
}

			
		
		
		
		
		
		