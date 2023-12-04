#include<iostream>
using namespace std;


// not-working
class Solution {
    bool f(int i, int j, int k, string s1, string s2, string s3) {
        if (i == s1.length() && j == s2.length() && k == s3.length()) {
            return true;
        }
        if (s1[i] == s3[k]) {
            return f(i + 1, j, k + 1, s1, s2, s3);
        }
        else if (s2[j] == s3[k]) {
            return f(i, j + 1, k + 1, s1, s2, s3);
        }
        else if (s1[i] == s2[j] == s3[k]){
            return f(i + 1, j, k + 1, s1, s2, s3) || f(i, j + 1, k + 1, s1, s2, s3);
        }
        else {
            return false;
        }
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        return f(0, 0, 0, s1, s2, s3);
    }
};


int main() {
    

    return 0;
}