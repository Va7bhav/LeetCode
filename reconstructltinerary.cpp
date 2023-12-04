#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
    bool dfs(string src, map<string, vector<string>> adj, vector<string>& res, vector<vector<string>>& tickets) {
        if (res.size() == tickets.size() + 1) 
            return true;
        if (adj.find(src) == adj.end()) 
            return false; // source does not have out going edges

        for (int i = 0; i < adj[src].size(); i++) {
            auto iter = adj[src].begin() + i;
            string temp = *iter;
            res.push_back(temp);
            adj[src].erase(iter);
            if (dfs(temp, adj, res, tickets)) return true;
            else {
                adj[src].insert(iter, temp);
                res.pop_back();
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        map<string, vector<string>> adj;
        for (vector<string> edge : tickets) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<string> res;
        res.push_back("JFK");
        dfs("JFK", adj, res, tickets);
        return res;
    }
};





int main() {
    
    return 0;
}