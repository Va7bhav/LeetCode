#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// in prim's algortithm we only store the parent in the queue when we are asked for the mst
// but here only the sum of the mst is asked we don't have to store the parent

// INTUITION - https://youtu.be/mJcZjjKzeqk?t=903
class Solution {
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        vector<int> visit(V, 0);

        int sum = 0;
        while (!pq.empty()) {
            int wt = pq.top().first;
            int val = pq.top().second;
            pq.pop(); 

            if (visit[val]) continue;
            visit[val] = 1;
            sum += wt;

            for (auto it : adj[val]) {
                int adjVal = it[0];
                int edgeWt = it[1];
                if (!visit[adjVal]) {
                    pq.push({edgeWt, adjVal});
                }
            }
        }
        return sum;
    }
};
int main() {
    
    return 0;
}