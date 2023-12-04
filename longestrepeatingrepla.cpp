#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<int, int> count;
        int l = 0, r = 0;
        int res = INT_MIN;
        for (int r = 0; r < s.length(); r++) {
            count[s[r]] += 1;
            max(count.second);
            res = max(res, r - l + 1);
        }
    }
};
int main() {
    
    return 0;
}