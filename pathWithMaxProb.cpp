#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double, int>> adj[n];
        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        priority_queue<pair<double, int>> maxHeap;

        vector<double> prob(n, 0);
        prob[start] = 1;

        maxHeap.push({1, start});
        double res = 0;
        while (!maxHeap.empty()) {
            pair<double, int> apex = maxHeap.top(); maxHeap.pop();
            double p = apex.first;
            int node = apex.second;
            if (node == end) {
                res = max(res, p);
            }
            for (auto it: adj[node]) {
                double edgeProb = it.first;
                int neigh = it.second;
                if (p * edgeProb > prob[neigh]) {
                    prob[neigh] = (double)p * edgeProb;
                    maxHeap.push({prob[neigh], neigh});
                }
            }
        }
        return res;
    }
};
int main() {
    
    return 0;
}