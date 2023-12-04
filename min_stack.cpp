#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class MinStack {
public:
    stack<int> tube;
    stack<int> min_tube;
    MinStack() {
    }
    
    void push(int val) {
        tube.push(val);
        if(min_tube.empty() || val <= getMin()) {
            min_tube.push(val);
        }
    }
    
    void pop() {
        if(tube.top() == getMin())  min_tube.pop();
        tube.pop();
    }
    
    int top() {
        return tube.top();
    }
    
    int getMin() {
        return min_tube.top();
    }
};

int main() {
    
    return 0;
}