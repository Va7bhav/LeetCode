#include<iostream>
#include<vector>
using namespace std;

int f(int n, int last_index, vector<vector<int>>& points) {
    if(n == -1) {
        return 0;
    }
    int max_score = 0;
    for(int i = 0; i < points[0].size(); i++) {
        if(i != last_index) {
            int score = points[n][i] + f(n - 1, i, points);
            max_score = max(max_score, score);
        }
    }       
    return max_score;
}
int ninjaTraining(vector<vector<int>>& points) {
    int n = points.size() - 1;
    int max_score = 0;
    for(int i = 0; i < points[0].size(); i++) {
        max_score = max(max_score, f(n, i, points));
    }
    return max_score;
}
    

int main() {
    // vector<vector<int>> points {{10, 50, 1}, {5, 100, 11}};
    vector<vector<int>> points {{10, 50, 1}, {5, 100, 11}};
    cout << ninjaTraining(points);
    return 0;
}