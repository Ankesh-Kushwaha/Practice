#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
    Node *left;
    Node *right;
    int val;

    Node(int val){
      this->val = val;
      left = right = nullptr;
    }
};

Node* buildTree(vector<int> &arr){ //level order
  if(arr[0]==-1)
    return NULL;
  Node *root = new Node(arr[0]);
 int idx = 1;
  queue<Node *> q;
  q.push(root);

  while(!q.empty() && idx<arr.size()){
    Node *curr = q.front();
    q.pop();
    
    if( idx<arr.size() && arr[idx]!=-1){
      curr->left = new Node(arr[idx]);
      q.push(curr->left);
    }

    idx++;
    if(idx<arr.size() && arr[idx]!=-1){
      curr->right = new Node(arr[idx]);
      q.push(curr->right);
    }

    idx++;
  }
  return root;
}

int findX(Node* root,int x){
       if(root==NULL)
         return 0;

       queue<Node *> q;
       q.push(root);
       int level = 0;
       while(!q.empty()){
        int n=q.size();
        while(n--){
          Node *curr = q.front();
          q.pop();

          if (curr->val == x)
            return level;

          if (curr->left != NULL)
          {
            q.push(curr->left);
          }

          if (curr->right != NULL)
          {
            q.push(curr->right);
          }
        }
        level++;
    }
    return 0;
}

int main(){
  int n;
  cin>>n;
  int x;
  cin >> x;

  vector<int> arr(n);
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }
  

  Node *root = buildTree(arr);
  cout << findX(root,x) << endl;
  return 0;
}