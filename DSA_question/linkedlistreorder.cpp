#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;

  Node(int val)
  {
    this->val = val;
    next = NULL;
  }
};

// Utility function to print list
void printList(Node *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void reorder(Node *head)
{
  if (head == NULL || head->next == NULL)
    return;

  // 1. Find middle of the list
  Node *slow = head;
  Node *fast = head;

  while (fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  // 2. Reverse second half
  Node *prev = NULL;
  Node *curr = slow->next;
  slow->next = NULL; // split list

  while (curr)
  {
    Node *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }

  // 3. Merge both halves alternately
  Node *h1 = head;
  Node *h2 = prev;

  while (h2)
  {
    Node *t1 = h1->next;
    Node *t2 = h2->next;

    h1->next = h2;
    h2->next = t1;

    h1 = t1;
    h2 = t2;
  }
}

int main()
{
  int n;
  cin >> n;

  if (n == 0)
    return 0;

  int x;
  cin >> x;
  Node *head = new Node(x);
  Node *tail = head;

  for (int i = 1; i < n; i++)
  {
    cin >> x;
    tail->next = new Node(x);
    tail = tail->next;
  }
  reorder(head);
  printList(head);

  return 0;
}
