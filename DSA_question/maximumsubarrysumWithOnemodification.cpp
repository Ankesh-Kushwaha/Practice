#include <bits/stdc++.h>
using namespace std;

int maxSubarrayWithOneDouble(vector<int> &a)
{
  int n = a.size();

  int dp0 = a[0];     // no doubling used
  int dp1 = 2 * a[0]; // doubling used on first element

  int ans = max(dp0, dp1);

  for (int i = 1; i < n; i++)
  {
    dp1 = max(dp1 + a[i], dp0 + 2 * a[i]);
    dp0 = max(a[i], dp0 + a[i]);
    ans = max(ans, max(dp0, dp1));
  }

  return ans;
}

int main()
{
  vector<int> a = {-2, 1 ,-3 ,4, -1 ,2 ,1 ,-5, 4};
  cout << maxSubarrayWithOneDouble(a);
  return 0;
}
