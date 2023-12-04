#include<iostream>
#include<vector>
using namespace std;

class Solution {
    void merge(int left, int right, vector<int>& arr) {
    int mid = (left + right) / 2;

    // forming the arrays
    vector<int> first(mid - left + 1);
    vector<int> second(right - mid);    

    int arrIndex = left;
    for(int i = 0; i < first.size(); i++) {
        first[i] = arr[arrIndex++];
    }
    for(int j = 0; j < second.size(); j++) {
        second[j] = arr[arrIndex++];
    }

    // merging those arrays
    int i = 0, j = 0; arrIndex = left;
    while(i < first.size() && j < second.size()) {
        if(first[i] < second[j]) { 
            arr[arrIndex++] = first[i++];
        }
        else {
            arr[arrIndex++] = second[j++];
        }
    }
    while(i < first.size()) {
        arr[arrIndex++] = first[i++];
    }
    while(j < second.size()) {
        arr[arrIndex++] = second[j++];
    }
}
    int mergeSort(int left, int right, vector<int> nums) {
        int mid = (left + right) / 2;
        if(right > left) {
            mergeSort(left, mid, nums);
            mergeSort(mid + 1, right, nums);
            merge(left, right, nums);
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }
};

int main() {
    
    return 0;
}