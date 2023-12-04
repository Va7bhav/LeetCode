


class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int top = -1;

        for (int i = 0; i < s.length(); i++) {
            if(stack.empty()) if(s[i] == ')' || s[i] == ']' || s[i] == '}') return false;
            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                top++;
                stack.push_back(s[i]);
            }
            else{
                char temp;

                if(stack[top] == '(') temp = ')';
                else if(stack[top] == '[')  temp = ']';
                else if(stack[top] == '{')  temp = '}';

                if(temp == s[i]){
                    stack.pop_back();
                    top--;
                }
                else {
                    return false;
                }
            }
        }
        if(stack.empty()) {
            return true;
        }
        return false;
    }
};