#include<iostream>
#include<algorithm>
using namespace std;
struct Time {
    int arrTime;
    int depTime;
};
bool comparator(struct Time t1, struct Time t2) {
    if(t1.depTime < t2.depTime) return true;
    if(t1.depTime > t2.depTime) return false;
    return false;
}
class Solution {
    public:
    int findPlatform(int arr[], int dep[], int n) {
        struct Time t[6];
        for(int i = 0; i < n; i++) {
            t[i].arrTime = arr[i];
            t[i].depTime = dep[i];
        }
    	sort(t, t + 6, comparator);
        int countPlatform = 0;
        int prevDept = 1000000;
        for (int i = 0; i < n; i++) {
            if(t[i].arrTime < prevDept) {
                countPlatform += 1;
                prevDept = t[i].depTime;
            }
        }
        return countPlatform;
    }
};
int main() {
    Solution sally;
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dept[] = {910, 1200, 1120, 1130, 1900, 2000};
    cout << sally.findPlatform(arr, dept, 6);
    return 0;
}