#ifndef BTREENODE_H
#define BTREENODE_H

#include "BTree.h"
const int M = 10;
class BTreeNode {
   friend class BTree;
   public:
      BTreeNode(){
	      leaf = true;
	      keyTally = 0;
	      };
      BTreeNode(const int& el);
      
         
   private:
      bool leaf;
      int keyTally;
      int keys[M-1];
      BTreeNode* pointers[M];
};
#endif