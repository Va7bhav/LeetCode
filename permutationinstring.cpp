#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        vector<int> count1(26, 0), count2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a'] += 1;
            count2[s2[i] - 'a'] += 1;
        }
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[s1[i] - 'a'] == count2[s2[i] - 'a']) {
                matches += 1;
            }
        }
        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) return true;

            int index = s2[r] - 'a';
            count2[index] += 1;
            if (count1[index] == count2[index]) {
                matches += 1;
            }
            else if (count2[index] - 1 == count1[index]) {
                matches -= 1;
            }
            // the count previously equal and now adding the same character made it bigger, so matches decrease
            // take ex - ab, dbbaac
            int index = s2[l] - 'a';
            count2[index] -= 1;
            if (count1[index] == count2[index]) {
                matches += 1;
            }
            else if (count2[index] + 1 == count1[index]) {
                matches -= 1;
            }
            l += 1;
        }
        return matches == 26;
    }
};


int main() {
    char c = 'a';
    int b = c - 'a';
    cout << b;    
    return 0;
}