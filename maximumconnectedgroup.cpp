#include<iostream>
#include<vector>
#include<set>
using namespace std;
class DisjointSet {
    public:
    vector<int> rank, size, parent;
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
    bool isValid(int r, int c, int n) {
        return r >= 0 && c >= 0 && r < n && c < n;
    }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int res = INT_MIN;
        vector<vector<int>> directions {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) {
                    set<int> s;
                    int size = 1;
                    for (auto dir : directions) {
                        int nr = r + dir[0];
                        int nc = c + dir[1];
                        int node = nc + (nr * n);
                        if (isValid(nr, nc, n)) {
                            int up = ds.findUParent(node);
                            if (s.find(up) == s.end()) {
                                s.insert(up);
                                size += ds.size[up];
                            }
                        }
                    }
                    res = max(res, size);
                }
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}