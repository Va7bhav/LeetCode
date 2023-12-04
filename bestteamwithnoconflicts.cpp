#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    bool age(int age1, int age2) {
        return age1 < age2;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        sort(scores.begin(), scores.end(), age);
        return 0;
    }
};

int main() {
    Solution sally;
    vector<int> scores {4, 5, 6, 5};
    vector<int> ages {2, 1, 2, 1};
    sally.bestTeamScore(scores, ages);

    for (auto i: scores) {
        cout << i;
    }

    return 0;
}