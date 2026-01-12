#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> findMissing(vector<int> &arr){
  int total = (arr.size() + 2) * (arr.size() + 3) / 2;

  int sum = 0;
  for (int i = 0; i < arr.size();i++){
    sum += arr[i];
  }

  int diff = total - sum;
  int mid = diff / 2;
  int leftSum = 0;
  for (int i = 0;i<arr.size();i++){
      if(arr[i]<=mid){
        leftSum += arr[i];
      }
  }

  int expectedSum = mid * (mid + 1) / 2;
  int a=expectedSum-leftSum;
  return {a,diff- a};
}

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }

  pair<int, int> t = findMissing(arr);
  cout <<t.first<<" "<<t.second<< endl;
  return 0;
}