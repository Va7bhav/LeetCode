#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;

class Solution {
    double bfs(string src, string target, map<string, vector<pair<string, double>>> adj) {

        if (adj.find(src) == adj.end() || adj.find(target) == adj.end()) return -1;
        queue<pair<string, double>> q;
        unordered_set<string> visit;
        q.push({src, 1});
        visit.insert(src);

        while (!q.empty()) {
            string n = q.front().first;
            double w = q.front().second;
            q.pop();

            if (n == target) {
                return w;
            }

            for (auto it: adj[n]) {
                if (visit.find(it.first) == visit.end()) {
                    visit.insert(it.first);
                    q.push({it.first, w * it.second});
                }
            }
        }

        return (double)-1;
        
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> res;
        for (auto q: queries) {
            res.push_back(bfs(q[0], q[1], adj));
        }

        return res;
    }
};
int main() {
    
    return 0;
}