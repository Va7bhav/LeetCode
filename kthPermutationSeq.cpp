#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    int factorial(int num) {
        return (num == 1 || num == 0) ? 1: num * factorial(num - 1);
    }
public:
    string getPermutation(int n, int k) {
        k--;
        vector<int> number;
        cout << "hello1";
        for(int i = 0; i < n; i++) {
            number.push_back(i + 1);
        }
        string res = "";
        cout << "hello2";
        while(true) {
            if(number.size() == 0) break;
            int fact = factorial(number.size() - 1);
            res = res + to_string(number[k / fact]);
            cout << res << endl;
            number.erase(number.begin() + k / fact);
            k = k / fact;
        }
        cout << "hello3";
        return res;
    }
};

int main() {
    Solution sally;
    cout << sally.getPermutation(4, 17);
    cout << "hello";
    return 0;
}