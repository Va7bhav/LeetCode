#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<queue>



using namespace std;

class SolutionDFS {
private:
    void dfs(int r, int c, set<string>& path, int& countIsland, vector<vector<char>> grid) {
        int rows = grid.size(), cols = grid[0].size();
        if(r < 0 || c < 0 || r > rows || c > cols || grid[r][c] == '0' || path.find(to_string(r) + to_string(c)) != path.end()) return;
        path.insert(to_string(r) + to_string(c));
       
        dfs(r, c + 1, path, countIsland, grid);
        dfs(r, c - 1, path, countIsland, grid);
        dfs(r + 1, c, path, countIsland, grid);
        dfs(r - 1, c, path, countIsland, grid);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int countIsland = 0;
        
        set<string> path;
        if(grid.empty()) return 0;
        
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {    
                if(grid[r][c] == '1' && path.find(to_string(r) + to_string(c)) == path.end()) {
                    dfs(r, c, path, countIsland, grid);
                    countIsland ++;
                }
            }
        }
        return countIsland;
    }
};
class SolutionBFS {
private:
    void bfs(int r, int c, vector<vector<char>> grid, vector<vector<int>>& visited) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vector<vector<int>> directions {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for(vector<int> direc : directions) {
                int nr = r + direc[0];
                int nc = c + direc[1];
                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == '1' && visited[nr][nc] == 0) {
                        visited[nr][nc] = 1;
                        q.push({nr, nc});
                }
            }
        }
    }
};
int main() {
    
    return 0;
}