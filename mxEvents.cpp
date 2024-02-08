#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int acc(vector<int> arr) {return accumulate(arr.begin(), arr.end(), 0);}
int MOD = 1e9 + 7;

bool comp(struct Event e1, struct Event e2) {
    if (e1.st == e2.st) {
        return e1.end < e2.end;
    }
    return e1.st < e2.st;

}
struct Event {
    int st;
    int end;
    int pos;
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        struct Event e[10];
        for(int i = 0; i < n; i++) {
            e[i].st = events[i][0];
            e[i].end = events[i][1];
            e[i].pos = i + 1;
        }
        sort(events.begin(), events.end(), comp);
        int d = 1;
        int res = 0;
        for (int i = 0; i < events.size(); i++) {
            if (d < events[i][0]) {
                d = events[i][0];
            }
            if (d <= events[i][1]) {
                res += 1;
            }
        }

        return res;
    }
    // 1,5   4,7   9,11
};

int main() {
    
    return 0;
}