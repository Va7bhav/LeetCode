#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
    int N;
    vector<int> size, parent;
    public:
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        N = n;
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
        N -= 1;
    }

    bool isConnected() {
        if (N == 1) return true;
        return false;
    }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet Alice(n), Bob(n);
        int res = 0;
        for (vector<int> edge: edges) {
            int color = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (color == 1) {
                if (Alice.findUParent(u) == Alice.findUParent(v)) {
                    res += 1;
                }
                else {
                    Alice.unionBySize(u, v);
                }
            }
            else if (color == 2) {
                if (Bob.findUParent(u) == Bob.findUParent(v)) {
                    res += 1;
                }
                else {
                    Bob.unionBySize(u, v);
                }
            } 
            else {
                if (Alice.findUParent(u) == Alice.findUParent(v)) {
                    res += 1;
                } 
                else {
                    Alice.unionBySize(u, v);
                }
                if (Bob.findUParent(u) == Bob.findUParent(v)) {
                    res += 1;
                }
                else {
                    Bob.unionBySize(u, v);
                }
            }
        }
        if (Alice.isConnected() && Bob.isConnected()) {
            return res;
        }
        return -1;
    }
};
int main() {
    
    return 0;
}