#include<iostream>
using namespace std;

class Solution {
    bool f(int i, int j, string s, string p) {
        // base cases
        if(i < 0 && j < 0) return true;
        // possibilities over index
        if(s[i] == p[j] || p[j] == '.') {
            return f(i - 1, j - 1, s, p);
        }
        else if(p[j] == '*') {
            if(i == j - 1) return f(i - 1, j - 2, s, p);
            if(!f(i, j - 1, s, p)) return false;
            else return f(i - 1, j, s, p);
        }
        else return false;
    }
public:
    bool isMatch(string s, string p) {
        return f(s.size() - 1, p.size() - 1, s, p);
    }
};

int main() {
    
    return 0;
}