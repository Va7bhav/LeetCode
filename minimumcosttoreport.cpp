#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int acc(vector<int> arr) {return accumulate(arr.begin(), arr.end(), 0);}
int MOD = 1e9 + 7;

class Solution {
    int f(int node, int parent, int seats, int& fuel, vector<int> adj[]) {

        int passengers = 0;
        for (int child: adj[node]) {
            if (child != parent) {
                int p = f(child, node, seats, fuel, adj);
                passengers += p;
                fuel += ceil(passengers / (seats*1.0));
            }
        }
        return passengers + 1;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<int> adj[roads.size() + 1];

        for (vector<int> road: roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        int fuel = 0;
        f(0, -1, seats, fuel, adj);
        return fuel;
    }
};

int main() {
    
    return 0;
}