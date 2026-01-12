#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   Node* next;
   char val;
   Node(char val){
     this->val=val;
     next = NULL;
   }
};

Node* buildList(string &s){
  Node *head = NULL;
  Node *tail = NULL;
  for (auto ch : s)
  {
    Node *newNode = new Node(ch);
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

bool isVowel(char ch){
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

Node *rearrangeList(Node *head)
{
  Node *vhead = NULL, *vtail = NULL;
  Node *chead = NULL, *ctail = NULL;

  while (head)
  {
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
    head = head->next;
  }

  
  if (vtail)
    vtail->next = chead;

  if (ctail)
    ctail->next = NULL;

  return vhead ? vhead : chead;
}

void printList(Node* head){
  Node *temp = head;
  while(temp){
    cout << temp->val << "->";
    temp = temp->next;
  }
}

int main(){
  string s;
  cin >> s;
  Node* head= buildList(s);
  cout << "before Reaarange:->";
  printList(head);
  cout << endl;
  Node* newHead=rearrangeList(head);
  cout << "After Reaarange:->";
  printList(newHead);
  cout << endl;

  return 0;
}