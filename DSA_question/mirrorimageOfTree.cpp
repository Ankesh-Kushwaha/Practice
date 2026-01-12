#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    Node *left;
    Node *right;
    int val;

    Node(int val){
      this->val = val;
      left=NULL;
      right = NULL;
    }

};


static int idx=-1;
Node* buildTree(vector<int> &arr){
  idx++;
  if(arr[idx]==-1)
    return NULL;

  Node* root=new Node(arr[idx]);
  root->left=buildTree(arr);
  root->right = buildTree(arr);
  return root;
}

void printTree(Node* root){
   if(root==NULL)
     return;

   cout << root->val << " ";
   printTree(root->left);
   printTree(root->right);
}

void findMirror(Node* root){
    if(root==NULL)
      return;

    swap(root->right, root->left);
    findMirror(root->left);
    findMirror(root->right);
}

int main(){
  int n;
  cin >> n; //enter the number of nodes

  vector<int> arr(n);
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }

  Node *root = buildTree(arr);
  // cout << "before" << endl;
  // printTree(root);
  // cout << endl;
  findMirror(root);
  // cout << "After" << endl;
  printTree(root);
  // cout << endl;

  return 0;
}