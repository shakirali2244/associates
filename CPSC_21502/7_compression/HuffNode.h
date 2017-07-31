
#ifndef HUFFNODE_H
#define HUFFNODE_H
class HuffNode{
   public:
      char val;
      int freq;
      bool parent;
      HuffNode(){
	 parent = false;
         val = '\n';
         freq = -1;
      }
      HuffNode* left;
      HuffNode* right;
      };
      
      bool operator<(const HuffNode& lhs, const HuffNode& rhs)
	{
		return lhs.freq > rhs.freq;
	}
	bool operator>(const HuffNode& lhs, const HuffNode& rhs)
	{
		return lhs.freq < rhs.freq;
	}
#endif