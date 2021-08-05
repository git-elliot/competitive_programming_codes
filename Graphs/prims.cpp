  #include<iostream>
  #include<vector>

  using namespace std;

  int spanningTree(int V, vector<vector<int>> graph[])
    {
        
        vector<int> dist(V,INT_MAX);
        vector<bool> mstSet(V,false);
        // bool mstSet[V] = {false};
        int src = 0, e = 1;
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // pq.push({0,src});
        
        // while(e<V){
        //     int u = pq.top().second;
        //     mstSet[u] = true;
        //     e++;
        //     for(int v = 0; v<V; v++){
        //         if( !mstSet[v] && graph[u][v]<dist[v]){
        //             dist[v] = graph[u][v];
        //             pq.push(make_pair(dist[v],v));
        //         }
        //     }
        // }
        int cost = 0;
        for(int i=0;i<V; i++) cost+=dist[i];
        return cost;
    }

    int main(){
        vector<vector<int>> graph = {{INT_MAX, 5,1},
                                    {5, INT_MAX, 3},
                                    {1,3, INT_MAX}
                                    };
        cout<<spanningTree(3,graph);
    }
    //mkdir -p .output && g++ -std=c++11 prims.cpp -o .output/prims.o && ./.output/prims.o