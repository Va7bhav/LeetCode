#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        string ref = strs[0];
        for(int i = 0 ; i < ref.size(); i++){
            int j = 1;
            for( ; j < strs.size(); j++){
                if(ref[i] != strs[j][i]){
                    break;
                }
            }
            if(j == strs.size()){
                ans+=ref[i];    
                continue;
            }
            else{
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution sally;  
    vector<string> strs = {"flower", "flow", "flight"};
    string ans = sally.longestCommonPrefix(strs);
    cout<<ans;
    return 0;
}
