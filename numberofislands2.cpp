#include<iostream>
#include<vector>
using namespace std;
class DisjointSet {
    vector<int> rank, size, parent;
    public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUParent(int nodeVal) {
        if (parent[nodeVal] == nodeVal) return parent[nodeVal];
        return parent[nodeVal] = findUParent(parent[nodeVal]);  // path compression
    } 
    void unionByRank(int u, int v) {
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        // up_x is ultimate parent of x
        if (up_u == up_v)  return;
        else if (rank[up_u] > rank[up_v]) {
            parent[up_v] = up_u;
        }
        else if (rank[up_u] < rank[up_v]) {
            parent[up_u] = up_v;
        }
        else {
            parent[up_v] = up_u;
            rank[up_u] += 1;
        }
    }
    void unionBySize(int u, int v) {
        int up_u = findUParent(u);
        int up_v = findUParent(v);
        if (up_u == up_v)  return;
        else if (size[up_u] > size[up_v]) {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        else {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        
    }
};
class Solution {
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        int k = operators.size();
        vector<vector<int>> visit(n, vector<int> (m, 0));
        int count = 0;
        vector<int> res;
        vector<vector<int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto it : operators) {
            int r = it[0];
            int c = it[1];
            if (visit[r][c] == 1) {
                res.push_back(count);
                continue;
            }
            visit[r][c] = 1;
            count += 1;
            int node = (r * m) + c;
            
            for (auto direc : directions) {
                int nr = r + direc[0];
                int nc = c + direc[1];
                int newNode = (nr * m) + nc;
                if (isValid(nr, nc, n, m)) {
                    if (visit[nr][nc] == 1) {
                        if (ds.findUParent(node) != ds.findUParent(newNode)) {
                            count -= 1;
                            ds.unionBySize(node, newNode);
                        }
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};

int main() {
    
    return 0;
}