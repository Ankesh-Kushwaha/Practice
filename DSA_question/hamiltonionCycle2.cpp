#include<bits/stdc++.h>
using namespace std;

bool isSafe(int v,vector<vector<int>> &graph,vector<int> &path,int pos){
       if(graph[path[pos-1]][v]==0)
         return false;

     //check if the vertex is used previosly
       for (int i = 0; i < pos;i++){
         if(path[i]==v)
           return false;
       }
       return true;
}

bool cycleExist(vector<vector<int>> &graph,vector<int> &path,int V,int pos){
       
  if(pos==V){
    return graph[path[pos - 1]][path[0]] == 1;
  }

  //explore the all path
  for (int v = 1; v < V;v++){
       if(isSafe(v,graph,path,pos)){
         path[pos] = v;

         if (cycleExist(graph, path, V, pos + 1))
           return true;

         // backtrack;
         path[pos] = -1;
       }
  }

  return false;
}

void findHamiltonion(vector<vector<int>> &graph,int V){
  vector<int> path(V, -1);

  path[0] = 0; //puth the first vertex in the graph
  if(!cycleExist(graph,path,V,1)){
    cout << "No hamiltanion cycle exist" << endl;
  }
 
  for (int i = 0; i < V;i++){
    cout << path[i] << "->";
  }
  cout << path[0] << endl;
}

int main(){
  int n;
  cin >> n;
  vector<vector<int>> graph(n, vector<int>(n, 0));
  for (int i = 0; i < n;i++){
    for (int j = 0; j < n;j++){
      cin >> graph[i][j];
    }
  }

  findHamiltonion(graph,n);

  return 0;
}