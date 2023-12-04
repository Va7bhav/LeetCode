#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) return {};
        vector<int> pCount(26, 0), sCount(26, 0);
        for (int i = 0; i < p.length(); i++) {
            pCount[p[i] - 'a'] += 1;
            sCount[s[i] - 'a'] += 1;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (pCount[p[i] - 'a'] == sCount[s[i] - 'a']) {
                matches += 1;
            }
        }
        vector<int> res;
        int l = 0;
        for (int r = p.length(); r < s.length(); r++) {
            int index = s[r] - 'a';
            if (matches == 26) res.push_back(l);
            sCount[index] += 1;
            if (pCount[index] == sCount[index]) {
                matches += 1;
            }
            
            // the count previously equal and now adding the same character made it bigger, so matches decrease
            // take ex - ab, dbbaac
            else if (sCount[index] - 1 == pCount[index]) {
                matches -= 1;
            }
            index = s[l] - 'a';
            sCount[index] -= 1;
            if (pCount[index] == sCount[index]) {
                matches += 1;
            }
            else if (sCount[index] + 1 == pCount[index]) {
                matches -= 1;
            }
            l += 1;
        }
        return res;
    }
};


int main() {
    
    return 0;
}