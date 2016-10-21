#include <iostream>
class Template{
   private:
      struct Node{
         char info;
         Node* next;
      };
      Node* list;
   public:
      Template();
      bool isEmpty();
      int length();
      Node* cons(char x, Node* p);
      bool append(char a);
      bool append(char a, Node* head);
      bool remove(char a);
      bool remove(char a, Node*head, Node* previous);
      bool search(char a);
      bool search(char a, Node* head);
      char getFirst();
      void reverse();
      void printList(std::ostream& fout);
      void printList(std::ostream& fout, Node* p);
       
      /*
      Node* cons(int x, Node* p);
      void readList(std::istream& fin);
      Node* readBackwardList(std::istream& fin);
      void deleteList(Node* &p);
      void printList(std::ostream& fout);
      void printList(std::ostream& fout, Node* p);
   */
};
