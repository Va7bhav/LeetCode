#include<iostream>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int result = 0; 
        
        for(char c : columnTitle) {
            
            int d = c - 'A' + 1;
            
            result = result * 26 + d;
            cout<<"result : "<<result;
        }
        return result;
    }
};
int main() {
    Solution sally;
    sally.titleToNumber("AB");
    return 0;
}