#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<pair<int, int>, int>> q;
        // {{r, c}, t}
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int fresh = 0;
        vector<vector<int>> vis(ROWS, vector<int> (COLS, 0));

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 2) {
                    q.push({{r, c}, 0});
                    vis[r][c] = 2;
                }
                if(grid[r][c] == 1) {
                    fresh += 1;
                }
            }
        }
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};
        int time = 0;

        while(!q.empty()) {
            int r = q.front().first.first;   
            int c = q.front().first.second;   
            int t = q.front().second;
            int time = max(time, t);
            q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[r][c] == 1 && vis[r][c] != 2) {
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                    fresh -= 1;
                }
            }
        }
        if(fresh != 0) return -1;
        return time;
    }
};

int main() {
    
    return 0;
}