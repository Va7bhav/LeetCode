#include<iostream>
#include<vector>
using namespace std;

// void dfs(int index, int s, vector<int> stack, vector<int> nums, int sum) {
//     if(index >= nums.size()) {
//         if(s == sum) {
//             for (auto i : stack) {
//                 cout<<i<<" ";
//            }
//         cout<<endl;
//     }
//         return;
//     }

//     stack.push_back(nums[index]); 
//     s += nums[index];
    
//     dfs(index + 1, s, stack, nums, sum);
    
//     stack.pop_back();
//     s -= nums[index];
    
//     dfs(index + 1, s, stack, nums, sum);
// }
// void printingSubsequencesWhoseSumIsGiven(vector<int> nums, int sum) {
//     vector<int> stack;
//     dfs(0, 0, stack, nums, sum);
// }


// bool dfs(int index, int s, vector<int> stack, vector<int> nums, int sum) {
//     if(index >= nums.size()) {
//         if(s == sum) {
//             for (auto i : stack) {
//                 cout<<i<<" ";
//            }
//         return true;
//     }
//         return false;
//     }

//     stack.push_back(nums[index]); 
//     s += nums[index];
    
//     if(dfs(index + 1, s, stack, nums, sum)) {
//         return true;
//     }
    
//     stack.pop_back();
//     s -= nums[index];
    
//     if(dfs(index + 1, s, stack, nums, sum)) {
//         return true;
//     }
//     return false;
// }
// void printingOnlyOneSubsequenceofSubsequencesWhoseSumIsGiven(vector<int> nums, int sum) {
//     vector<int> stack;
//     dfs(0, 0, stack, nums, sum);
// }


int dfs(int index, int s, vector<int> nums, int sum) {
    if(index >= nums.size()) {
        if(s == sum) {
            return 1;
        }
        return 0;
    }

    s += nums[index];
    
    int l = dfs(index + 1, s, nums, sum);
    
    s -= nums[index];
    
    int r = dfs(index + 1, s, nums, sum);

    return l + r;
}
int countingSubsequencesWhoseSumIsGiven(vector<int> nums, int sum) {
    return dfs(0, 0, nums, sum);
}


int main() {
    // printingSubsequencesWhoseSumIsGiven({1, 2, 1}, 2);
    // printingOnlyOneSubsequenceofSubsequencesWhoseSumIsGiven({1, 2, 1}, 2);
    // cout << countingSubsequencesWhoseSumIsGiven({1, 2, 1}, 2);
    return 0;
}