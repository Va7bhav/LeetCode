#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.insert(flowerbed.end(), 0);

        for (int i = 1; i < flowerbed.size() - 2; i++) {
            if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
                flowerbed[i] = 1;
                n -= 1;
            }
        }
        return n <= 0;
    }
};

int main() {
    
    return 0;
}