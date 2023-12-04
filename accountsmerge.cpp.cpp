#include<iostream>
#include<vector>
#include<unordered_map>
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailToNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailToNode.find(mail) == mailToNode.end())
                    mailToNode[mail] = i;
                else {
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }
        vector<string> mergeMail[n];
        for (auto it : mailToNode) {
            string mail = it.first;
            int node = ds.findUParent(mailToNode[mail]);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>> res;
        
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto str : mergeMail[i]) {
                temp.push_back(str);
            }
            res.push_back(temp);
        }
        return res;
    }
};




int main() {
    
    return 0;
}