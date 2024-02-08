#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9 + 7;

class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		queue<int> q;
		
		for (int i = 1; i <= 9; i++) q.push(i);
		vector<int> res;
		while (!q.empty()) {
			int n = q.front();
			if (n > high) {
				break;
			}
			if (low <= n && n <= high) {
				res.push_back(n);
			}
			int ones = n % 10;

			if (ones <= 9) {
				q.push(n * 10 + (ones + 1));
			}
		}
	return res;
	}
};

int main()
{

	return 0;
}