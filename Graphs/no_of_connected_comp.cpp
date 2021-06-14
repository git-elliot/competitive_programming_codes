// Find number of connected components in an undirected graph
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int w){
    if(w == parent[w]){
        return w;
    }
    return find(parent[w]);
}

void doUnion(int u, int v){
    int uP = find(u);
    int vP = find(v);

    parent[uP] = vP;
}

int numberOfConnectedComponents(vector<pair<int,int> > edges){
    for(int i=0; i<edges.size(); i++){
        pair<int,int> p = edges[i];
        doUnion(p.first, p.second);
    }
    int count = 0;
    for(int i=0; i<parent.size(); i++){
        if(parent[i] == i){
            count++;
        }
    }

    return count;
}

int main(){

    int i,v,e;
    cin>>v>>e;
    vector<pair<int,int> > edges;
    int e1,e2;
    for(i=0; i < e; i++){
        cin>>e1>>e2;
        edges.push_back(make_pair(e1,e2));
    }
    parent.resize(v);
    for(i=0; i<v; i++){
        parent[i] = i;
    }

    cout<<numberOfConnectedComponents(edges);

}