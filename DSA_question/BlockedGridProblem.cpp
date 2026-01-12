#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
  int m, n;
  vector<vector<int>> dp;

  int solve(int i, int j, vector<vector<char>> &grid)
  {
    // boundary check
    if (i >= m || j >= n)
      return 0;

    // blocked cell
    if (grid[i][j] == 'X')
      return 0;

    // destination
    if (i == m - 1 && j == n - 1)
      return 1;

    // memo check
    if (dp[i][j] != -1)
      return dp[i][j];

    // move right & down
    return dp[i][j] = solve(i + 1, j, grid) + solve(i, j + 1, grid);
  }

  int findUniqueWay(vector<vector<char>> grid)
  {
    m = grid.size();
    n = grid[0].size();
    dp.assign(m, vector<int>(n, -1));
    return solve(0, 0, grid);
  }
};

int main()
{
  vector<vector<char>> arr = {
      {'.', '.', '.'},
      {'.', 'X', '.'},
      {'.', '.', '.'}};

  solution sol;
  cout << sol.findUniqueWay(arr) << endl;
  return 0;
}
