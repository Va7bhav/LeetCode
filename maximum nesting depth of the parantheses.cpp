#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

class Solution
{
public:
    int maxDepth(string s)
    {
        int n = s.length();
        int depth = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            if (s[i] == ')')
            {
                if (depth < st.size())
                {
                    depth = st.size();
                }
                st.pop();
            }
        }
        return depth;
    }
};
int main()
{

    return 0;
}