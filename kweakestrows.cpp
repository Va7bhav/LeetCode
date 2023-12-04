#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, int> hash;
        vector<int> temp(mat[0].size());

        for (int m = 0; m < mat[0].size(); m++) {
            int n = 0;
            while(mat[m][n] == 1) {
                hash[mat[m][n]]++;
                n++;
            }
            temp[m] = hash[1];
            hash[1] = 0;
        }

        vector<int> vecOfArray[5];
        for (int i = 0; i < mat[0].size(); i++) {
            vecOfArray[temp[i]].push_back(i);
        }

        vector<int> res;
        for (int i = 0; i < mat[0].size(); i++) {
            for(int ele : vecOfArray[i]) {
                res.push_back(ele);
            }
            if(res.size() == k) break;
        }
        return res;
    }
};
int main(){

    Solution sally;
    vector<vector<int>> mat{{1,1,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,0,0,0}, {1,1,1,1,1}};
    vector<int> ans = sally.kWeakestRows(mat, 3);
    cout<<ans[0]<<endl;
    cout<<ans[1]<<endl;
    cout<<ans[2]<<endl;
    return 0;
}