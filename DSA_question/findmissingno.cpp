#include <bits/stdc++.h>
using namespace std;
pair<int, int> findMissing(vector<int> &arr)
{
  int n = arr.size();
  if (n == 0)
    return {0, 0};

  int total = (n + 2) * (n + 3) / 2;
  int arr_sum = accumulate(arr.begin(), arr.end(), 0);

  int diff = total - arr_sum;
  int mid = diff / 2;
  int leftsum = 0;
  for (auto v:arr){
     if(v<=mid)
       leftsum += v;
  }

  int expectedLeft = mid * (mid + 1) / 2;
  int first = expectedLeft - leftsum;
  return {first, diff - first};
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  auto ans = findMissing(arr);
  cout << ans.first<<" "<< ans.second << endl;

  return 0;
}