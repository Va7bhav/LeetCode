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
    public:
        int removeStones(vector<vector<int>>& stones) {
            int n = stones.size();
            int maxRow = 0, maxCol = 0;
            for (auto it : stones) {
                maxRow = max(maxRow, it[0]);
                maxCol = max(maxCol, it[1]);
            }
            vector<int> incredible(maxRow + maxCol + 1);
            DisjointSet ds(maxRow + maxCol + 1);
            set<int> s;
            for (auto coord : stones) {
                int r = coord[0];
                int c = coord[1];
                ds.unionBySize(r, c + maxRow + 1);
                s.insert(ds.findUParent());
            }
            int res = 0;
            for (int parent : s) {
                res += ds.size[parent] - 1;
            }
            return res;
        }
    };

int main() {
    
    return 0;
}