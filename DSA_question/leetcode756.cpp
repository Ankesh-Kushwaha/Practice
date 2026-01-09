#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class solution{

  public:
    unordered_map < string, bool >dp;
    bool solve(string curr, unordered_map<string, vector<char>> &mp, int idx, string next)
    {
      if (curr.length() == 1) // pyramid formation is possible
        return true;

      string key = curr + "_" + to_string(idx) + "_" + next;
      if(mp.count(key))
        return dp[key];

      if (idx == curr.length() - 1)
      {
        return dp[key]= solve(next, mp, 0, ""); // move to the second layer
      }

      string pair = curr.substr(idx, 2);
      if (mp.find(pair) == mp.end())
        return dp[key]= false; // does not find the actual small pyramid to form;

      // explore for the all
      for (auto &ch : mp[pair])
      {
        next.push_back(ch); // do

        if (solve(curr, mp, idx + 1, next))
          return dp[key]= true; // explore

        next.pop_back(); // undo;
      }

      return dp[key]= false;
    }

  bool pyramidTransition(string bottom,vector<string> &allowed){
    unordered_map<string, vector<char>> mp;
    for(auto str:allowed){
      mp[str.substr(0, 2)].push_back(str[2]);
    }
    return solve(bottom, mp, 0, "");
  }

};

int main(){
  solution sol;
  string bottom = "BCD";
  vector<string> allowed = {"BCC", "CDE", "CEA", "FFF"};
  bool answer = sol.pyramidTransition(bottom,allowed);
  cout << answer << endl;
}
