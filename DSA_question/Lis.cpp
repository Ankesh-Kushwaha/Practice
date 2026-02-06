#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> dp(n + 1, 1);

    int ans = 1;
    for (int curr = 0; curr < n; curr++)
    {
      for (int prev = 0; prev < curr; prev++)
      {
        if (nums[curr] > nums[prev])
        {
          dp[curr] = max(dp[curr], dp[prev] + 1);
          ans = max(ans, dp[curr]);
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      cout << dp[i] << " ";
    }
    return ans;
  }
};