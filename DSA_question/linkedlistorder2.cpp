#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  Node *next;
  int val;

  Node(int val)
  {
    this->val = val;
    next = NULL;
  }
};

Node *buildList(vector<int> &arr)
{
  Node *root = nullptr;
  Node *temp = root;

  for (int i = 0; i < arr.size(); i++)
  {
    temp->next = new Node(arr[i]);
    temp = temp->next;
  }
  return root->next;
}

int main()
{
  int n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  Node *root = buildList(arr);

  int 

  return 0;
}