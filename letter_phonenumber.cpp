#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
    private:
        void backtrack(string digits, vector<string>& ans, string digitToChar[], int index) {
            string stack;
            if(stack.length() == digits.length()) {
                ans.push_back(stack);
                return;
            }   

                string str = digitToChar[digits[index] - '0'];

                for (int i = 0; i < digits.length(); i++)
                {
                    stack.push_back(str[i]);
                    backtrack(digits, ans, digitToChar, index+1);   
                    stack.pop_back();
                }       
        }
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            string digitToChar[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            backtrack(digits, ans, digitToChar, 0);
            return ans;
        }
};
int main() {
    Solution sally;
    // cout<<sally.letterCombinations("23");
    return 0;
}