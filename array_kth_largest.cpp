#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> minHeap;
        
        for(int i: nums) {
            minHeap.push(i);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        for(int i = 0; i < k; i++) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
int main() {
    Solution sally;
    cout << sally.findKthLargest({3, 2, 1, 5, 6, 4}, 2);
    priority_queue<int> q;
    q.push(2);
    q.push(1);
    q.push(4);
    q.push(3);
    // cout << q.top();
    return 0;
}