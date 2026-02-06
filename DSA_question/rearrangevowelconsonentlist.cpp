#include<bits/stdc++.h>
using namespace std;
class Node{
public:
  Node *next;
  char val;

  Node(char val){
    this->val = val;
    next = NULL;
  }
};

Node* buildList(string &s){
  Node* head=nullptr;
  Node *tail = nullptr;

  for(auto c:s){
    Node *newNode = new Node(c);
    if(!head){
      head = newNode;
      tail = newNode;
    }
    else{
      tail->next = newNode;
      tail = newNode;
    }
  }
  return head;
}

void printList(Node* head){
   while(head){
     cout << head->val << "->";
     head = head->next;
   }
   cout << endl;
}

bool isVowel(char c){
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

Node *rearrange(Node *head)
{
  Node *vhead = nullptr, *vtail = nullptr;
  Node *chead = nullptr, *ctail = nullptr;

  while (head)
  {
    Node *nextNode = head->next; // save next
    head->next = nullptr;        // detach

    if (isVowel(head->val))
    {
      if (!vhead)
      {
        vhead = vtail = head;
      }
      else
      {
        vtail->next = head;
        vtail = head;
      }
    }
    else
    {
      if (!chead)
      {
        chead = ctail = head;
      }
      else
      {
        ctail->next = head;
        ctail = head;
      }
    }
    head = nextNode;
  }

  if (vtail)
    vtail->next = chead;

  return vhead ? vhead : chead;
}

int main(){
  string s;
  cin >> s;

 Node* head=buildList(s);

 cout << "before rearrange" << endl;
 printList(head);
 Node *newhead = rearrange(head);
 cout << "after rearrange" << endl;
 printList(newhead);
 return 0;
}