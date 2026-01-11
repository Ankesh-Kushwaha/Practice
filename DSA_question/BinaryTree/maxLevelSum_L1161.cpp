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
    this->left = NULL;
    this->right = NULL;
  }
};

class solution{
   public:
     int idx = -1;
     Node* createBT(vector<int> &arr){
       idx++;
       if(arr[idx]==-1)
         return NULL;

       Node *root = new Node(arr[idx]);
       root->left = createBT(arr);
       root->right = createBT(arr);
       return root;
     }

     int maxLevelSum(Node* root){
       // traverse the tree using level order and add the sum at each level;
       long long maxSum = 0;
       queue<Node *> q;
       q.push(root);
       int level = 0;
       int ans = 0;
       while(!q.empty()){
         level++;
         int n = q.size();
         long long currSum = 0;
         while(n--){
           Node *curr = q.front();
           q.pop();

           currSum += curr->val;
           if(curr->left!=NULL)
             q.push(curr->left);
           
           if(curr->right!=NULL){
             q.push(curr->right);
           }  
         }
         
         if(maxSum<currSum){
           maxSum = currSum;
           ans = level;
         }
       }
       return ans;
     }

};

int main(){
  vector<int> arr = {1, 7, 7, -1, -1, -8, -1, -1, 0, -1, -1};
  solution b1;
  Node* root=b1.createBT(arr);
  cout << b1.maxLevelSum(root) << endl;
  
  return 0;
}