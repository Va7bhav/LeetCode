#include<iostream>
#include<vector>
using namespace std;
class Solution {
    private:
        void backtrack(int open, int close, int n, vector<string>& res, string& stack) {
            if(open == n && close == n) {
                res.push_back(stack);
                return;
            }
                if(open < n) {
                    stack.push_back('(');
                    backtrack(open + 1, close, n, res, stack);
                    stack.pop_back();
                }
                if (close < open) {
                    stack.push_back(')');
                    backtrack(open, close + 1, n, res, stack);
                    stack.pop_back();
                }
        }
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> res;
            string stack;
            int open = 0, close = 0;
            backtrack(open, close, n, res, stack);
            return res;
        }
};

void f(vector<string> res, string stack, int n, int open, int close) {
    if(stack.size() == 2*n) {
        res.push_back(stack);
        return;
    }
    if(open <= n) {
        stack.push_back('{');
        open++;
        stack.pop_back();
        open--;
    }
    if(close <= open) {
        stack.push_back('}');
        close++;
        stack.pop_back();
        close--;
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    string stack;
    f(res, stack, n, 0, 0);
    return res;
}
int main() {
    
    return 0;
}