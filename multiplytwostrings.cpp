#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> res(num1.length() + num2.length());
        for (int i1 = 0; i1 < num1.length(); i1++) {
            for (int i2 = 0; i2 < num2.length(); i2++) {
                int digit = int(num1[i1]) * int(num2[i2]);
                res[i1 + i2] += digit;
                res[i1 + i2 + 1] += digit / 10;
                res[i1 + i2] = digit % 10;
            }
        }
        reverse(res.begin(), res.end());
        int begin = 0;
        while (begin < res.size() && res[begin] == 0) begin += 1;
        string output = "";
        for (int i = begin; i < res.size(); i++) {
            output.push_back(res[i]);
        }
        return output;
    }
};

int main() {

    return 0;
}