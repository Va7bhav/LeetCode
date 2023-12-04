#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class MedianFinder2 {
    map<int, int> hash;
    int size;
public:
    MedianFinder2() {   
        this->size = 0;
    }
    
    void addNum(int num) {
        this->hash[num] = num;
        this->size += 1;
    }
    
    double findMedian() {
        double median;
        int i = 0;
        if(this->size % 2 == 1) { 
            for(auto element: hash) { 
                if(i == this->size / 2) {
                    median = element.second;
                    break;
                } 
                else i++;    
            }
        }
        else {
            double midElement1, midElement2;
            for(auto element: hash) {
                if(i == (this->size / 2) - 1) {
                    midElement1 = element.second;
                }
                if(i == (this->size / 2)) {
                    midElement2 = element.second;
                    break;
                }
                i++;
            }
            cout << midElement1 << " " << midElement2 << endl;
            median = (midElement1 + midElement2) / 2;
        }
        return median;
    }
};

class MedianFinder {
    priority_queue<int, vector<int>> small;
    priority_queue<int, vector<int>, greater<int>> large;
public:
    MedianFinder() {
            
    }
    
    void addNum(int num) {
        small.push(num);
        // make sure every small is <= every value in large
        if(!small.empty() && !large.empty() && small.top() > large.top()) {
            int temp = small.top();
            small.pop();
            large.push(temp);
        }
        if(small.size() > large.size() + 1) {
            int temp = small.top();
            small.pop();
            large.push(temp);
        }
        if(large.size() > small.size() + 1) {
            int temp = large.top();
            large.pop();
            small.push(temp);
        }

    }
    
    double findMedian() {
        if(small.size() > large.size()) {
            return small.top();
        }
        if(large.size() > small.size()) {
            return large.top();
        }
        else {
            return ((small.top() + large.top()) / 2.0);
        }
    }
};


int main() { 
    MedianFinder* obj = new MedianFinder();
    obj->addNum(3);
    obj->addNum(2);
    double param_2 = obj->findMedian();
    cout << param_2;
    return 0;
}