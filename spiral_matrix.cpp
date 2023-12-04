#include<iostream>
#include<vector>
using namespace std;
    class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0;
        int right = matrix.size();
        int top = 0;
        int bottom = matrix[0].size();
        while(left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i < bottom; i++) {
                ans.push_back(matrix[i][right-1]);
            }
            right--;
            if  (!(left < right && top < bottom)) {
                break;
            }
            for (int i = right-1; i > left-1; i--) {
                ans.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for (int i = bottom-1; i > top-1; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
int main() {
    Solution sally;
    vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = sally.spiralOrder(matrix);

    return 0;
}