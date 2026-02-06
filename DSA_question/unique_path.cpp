#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, vector<vector<char>> &grid, int d_x, int d_y)
{
  if (i >= grid.size() || j >= grid[0].size())
    return 0;

  if (i > d_x || j > d_y) // 🔥 must come BEFORE destination
    return 0;

  if (grid[i][j] == 'x')
    return 0;

  if (i == d_x && j == d_y)
    return 1;

  return solve(i + 1, j, grid, d_x, d_y) + solve(i, j + 1, grid, d_x, d_y);
}

int main()
{
  int m, n, d_x, d_y;
  cin >> m >> n >> d_x >> d_y;
  vector<vector<char>> grid(m, vector<char>(n));
  for (int i = 0;i<m;i++){
    for (int j = 0; j < n;j++){
      cin >> grid[i][j];
    }
  }

    cout << solve(0, 0, grid, d_x, d_y) << endl;
  return 0;
}