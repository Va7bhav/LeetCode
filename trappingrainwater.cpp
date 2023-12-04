#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int lmax = 0, rmax = 0;
        int res = 0;
        while (l < r) {
            if (lmax <= rmax) {
                l += 1;
                lmax = max(lmax, heights[l]);
                if (lmax - heights[l] != 0)
                    res += lmax - heights[l];
            }
            else {
                r -= 1;
                rmax = max(rmax, heights[r]);
                if (rmax - heights[r] != 0)
                    res += rmax - heights[r];
            }
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int lmax = heights[0], rmax = heights[heights.size() - 1];
        int res = 0;
        while (l < r) {
            if (lmax <= rmax) {
                l += 1;
                lmax = max(lmax, heights[l]);
                cout << "lmax:" << lmax << endl;
                if (lmax - heights[l] != 0)
                    res += lmax - heights[l];
            }
            else {
                r -= 1;
                rmax = max(rmax, heights[r]);
                cout << "rmax:" << rmax << endl;                
                if (rmax - heights[r] != 0)
                    res += rmax - heights[r];
            }
        }
        return res;
    }
};

int main() {
    
    return 0;
}