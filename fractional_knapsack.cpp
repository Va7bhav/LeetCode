#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int value;
    int weight;
};


class Solution {
    bool sortByProfit(struct Item i1, struct Item i2) {
        double p1 = i1.value / i1.weight;
        double p2 = i2.value / i2.weight;
        return p1 > p2;
    }
    public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, sortByProfit);    
        double maxValue;
        for(int i = 0; i < n; i++) {
            if(W >= arr[i].weight) {
                maxValue += arr[i].value;
                W -= arr[i].weight;      
            }
            else {
                maxValue += (W / arr[i].weight) * arr[i].value;
            }
        }
        return maxValue;
    }
};

int main() {
    
    return 0;
}