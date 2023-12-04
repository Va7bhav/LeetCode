// doubt comes in head : rowZero is only true or false for the row 0, the [1][0], [2][0] .... does'nt trigger it

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false;
        for(int r = 0; r < matrix.size(); r++) {
            for(int c = 0; c < matrix[0].size(); c++) {
                if(r > 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
                else if(r == 0) {
                    rowZero = true;
                    matrix[0][c] = 0;
                }
            }
        }
        // first
        // travel row 0, put columns to zero
        for(int c = 0; c < matrix[0].size(); c++) {
            if(matrix[0][c] == 0) {
                for(int r = 0; r < matrix.size(); r++) {
                    matrix[r][c] = 0;
                }
            }
        }
        //second
        // check rowZero
        if(rowZero) for(int c = 0; c < matrix[0].size(); c++) {
            matrix[0][c] = 0;
        }

        // third
        // traveling [1][0] [2][0]
        for(int r = 1; r < matrix.size(); r++) {
            if(matrix[r][0] == 0) {
                for(int c = 0; c < matrix[0].size(); c++) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
int main() {
    
    return 0;
}