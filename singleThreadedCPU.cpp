#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        int i = 0, time = tasks[0][0];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // {intime, processing time, index}
        vector<int> res;
        while (!minHeap.empty() || i < tasks.size()) {
            while (i < tasks.size() || time >= tasks[i][0]) {
                minHeap.push({tasks[i][1], tasks[i][2]});
                i += 1;
            }
            if (minHeap.empty()) {
                time += tasks[i][0];
            }
            else {
                pair<int, int> apex = minHeap.top(); minHeap.pop();
                int processing_time = apex.first;
                int curr_index = apex.second;
                time += processing_time;
                res.push_back(curr_index);
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}