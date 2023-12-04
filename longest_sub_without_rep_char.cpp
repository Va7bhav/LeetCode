#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> hash;
        int l = 0, r = 0;
        int max_count = 0;
        while(s[r] != NULL) {
            if(hash[s[r]] != NULL) {
                max_count = max(max_count, l - r + 1);
                l = max(l, hash[s[r]] + 1);
            } 
            hash[s[r]] = r;
            r++;
        }
        return max_count;
    }
};
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int l = 0, r = 0;
        int max_count = 0;
        while (s[r] != NULL) {
            if(/*hash contains s[r]*/ hash[s[r]] != -1) {
// l = max of indexes of just repeated element in the hash, jo 'l' ne visit kiyen hai
// example - "abcaabcdba";            
// jese jab 'a' repeat hua dusri baar toh 'l' ki value uske agle vaale index par ho gayi, par jab 'a' third baar repeat hua toh l ki value max of(index : 2, index : 3 + 1 hogyi)
                l = max(l, hash[s[r]] + 1); 
            }
            hash[s[r]] = r; 
            max_count = max(max_count, r - l + 1);
            r++;
        }
        return max_count;
    }
};
int main() {
    return 0;
}