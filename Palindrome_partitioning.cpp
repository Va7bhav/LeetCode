#include<iostream>
#include<vector>

using namespace std;
class Solution {
    private:
        bool isPalindrome(string s, int i, int j) {
            while(i <= j) {
                if(s[i++] != s[j--]) return false;
            }
            return true;
        }
        
        void backtrack(string s, vector<vector<string>>& res, vector<string> stack, int i) {
            if(i == s.size()) {
                res.push_back(stack);
                return;
            }   
            for(int j = i; j < s.size(); ++j) {
                if(isPalindrome(s, i, j)) {
                    stack.push_back(s.substr(i, j - i + 1));
                    backtrack(s, res, stack, i + 1);
                    stack.pop_back();
                }
            }
        }
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> stack;
            backtrack(s, res, stack, 0);
            return res;
        }
};


class Solution {
    bool isPalindrome(string s, int i, int j) {
            while(i <= j) {
                if(s[i++] != s[j--]) return false;
            }
            return true;
        }

    void(f(string s, vector<vector<string>>& res, vector<string> stack, int slash)) {
        if(slash == s.size()) {
            res.push_back(stack);
            return;
        }
        for(int j = slash + 1; j <= s.size(); j++) {
            string substr = s.substr(slash, j);
            if(isPalindrome(substr, slash, j)) {
                stack.push_back(substr);
                f(s, res, stack, j + 1);

            }
        }
    }
    public:
        vector<vector<string>> partition(string s) {
            vector<vector<string>> res;
            vector<string> stack;
            f(s, res, stack, 0);
            return res;
        }
};
int main() {
    
    return 0;
}