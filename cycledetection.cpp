#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// undirected : dfs
class Solution {
    bool dfs(int nodeVal, int parent, vector<int> adj[], vector<int> visit) {
        visit[nodeVal] = 1;
        for(auto currVal : adj[nodeVal]) {
            if(!visit[currVal]) {
                if(dfs(currVal, nodeVal, adj, visit)) {
                    return true;
                }
            }
            else if(currVal != parent) {
                return true;
            }
        }
        return false;
    }
    public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visit(V, 0);
        for(int i = 0; i < V; i++) {
            if(dfs(i, -1, adj, visit)) return true;
        }
        return false;
    }
};

// undirected : bfs
class Solution {
    bool detect(int val, int V, vector<int> adj[], vector<int> visit, queue<pair<int, int>> q) {
        q.push({val, -1});
        while(!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();

            int nodeVal = front.first;
            int nodeParent = front.second;
            visit[nodeVal] = 1;

            for(int currVal : adj[nodeVal]) {
                if(!visit[currVal])
                    q.push({currVal, nodeVal});

                else if(visit[currVal] && currVal != nodeParent) 
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visit(V, 0);
        queue<pair<int, int>> q;
        for(int i = 0; i < V; i++)
            if(detect(i, V, adj, visit, q)) return true;
        return false;
    }
};

// directed : DFS --> course schedule

// directed : BFS 

int main() {
    return 0;
}