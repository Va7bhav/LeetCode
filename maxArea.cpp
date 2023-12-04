#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size();
        int max_area = (right-left) * min(height[left], height[right]);

        while(left < right){
            max_area = max(max_area, ((right-left) * min(height[left], height[right])));
            if(height[left] <= height[right]) left++;
            else if(height[left] > height[right]) right--;
        }
        return max_area;
    }
};

int main() {

    Solution sally;
    vector<int> vec {1,8,6,2,5,4,8,3,7};
    cout<<sally.maxArea(vec);
    return 0;
}