#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
    public:
    int val;
    int row;
    int col;
    
    Node(int val, int row, int col) {
        val = val;
        row = row;
        col = col;
    }
};
class Compare {
    public: 
    bool operator()(Node* a, Node* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        int MAX = -1e9;
        for (int i = 0; i < nums.size(); i++) {
            MAX = max(MAX, nums[i][0]);
            pq.push(new Node(nums[i][0], i, 0));
        }

        vector<int> range(2);
        range[0] = pq.top()->val;
        range[1] = MAX;

        while (!pq.empty()) {
            Node* apex = pq.top();
            pq.pop();
            int MIN = apex->val;
            int row = apex->row;
            int col = apex->col;

            MAX = max(MAX, nums[row][col + 1]);

            if (MAX - MIN < range[1] - range[0]) {
                range[0] = MIN;
                range[1] = MAX;
            }
            if (col + 1 <= nums[row].size()) {
                pq.push(new Node(nums[row][col + 1], row, col + 1));
            } else {
                break;
            }
        }
        return range;
    }
};

int main() {
    
    return 0;
}