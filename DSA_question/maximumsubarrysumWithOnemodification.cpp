#include<bits/stdc++.h>
using namespace std;


int maxSum(vector<int> &arr){
  int ans = INT_MIN;
  int dp0 = arr[0];
  int dp1 = 2 * arr[0];
  ans = max(dp0, dp1);

  for (int i = 1; i < arr.size();i++){
    int new_dp1 = max({dp0 + 2 * arr[i], dp1 + arr[i],2*arr[i]});
    int new_dp0 = max(arr[i], dp0 + arr[i]);

    dp0 = new_dp0;
    dp1 = new_dp1;
    ans = max({ans, dp0, dp1});
  }
  return ans;
}


int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n;i++){
    cin >> arr[i];
  }
  cout << maxSum(arr) << endl;
  return 0;
}