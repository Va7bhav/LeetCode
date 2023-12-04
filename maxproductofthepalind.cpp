#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int maxProduct(string s) {
        int len = s.length();
        map<int, int> hash;
        for (int i = 1; i < (1 << len); i++) { // 1 << len == 2 ** len
            string subseq = "";
            for (int j = 0; j < len; j++) {
                if (((1 << j) & i) == 1) {
                    subseq.push_back(s[j]);
                } 
            }
            string subseq_ = subseq;
            reverse(subseq.begin(), subseq.end()); 
            

            if (subseq_ == subseq) {
                hash[i] = subseq.length();
            }
        }

        int res = 0;
        for (auto iter1: hash) {
            for (auto iter2: hash) {
                if (iter1.first & iter2.first == 0) { // disjoint
                    res = max(res, iter1.second * iter2.second);
                }
            }
        }
        return res;
    }
};

int main() 
{ 
    string str = "Journal Dev reverse example"; 
    reverse(str.begin(), str.end()); 
	cout<<"\n"<<str; 
    return 0;
}