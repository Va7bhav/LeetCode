#include<iostream>
#include<algorithm>
using namespace std;

// struct meeting {
//     int startTime;
//     int endTime;
//     int pos;
// };

// bool sortByEndTime(struct meeting m1, struct meeting m2) {
//     if(m1.endTime < m2.endTime) return true;
//     else if(m1.endTime > m2.endTime) return false;
//     else if(m1.endTime == m2.endTime) 
//         if(m1.pos < m2.pos) return true;
//     return false;
// }
// class Solution {
//     public:
//     int maxMeetings(int start[], int end[], int n) {
//         struct meeting meet[n];

//         for(int i = 0; i < n; i++) {
//             meet[i].startTime = start[i];
//             meet[i].endTime = end[i];
//             meet[i].pos = i + 1;
//         }
//         sort(meet, meet + n, sortByEndTime);
//         int currTime = 0;
//         int countMeet = 0;
//         for(int i = 0; i < n; i++) {
//             if(currTime < meet[i].startTime) {
//                 countMeet += 1;
//                 currTime = meet[i].endTime;
//             }
//         }
//         return countMeet;
//     }
// };

// my code
bool sortByEndTime(struct meeting m1, struct meeting m2){
    if(m1.endTime < m2.endTime) return true;
    if(m1.endTime > m2.endTime) return false;
    if(m1.endTime == m2.endTime) 
        if(m1.pos < m2.pos) return true;
    return false;       
}
struct meeting {
    int pos;
    int startTime;
    int endTime;
};
class Solution {
    public:
    int maxMeetings(int start[], int end[], int n) {
    struct meeting meet[9];
    for(int i = 0; i < n; i++) {
        meet[i].pos = i;
        meet[i].startTime = start[i];
        meet[i].endTime = end[i];
    }
    sort(meet, meet + n, sortByEndTime);
    int res = 0;
    int prev_startTime = 0;
    int prev_endTime = 0;
    for(auto meeting : meet) {
       if(meeting.startTime > prev_endTime) res++;
       prev_endTime = meeting.endTime;
    }
    return res;
};


int main() {
    Solution sally;
    int start[] = {1, 0 ,3, 8, 5, 8};
    int end[] = {2, 6, 4, 9, 7, 9};

    // {10, 12, 20}
    // {20, 25, 30}
    cout << sally.maxMeetings(start, end, 6);
    return 0;
}