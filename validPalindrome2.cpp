#include<iostream>
using namespace std;

class Solution {
public: 
    bool validPalindrome(string s) {
        int Len = s.length();
        int l = 0, r = Len - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                string str1 = s.substr(l + 1, r - l);
                string revStr1 = str1; reverse(revStr1.begin(), revStr1.end());

                string str2 = s.substr(l, r - l);
                string revStr2 = str2; reverse(revStr2.begin(), revStr2.end());

                return (str1 == revStr1) || (str2 == revStr2);
            }
            else if (s[l] == s[r]) {
                l += 1, r += 1;
            }
        }
        return false;
    }
};
int main() {
    // reverse(str1.begin(), str1.end())
    return 0;
}