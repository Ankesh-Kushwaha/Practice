#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
      public:
      Node* left;
      Node *right;
      int val;
      Node(){
            left=nullptr;
            right = nullptr;
            val = 0;
      }

      Node(int val){
        left = nullptr;
        right = nullptr;
        this->val = val;
      }
};

class BinaryTree{
    Node *root = nullptr;
    public:
    //create a binary Tree from array
    int idx = -1;
    Node* createBT(vector<int> &arr){
      idx++;
      if (arr[idx]==-1)
        return NULL;
      
      //create a new node
      Node *newNode = new Node(arr[idx]);
      newNode->left = createBT(arr);
      newNode->right = createBT(arr);
      return newNode;
    }

    // create Binary Tree without array;
    Node* createBT2(){
      int val;
      cin >> val;
      if(val==-1)
        return NULL;
      
      //create a new node
      Node *newNode = new Node(val);
      newNode->left = createBT2();
      newNode->right = createBT2();
      return newNode;
    }

    // traversal on tree
    // 1.levelorder Traversel;
    void levelOrder(Node* root){
           queue<Node*> q;
           q.push(root);
           while(!q.empty()){
             int n = q.size();
             while(n--){
               Node *curr = q.front();
               q.pop();

               cout << curr->val << " ";
               if(curr->left!=NULL)
                 q.push(curr->left);
              
              if(curr->right!=NULL)
                q.push(curr->right);
             }
             cout << endl;
           }
    }

    // 2.preorder traversal;
    void preorder(Node* root){
           if(root==NULL)
             return;

           cout << root->val << " ";
           preorder(root->left);
           preorder(root->right);
    }

    // 2.  inorder traversal;
    void inorder(Node* root){
       if(root==NULL){
         return;
       }

       inorder(root->left);
       cout << root->val << " ";
       inorder(root->right);
    }

    //3. postorder
    void postorder(Node* root){
          if(root==NULL)
            return;

          postorder(root->left);
          postorder(root->right);
          cout << root->val << " ";
    }
};

int main(){
  //vector<int> arr = {0, 1, -1, -1, 3, 2, -1, -1, -1};
  BinaryTree bt;
  cout << "enter value in preorder:" << endl;
  Node*root= bt.createBT2();
  cout << "printing levelorder:" << endl;
  bt.levelOrder(root);
  cout << "printing preorder" << endl;
  bt.preorder(root);
  cout << "printing inorder" << endl;
  bt.inorder(root);
  cout << "printing postorder:" << endl;
  bt.postorder(root);
  return 0;
}