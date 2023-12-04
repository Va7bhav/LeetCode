#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({v, t});
        }

        vector<int> time(n + 1, 1e9); 
        time[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            int nodeTime = pq.top().first;
            int nodeVal = pq.top().second;
            pq.pop();
            for(pair<int, int> pair : adj[nodeVal]) {
                int currVal = pair.first;
                int currTime = pair.second;
                if(currTime + nodeTime < time[currVal]) {
                    time[currVal] = currTime + nodeTime;
                    pq.push({time[currVal], currVal});
                }
            }
        }
        
        int res = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(time[i] == 1e9) return -1;
            res = max(res, time[i]);
        }
        return res;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({v, t});
        }

        vector<int> time(n + 1, 1e9);
        time[k] = 0;

        set<pair<int, int>> s;
        s.insert({0, k});

        while(!s.empty()) {
            int nodeTime = (*s.begin()).first;
            int nodeVal = (*s.begin()).second;
            s.erase({nodeTime, nodeVal});
            for(pair<int, int> pair : adj[nodeVal]) {
                int currVal = pair.first;
                int currTime = pair.second;
                if(currTime + nodeTime < time[currVal]) {
                    if(time[currVal] != 1e9) s.erase({currTime, currVal});
                    time[currVal] = currTime + nodeTime;
                    s.insert({time[currVal], currVal});
                }
            }
        }
        int res = INT_MIN;
        for(int i = 1; i <= n; i++) {
            if(time[i] == 1e9) return -1;
            res = max(res, time[i]);
        }
        return res;
    }
};
int main() {
    
    return 0;
}