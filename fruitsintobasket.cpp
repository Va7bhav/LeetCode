#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0, total = 0, l = 0;
        map<int, int> count;

        for (int r = 0; r < fruits.size(); r++) {
            count[fruits[r]] += 1;
            total += 1;

            while (count.size() > 2) {
                int f = fruits[l];
                count[f] -= 1; 
                total -= 1;
                l += 1;
                if (!count[f])
                    count.erase(f);
            }
            res = max(res, total);
        }
        return total;
    }
};

int main() {
    map<int, int> count;
    cout << count.size();
    count[1] = 1;
    cout << count.size();
    count.erase(1);
    cout << count.size();
    return 0;
}