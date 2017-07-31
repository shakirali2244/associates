
#ifndef BTREE_H
#define BTREE_H

#include "BTreeNode.h"
#include <iostream>
using namespace std;
class BTree {
   public:
	   
      BTreeNode* root;
      BTree(){
	      root = new BTreeNode();
      }
      
      void insert(int t){
	      insert(root, nullptr, 0, t);
      }
      
      void insert(BTreeNode* node, BTreeNode* parent, int pos, int t){
	      if (node == nullptr){
		      cout << "null passed" << endl;
		      return;
	      }
         if(node->leaf){
		   if(node->keyTally == 0){
			   node->keys[0] = t;
			   node->keyTally++;
			   cout << "inserted first " << t <<  endl;
			   for(int j = 0; j < node->keyTally; j++){
					cout << ", " <<  node->keys[j] << ", " ;
			   }
			   cout << endl;
			   return;
		   }
		    if(node->keyTally < (int)((float)M/(float)2)){ // if not full
			    for(int i=0; i < node->keyTally; i++){ 
				       if (node->keys[i] > t){
					  //cout << "inserted " << t << " ";
					  int j = i, temp =node->keys[j];
					  for(j = i; j < node->keyTally; j++){
						     temp = node->keys[j];
						     node->keys[j] = t;
						     t = temp;
					  } //for
					  node->keys[j] = t;
					  node->keyTally++;
					  //cout << "keyTally = " << node->keyTally <<  endl;
					   for(int j = 0; j < node->keyTally; j++){
					//	   cout << ", " <<  node->keys[j] << ", " ;
					   }
					 // cout << endl;
					  return;
				       }
				}
				//cout << "inserted " << t << " ";
				node->keys[node->keyTally] = t;
				node->keyTally++;
				//cout << "keyTally = " << node->keyTally <<  endl;
				for(int j = 0; j < node->keyTally; j++){
				//		   cout << ", " <<  node->keys[j] << ", " ;
					   }
				//	  cout << endl;
				return;
				
			}else{ // split
				
				for(int i=0; i < node->keyTally; i++){ 
				       if (node->keys[i] > t){
					  int j=i, temp;
					  for(j = i;j < node->keyTally; j++){
						     temp = node->keys[j];
						     node->keys[j] = t;
						     t = temp;
					  } 
					  node->keys[j] = t;
					  node->keyTally++;
					  break;
					} else if (i == (node->keyTally)){
						node->keys[i+1] = t;
						 node->keyTally++;
					}
				}
				
				int halfway = (int)((float)node->keyTally/(float)2);
				
				//cout << "halfway = " << halfway << endl;
						
				//cout << "inside split logic" << endl; 
				cout << "trying to split at " <<  node->keys[halfway] <<endl;
					 for(int j = 0; j < node->keyTally; j++){
						   cout << ", " <<  node->keys[j] << ", " ;
					   }
					  cout << endl;
				       
				
				
				BTreeNode* nodert = new BTreeNode();
				int j = 0;
				
				for(int i = (halfway +1); i < node->keyTally; i++){
					nodert->keys[j] = node->keys[i];
					j++;
					nodert->keyTally++;
				}
									
				 /// BUGGY PART
				if (parent != nullptr){
					node->keyTally = halfway;
					int i,temp;
					BTreeNode* tmp;
					int helper = node->keys[halfway];
					for(i=pos; i < parent->keyTally; i++){ 
					     temp = parent->keys[i];
					     tmp = parent->pointers[i+1];
				
					     parent->keys[i] = helper;
					     parent->pointers[i+1] = nodert;
				
					     helper= temp;
					     nodert = tmp;
					}
					parent->keys[i] = helper;
					parent->pointers[i+1] = nodert;
					// end BUGGY PART
				} else{
					//cout << "creating new root with " <<  node->keys[halfway] << endl;
					node->keyTally = halfway;
					BTreeNode* newroot = new BTreeNode();
					newroot->keys[0] = node->keys[halfway];
					newroot->pointers[0] = node;
					newroot->pointers[1] = nodert;
					
					newroot->keyTally++;
					newroot->leaf = false;
					
					root = newroot;
				}
				
				node->leaf = false;
				
            }
         } else{
		for(int i=0; i < node->keyTally; i++){ 
			       if (t < node->keys[i]){
				       cout << "recursive call a " << i << " " << t <<   endl;
				       insert(node->pointers[i],node, i, t);
			       } else if(i == (node->keyTally)-1){
				       //cout << "keyTally " << node->pointers[i+1]->keyTally << endl;
				       cout << "recursive call b " << i << " " << t <<   endl;
				       insert(node->pointers[i+1],node, i+1, t);
			       }
			}
		}
	}
	       
       void print(std::ostream& out){
	       out << "[ ";
	       print(out, root);
	       out << " ]" << endl;
       }
       
       void print(std::ostream& out, BTreeNode* node){
	    if (node == nullptr){
		    return;
	    }
	    int i; 
	    for (i=0; i < node->keyTally; i++){
		print(out, node->pointers[i]);
		out << " " << node->keys[i];
	    }
	    print(out, node->pointers[i]);
    }
	    
};
#endif
      