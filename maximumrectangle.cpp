#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    int largestRectangleArea(vector<int>&heights) {
        heights.push_back(0);
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                // index mil rhi hai, index ko pop karna hai, previous smaller index mil gyi ab top mein area calculate karna hai
                int h = heights[st.top()];
                st.pop();
                if (st.empty()) maxArea = max(maxArea, h * i);
                else {
                    int l = i - st.top() - 1;
                    maxArea = max(maxArea, h * l);
                }
            }
            st.push(i);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        int maxRect = 0;
        vector<int> heights(COLS);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (matrix[r][c] == '1') heights[c] += 1;
                else heights[c] = 0;
            }
            maxRect = max(maxRect, largestRectangleArea(heights));
        }
        return maxRect;
    }
};
int main() {
    
    return 0;
}