#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int acc(vector<int> arr) {return accumulate(arr.begin(), arr.end(), 0);}
int MOD = 1e9 + 7;

class Solution {
    string s;
    int sLen = s.length();
    int minJump, maxJump;

    bool f(int left, int right) {


        for (int i = left; i <= right; i++) {
            if (s[i] == '0') {
                int what = min(i + maxJump, sLen - 1);
                right = max(right, what);
                if (right == s.length() - 1) {
                    return true;
                }
            }
        }
        left = left + minJump;
        if (f(left, right)) return true;
        else return false;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        this->s = s;
        this->minJump = minJump;
        this->maxJump = maxJump;
        return f(0, 0);   
    }
};

int main() {
    
    return 0;
}