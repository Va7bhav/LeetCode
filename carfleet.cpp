#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<vector<int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.begin(), pair.end());
        vector<float> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = ((float)target - (float)pair[i][0]) / (float)pair[i][1];
        }
        int res = 0;
        stack<int> st;
        int i = n - 1;
        
        if (st.empty() || time[i] <= st.top()) {
            st.push(time[i]);
        }   
        
        


        return res;
    }
};

int main() {
    Solution sally;
    int target = 10; vector<int> position = {6, 8}, speed = {3, 2};

    cout << sally.carFleet(target, position, speed);
    return 0;
}