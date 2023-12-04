#include<iostream>
#include<vector>
#include<algorithm>	// max_element
#include <numeric>  // accumulate
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> wealth;
    
    for(auto customer : accounts){
        
		// Function that adds all the elements of a vector.
		// Here it will add all the wealth of a particular customer.
        int TotalWealth = accumulate(customer.begin(),customer.end(),0);
        
        wealth.push_back(TotalWealth);
    }
    // Richest customer wealth is :
    int Richest = *max_element(wealth.begin(),wealth.end());
    
    return Richest;
    }
};
    
 	
    

int main(){
	Solution sally;
	return 0;
}