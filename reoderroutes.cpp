#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, bool>> adj[4];
        for (int i = 0; i < n - 1; i++) {
            int node1 = connections[i][0];
            int node2 = connections[i][1];
            adj[node1].push_back({node2, true});
            adj[node2].push_back({node1, false});
        }
        vector<int> visit(n);
        queue<int> q;
        q.push(0);
        visit[0] = 1;
        int res = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (pair<int, bool> it: adj[node]) {
                int neighbour = it.first;
                bool connection_from_node_to_neighbour = it.second;
                if (visit[neighbour] = 1) continue;
                if (connection_from_node_to_neighbour == true) {
                    res += 1;
                }
                visit[neighbour] = 1;
                q.push(neighbour);
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}