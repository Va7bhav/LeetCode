#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            int rowSize = i + 1;
            res[i].resize(rowSize);
            // putting first and last element zero
            res[i][0] = 1;
            res[i][rowSize - 1] = 1;
            
            for (int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        
    }
};

int main(){
      
    return 0;
}