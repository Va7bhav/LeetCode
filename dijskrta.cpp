#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

 
// using priority_queue    t.c = E log V    
// https://youtu.be/3dINsjyfooY?t=334
class Solution {
    public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, 1e9);
        dist[S] = 0;
            
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, S});    

        while (!pq.empty()) {
            int dis = pq.top().first; // dist[nodeVal]
            int nodeVal = pq.top().second;
            pq.pop();
            for (vector<int> pair : adj[nodeVal]) {
                int val = pair[0];
                int edgeWt = pair[1];
                if (dis + edgeWt < dist[val]) {
                    dist[val] = dis + edgeWt;
                    pq.push({dist[val], val});
                }
            }
        }
        return dist;
    }   
};

// using set 
// https://youtu.be/PATgNiuTP20?t=302
class Solution {
    public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        set<pair<int, int>> s;
        s.insert({0, S});

        while (!s.empty()) {
            int dis = (*s.begin()).first;
            int nodeVal = (*s.begin()).second;
            s.erase({dis, nodeVal});
            for (vector<int> pair : adj[nodeVal]) {
                int val = pair[0];
                int edgeWt = pair[1];
                if (dis + edgeWt < dist[val]) {
                    if (dist[val] != 1e9) s.erase({dist[val], val});
                    dist[val] = dis + edgeWt;
                    s.insert({dist[val], val});
                }
            }
        }
        return dist;
    }   
};
int main() {
     
    return 0;
}