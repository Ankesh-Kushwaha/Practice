#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int solve(int sum,int val,vector<vector<int>> &dp){
    if(sum==0){
      return 1;
    }
   
    if(dp[sum][val]!=-1)
      return dp[sum][val];
    if (val > sum)
      return 0;

    int  take = solve(sum - val, val,dp); //we can take  more
    int not_take = solve(sum, val + 1,dp);
    return dp[sum][val]= take + not_take;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(1000, vector<int>(1000, -1));
  int ans = solve(n,m,dp);
  cout << ans << endl;
  return 0;
}