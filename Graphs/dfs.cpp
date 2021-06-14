#include <iostream>
#include <vector>

using namespace std;
void dfs(int i, vector<vector<int> > &graph, vector<bool> &visited){
    visited[i] = true;
    cout<<i<<" ";
    for(int it = 0; it<graph[i].size(); it++){
        if(!visited[it]){
            dfs(it, graph, visited);
        }
    }
}
void dfsTraversal(vector<vector<int>> &graph, int n){
    vector<bool> visited(n,false);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i,graph, visited);
        }
    }

}
int main(){
  vector<vector<int> > graph;
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  graph.push_back(v);
  v.clear();
  v.push_back(0);
  v.push_back(3);
  graph.push_back(v);
  v.clear(); 
  v.push_back(1);
  v.push_back(0);
  graph.push_back(v);
  v.clear(); 
  v.push_back(2);
  v.push_back(3);
  graph.push_back(v);

  dfsTraversal(graph,4);

}