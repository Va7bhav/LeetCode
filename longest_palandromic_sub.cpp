#include<iostream>
using namespace std;
class Solution {
public:
    
    string longestPalindrome(string s) {
        string ans = "";
        int ansLen = 1;
        
        for(int i = 0; i < s.length(); i++) {
            int l = i, r = i;
            while(l >= 0 && r < s.length() && s[l] == s[r]) {
                if(r - l + 1 > ansLen){
                    ansLen = max(ansLen, r - l + 1);
                    ans = s.substr(l, r + 1); 
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while (l>=0 && r<s.length() && s[l] == s[r]) {
                if (l - r + 1 > ansLen) {
                    ansLen = max(ansLen, r - l + 1);
                    ans = s.substr(l, r + 1);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};
int main() {
    
    return 0;
}