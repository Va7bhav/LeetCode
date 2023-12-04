#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

// FINDING SHORTEST PATH FOR DIRECTED GRAPH
class Solution {
    void topoSort(int i, vector<pair<int, int>> adj[], stack<int>& st, vector<int> visit) {
        visit[i] = 1;
        for(auto pair : adj[i]) {
            int val = pair.first;
            if(!visit[val]) topoSort(val, adj, st, visit);
        }
        st.push(i);
    }
    public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        for(int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        stack<int> st;
        vector<int> visit(N, 0);
        for(int i = 0; i < N; i++) {
            if(!visit[i])
                topoSort(i, adj, st, visit);
        }
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while(!st.empty()) {
            int val = st.top();
            st.pop();

            for(auto pair : adj[val]) {
                int currVal = pair.first;
                int currWt = pair.second;
                if(dist[val] + currWt < dist[currVal]) 
                    dist[currVal] = dist[val] + currWt;
                // dist[currVal] = min(dist[currVal], dist[val] + currWt);
            }
        }
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};

// SHORTEST PATH FOR UNDIRECTED GRAPH
class Solution {
    public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist(N, 1e9);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while(!q.empty()) {
            int nodeVal = q.front();
            q.pop();
            
            for(int currVal : adj[nodeVal]) {
                if(dist[nodeVal] + 1 < dist[currVal]) {
                    dist[currVal] = dist[nodeVal] + 1;
                    q.push(currVal);
                }
            }        
        }
        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
int main() {
    
    return 0;
}