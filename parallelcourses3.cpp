#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dfs(int node, vector<int> adj[], vector<int> time, unordered_map<int, int>& max_time) {
        
        if (max_time.find(node) != max_time.end()) return max_time[node];

        int t = 0;
        for (int adjNode: adj[node]) {
            t = max(t, dfs(adjNode, adj, time, max_time));
        }

        return max_time[node] = t + time[node - 1];

    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n + 1];

        for (vector<int> relation: relations) {
            adj[relation[1]].push_back(relation[0]);
        }
        
        unordered_map<int, int> max_time;
        
        for (int i = 1; i <= n; i++) {
            dfs(i, adj, time, max_time);
        }

        int res = INT_MIN;

        for (auto iter: max_time) {
            res = max(res, iter.second);
        }

        return res;
    }
};

int main() {
  
  return 0;
}