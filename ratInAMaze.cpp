#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void backTrack( int r, int c, vector<vector<int>>& m, int n, int ROWS, int COLS, string stack, vector<string> res, vector<vector<int>> vis) {
        if(r == n - 1 && c == n - 1) {
            res.push_back(stack);
            return;
        }
        
        if(c - 1 > 0 && vis[r][c] != 1 && m[r][c - 1] == 1) {
            vis[r][c] = 1;
            stack.push_back('L');
            backTrack(r, c - 1, m, n, ROWS, COLS, stack, res, vis);
            stack.pop_back();
            vis[r][c] = 0;
        }

        if(c + 1 < n && vis[r][c] != 1 && m[r][c + 1] == 1) {
            vis[r][c] = 1;
            stack.push_back('L');
            backTrack(r, c + 1, m, n, ROWS, COLS, stack, res, vis);
            stack.pop_back();
            vis[r][c] = 0;
        }

        if(r - 1 >= 0 && vis[r][c] != 1 && m[r - 1][c] == 1) {
            vis[r][c] = 1;
            stack.push_back('L');
            backTrack(r - 1, c, m, n, ROWS, COLS, stack, res, vis);
            stack.pop_back();
            vis[r][c] = 0;
        }
        
        if(r + 1 < n && vis[r][c] != 1 && m[r + 1][c] == 1) {
            vis[r][c] = 1;
            stack.push_back('L');
            backTrack(r + 1, c, m, n, ROWS, COLS, stack, res, vis);
            stack.pop_back();
            vis[r][c] = 0;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        int ROWS = m.size();
        int COLS = m[0].size();
        vector<string> res;
        string stack;
        vector<vector<int>> vis(n ,vector<int> (n, 0));
        backTrack(0, 0, m, n, ROWS, COLS, stack, res, vis);
        return res;
    }
};

class Solution {
    void backTrack(int r, int c, vector<vector<int>>& m, int n, int ROWS, int COLS, string stack, vector<string> res, vector<vector<int>> vis) {
        if(r == n - 1 && c == n - 1) {
            res.push_back(stack);
            return;
        }
        
        vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        string dir = "RLUD";
        int i = 0;
        for(auto direc : directions) {
            int nr = r + direc[0];
            int nc = c + direc[1];
            if(nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc] && m[nr][nc] == 1) {
                vis[nr][nc] = 1;
                backTrack(nr, nc, m, n, ROWS, COLS, stack + dir[i], res, vis);
                vis[nr][nc] = 1;
            }
            i++;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        int ROWS = m.size();
        int COLS = m[0].size();
        vector<string> res;
        string stack;
        vector<vector<int>> vis(n ,vector<int> (n, 0));
        backTrack(0, 0, m, n, ROWS, COLS, stack, res, vis);
        return res;
    }
};
int main() {
    
    return 0;
}