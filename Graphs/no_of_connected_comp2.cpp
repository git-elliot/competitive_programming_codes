#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<bool>& visited, vector<int> graph[]){
    visited[u] = true;
    cout<<u<<" ";
    for(int i=0; i<graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(v,visited,graph);
        }
    } 
    return;
}

int main(){
    
    int i,v,e,count = 0;
    cin>>v>>e;
    vector<pair<int,int> > edges;
    int e1,e2;
    for(i=0; i < e; i++){
        cin>>e1>>e2;
        edges.push_back(make_pair(e1,e2));
    }
    vector<int> graph[v];

    for(i=0; i<edges.size(); i++){
        pair<int,int> p = edges[i];
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }
    vector<bool> visited(v, false);
    for(i=0; i<v; i++){
        if(!visited[i]){
            dfs(i,visited,graph);
            count++;
        }
    }
    cout<<"\nNumber of connected components : "<<count;
}