#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> countT, window;
        for(auto i : t) {
            countT[i]++;
        }
        int have = 0, need = countT.size();
        string res; int resLen = INT_MAX;
        int l = 0;
        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            if(countT.find(c) != countT.end()) {
                if(window[c] == countT[c]) {
                    have++;
                }
            }
            while(have == need) {
                if(r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    res = s.substr(l, resLen);
                }
                window[s[l]] -= 1;
                if(countT.find(s[l]) != countT.end()) {
                    if(window[s[l]] < countT[s[l]]) {
                        have--;
                    }
                }
                l++;
            }
        }
        return res;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> countT, countS;
        for (char c : t) {
            countT[c] += 1;
        }
        int have = 0, need = t.length();
        string res; int resLen = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            countS[s[r]] += 1;
            if (countT.find(s[r]) != countT.end()) {
                if (countT[s[r]] == countS[s[r]]) {
                    have += 1;
                }
            }
            while (have == need) {
                if ((r - l + 1) < resLen) {
                    res = s.substr(l, r - l + 1);
                    resLen = (r - l + 1);
                }
                countS[s[l]] -= 1;
                if (countT.find(s[l]) != countT.end() && countS[s[l]] < countT[s[l]]) {
                    have -= 1;
                }
                l += 1;
            }
        }
        return res;
    }
};
int main() {
    
    return 0;
}