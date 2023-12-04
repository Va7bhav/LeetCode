#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int>st;
        
        for(int i = nums2.size()-1; i >= 0; i--)
        {
            while(!st.empty() && nums2[i] > st.top())
            {
                st.pop();
            }
            if(st.empty())
                mp[nums2[i]] = -1;
            else
            mp[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        vector<int> result;
        
        for(int i = 0; i < nums1.size(); i++)
        {
            int x = mp[nums1[i]];
            result.push_back(x);
        }
        
        return result;
    }
};


// my code
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> ngeOf;
        stack<int> tube;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];
            while(!tube.empty() && curr > tube.top()) {
                tube.pop();
            }
            int nge;
            if(tube.empty()) nge = -1;
            else nge = tube.top();
            ngeOf[curr] = nge;
            tube.push(curr);
        }
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++) {
            res.push_back(ngeOf[nums1[i]]);
        }
        return res;
    }
};
int main() {
    
    return 0;
}