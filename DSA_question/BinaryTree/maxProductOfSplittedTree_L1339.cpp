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
    left = NULL;
    right = NULL;
  }
};

class Solution{
 public:
   int idx = -1;
   Node *createBT(vector<int> &arr)
   {
     idx++;
     if(arr[idx]==-1)
       return NULL;

     Node* root=new Node(arr[idx]);
     root->left = createBT(arr);
     root->right = createBT(arr);
     return root;
   }
   
   int findSum(Node* root){
        if(root==NULL)
          return 0;

        return root->val + findSum(root->left) + findSum(root->right);
   }

   int dfs(Node *root, int subTreeSum, long long totalSum, long long &ans){
         if(root==NULL)
           return 0;

         int left = dfs(root->left, subTreeSum, totalSum, ans);
         int right = dfs(root->right, subTreeSum, totalSum, ans);

         subTreeSum = root->val + left + right;
         cout << subTreeSum << endl;
         ans = max(ans, (totalSum - subTreeSum) * subTreeSum);
         return subTreeSum;
   }

   long long maxProductOfSplittedTree(Node* root){
     long long totalSum = findSum(root);
     long long ans = LLONG_MIN;
     dfs(root, 0,totalSum,ans);
     return ans;
   }
};

// time complexity -> O(n);
int main(){
  vector<int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, -1};
  Solution b1;
  Node* root=b1.createBT(arr);
  cout << b1.maxProductOfSplittedTree(root) << endl;
  return 0;
}