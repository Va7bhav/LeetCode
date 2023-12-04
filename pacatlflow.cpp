#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
    void dfs(int r, int c, int prevHeight, set<pair<int, int>>& visit, vector<vector<int>>& heights) {
        if (visit.find({r, c}) != visit.end()
            || r < 0 || c < 0 || r == heights.size() || c == heights[0].size()
            || heights[r][c] < prevHeight) 
                return;
        visit.insert({r, c});
        dfs(r + 1, c, heights[r][c], visit, heights);
        dfs(r, c + 1, heights[r][c], visit, heights);
        dfs(r - 1, c, heights[r][c], visit, heights);
        dfs(r, c - 1, heights[r][c], visit, heights);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        set<pair<int, int>> atl, pac;

        for (int c = 0; c < COLS; c++) {
            dfs(0, c, heights[0][c], pac, heights);
            dfs(ROWS - 1, c, heights[ROWS - 1][c], atl, heights);
        }
        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, heights[r][0], pac, heights);
            dfs(r, COLS - 1, heights[r][COLS - 1], atl, heights);
        }
        vector<vector<int>> res;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (atl.find({r, c}) != atl.end() && pac.find({r, c}) != pac.end()) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }
};
int main() {
    
    return 0;
}