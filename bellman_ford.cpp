#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        // to detect negative cycles :
        // as in bellman algorithm we should have got our answer after V - 1 iterations but now
        // if another iterations are giving us updating results then there is an issue and this 
        // means we have a negative cycle
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dist[u] + w < dist[v]) {
                return {-1};
            }
        }
        return dist;
    }
};
int main() {
    
    return 0;
}