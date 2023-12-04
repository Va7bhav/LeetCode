#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        int l = 0, r = 0;
        while (r < nums.size()) {
            dq.push_back(r);
            // data structure is decreasing or equal
            while (!dq.empty() && nums[r] > dq.back()) {
                dq.pop_back();
            }
            // pop from the queue if out of bounds
            if (l > dq.front()) {
                dq.pop_front();
            }
            // update our result if length of the window is equal to k
            if (r - l + 1 == k) {
                res.push_back(nums[dq.front()]);
                l += 1;
            }
            r += 1;
        }
        return res;
    }
};

int main()
{

    return 0;
}
