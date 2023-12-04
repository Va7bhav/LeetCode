#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> effort(ROWS, vector<int> (COLS, 1e9));
        
        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; 
       
        while(!pq.empty()) {
            int _effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r == ROWS - 1 && c == COLS - 1) return _effort;

            for(auto dir : directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                int currEffort = max(abs(heights[r][c] - heights[nr][nc]), _effort); 
                if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS) {
                    if(currEffort < effort[nr][nc]) {
                        pq.push({currEffort, {nr, nc}});
                        effort[nr][nc] = currEffort;
                    }
                }
            }
        }
        return 0;
    }
};

class Solution {
    public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == m - 1) {
                return dis;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int effort = max(dis, abs(heights[row][col] - heights[nrow][ncol]));
                    if (effort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = effort;
                        pq.push({effort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<vector<int>> maxEffortArray(ROWS, vector<int> (COLS, 1e9));

        vector<vector<int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!pq.empty()) {
            auto apex = pq.top(); pq.pop();
            int pathMaximumEffort = apex.first;
            int r = apex.second.first;
            int c = apex.second.second;
            
            for (vector<int> dir: directions) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS) {
                    int nextEffort = abs(heights[nr][nc] - heights[r][c]);
                    pathMaximumEffort = max(pathMaximumEffort, nextEffort);
                    if (pathMaximumEffort < maxEffortArray[nr][nc]) {
                        maxEffortArray[nr][nc] = pathMaximumEffort;
                        pq.push({pathMaximumEffort, {nr, nc}});
                    }
                }
            }
        }
        return maxEffortArray[ROWS - 1][COLS - 1];
    }
};
int main() {

    return 0;
}