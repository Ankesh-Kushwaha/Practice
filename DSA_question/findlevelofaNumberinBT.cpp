#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   Node* left;
   Node *right;
   int val;

   Node(int val){
     this->val = val;
     left = NULL;
     right = NULL;
   }
};


Node* buildTree(){
   int num;
   cin>>num;
   if(num==-1)
     return NULL;
   
   Node *newNode=new Node(num);
   newNode->left = buildTree();
   newNode->right = buildTree();
   return newNode;
}

int findLevel(Node* root,int X){
  if(root==NULL)
    return -1;

  queue<Node *> q;
  q.push(root);
  int level = 0;
  while(!q.empty()){
    int sz = q.size();
    while(sz--){
      Node *curr = q.front();
      q.pop();

      if (curr->val == X)
      {
        return level;
      }
      
      if(curr->left!=NULL)
        q.push(curr->left);
      
      if(curr->right!=NULL)
        q.push(curr->right);

    }
    level++;
  }
  return -1;
}

int main(){
  Node *root = buildTree();
  int X;
  cin>>X;
  cout << findLevel(root,X)<<endl;
  return 0;
}