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
            for (int i = 0; i <= n; i++) {
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
            if (up_u == up_v) return;
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

class DisjointSet {
    vector<int> size, parent;
    public:
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv) return;
        else if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

int main() {
    
    return 0;
}