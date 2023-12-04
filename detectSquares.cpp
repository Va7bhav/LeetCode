#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class DetectSquares {
    map<pair<int, int>, int> ptsCount;
    vector<pair<int, int>> pts;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        ptsCount[{x, y}] += 1;
        pts.push_back({x, y});
    }
    
    int count(vector<int> point) {
        int px = point[0], py = point[1];
        int count = 0;
        for (auto it: pts) {
            int x = it.first;
            int y = it.second;
            if (abs(x - px) != abs(y - py) && (x == px || y == py)) continue;
            if (ptsCount[{x, py}] > 0 && ptsCount[{px, y}] > 0) {
                count += ptsCount[{x, py}] * ptsCount[{px, y}];
            }
        }
        return count;
    }
};

int main() {
    vector<int> arr;
    return 0;
}