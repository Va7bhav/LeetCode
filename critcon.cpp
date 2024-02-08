#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

class Solution {

    int timer = 1;
    vector<vector<int>> res;
    void dfs(int node, int parent, vector<int> adj[], vector<int> time, vector<int> low, vector<int> visit) {

        visit[node] = 1;
        time[node] = timer, low[node] = timer;
        timer += 1;
        for (int adjNode: adj[node]) {
            if (adjNode != parent) {
                low[node] = min(low[node], low[adjNode]);
            }
            if (!visit[adjNode]) {
                dfs(adjNode, node, adj, time, low, visit);
            }
            if (low[node] != low[adjNode]) {
                res.push_back({node, adjNode});
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (vector<int> con: connections) {
            adj[con[0]].push_back(con[1]);
            adj[con[1]].push_back(con[0]);
        }
        vector<int> visit(n);
        vector<int> time(n);
        vector<int> low(n);
        dfs(0, -1, adj, time, low, visit);
        return res;
    }
};
int main() {
  
  return 0;
}