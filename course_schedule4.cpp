#include<iostream>
#include<map>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
    unordered_set<int> dfs(int crs, map<int, unordered_set<int>>& prereqMap, vector<int> adj[]) {
        
        if (prereqMap.find(crs) == prereqMap.end()) {
            unordered_set<int> pMap;
            for (int prereq: adj[crs]) {
                for (int node: dfs(prereq, prereqMap, adj)) {
                    pMap.insert(node);
                }
            }
            pMap.insert(crs);
        }

        return prereqMap[crs];
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> adj[10];
        for (auto pre: prerequisites) {
            adj[pre[0]].push_back(pre[1]);
        }

        map<int, unordered_set<int>> prereqMap;
        for (int crs = 0; crs < numCourses; crs++) {
            dfs(crs, prereqMap, adj);
        }

        vector<bool> res;
        for (int i = 0; i < queries.size(); i++) {
            res.push_back(prereqMap[queries[i][1]].find(queries[i][0]) 
                                != prereqMap[queries[i][1]].end());
        }

        return res;
    }
};
int main() {
    
    return 0;
}