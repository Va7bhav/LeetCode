#include<iostream>
#include<vector>
using namespace std;

class Solution {
    bool isValid(bool graph[101][101], int node, int col, int N, vector<int> color) {
        for(int k = 0; k < N; k++) {
            if(k != node && graph[node][k] == 1 && color[k] == col) return false;
        }
        return true;
    }
    bool f(int node, int m, int N, bool graph[101][101], vector<int> color) {
        if(node == N) return true;

        for(int col = 1; col <= m; col++) {
            if(isValid(graph, node, col, N, color)) {
                color[node] = col;
                if(f(node + 1, m, N, graph, color)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    public:
    bool graphColoring(bool graph[101][101], int m, int N) {
        vector<int> color(N);
        return f(0, m, N, graph, color);
    }
};
int main() {
    
    return 0;
}