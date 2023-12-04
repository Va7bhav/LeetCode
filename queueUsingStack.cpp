#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
    stack<int> input;
    stack<int> output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        this->input.push(x);
    }
    
    int pop() {
        if(!this->output.empty()) {
            return this->output.top();
        }
        else {
            while(!this->input.empty()) {
                this->output.push(this->input.top());
                this->input.pop();
            }
            this->output.pop();
        }
    }
    
    int peek() {
        if(!output.empty()) {
            return output.top();
        }
        else {
            while(!this->input.empty()) {
                this->output.push(this->input.top());
                this->input.pop();
            }
            this->output.pop();
        }
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
        return false;
    }
};

int main() {
    
    return 0;
}