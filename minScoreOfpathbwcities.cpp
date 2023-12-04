#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    void dfs(int node, vector<vector<pair<int, int>>> adj, vector<int>& visit, int& minEdge) {

        visit[node] = 1;
        for (pair<int, int> it: adj[node]) {
            int nei = it.first;
            int dist = it.second;
            minEdge = min(minEdge, dist);

            if (!visit[nei]) {
                dfs(nei, adj, visit, minEdge);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<int> visit(n + 1);
        int minEdge = INT_MAX;
        dfs(1, adj, visit, minEdge);
        return minEdge;
    }
};

int main() {
    
    return 0;
}