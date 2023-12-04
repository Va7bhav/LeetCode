#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class DisjointSet {
    public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int node) {
        if (node == parent[node]) return node;
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
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<int> adj[edges.size()];

        for (vector<int> edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // for each value create sets and then count the vals in those sets this will give the the paths including the vals themselves as they are also supposed to be considered
        
        unordered_map<int, vector<int>> valToIndex;
        for (int i = 0; i < vals.size(); i++) {
            valToIndex[vals[i]].push_back(i);
        }
        
        DisjointSet uf(vals.size());
        int res = 0;
        for (auto iter: valToIndex) {
            int val = iter.first;
            vector<int> indexes = iter.second;

            for (int i: indexes) {                
                for (int nei: adj[i]) {
                    if (vals[nei] <= vals[i]) {
                        uf.unionBySize(nei, i);
                    }
                }
            }
            unordered_map<int, int> count; // count the number 
            for (int i: valToIndex[val]) {
                count[uf.findUParent(i)] += 1;
                res += count[uf.findUParent(i)];
            }
        }
        return res;
    }
};
int main() {
    
    return 0;
}