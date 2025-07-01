/*
Approach
1. we can use a stack + a vector to achieve min stack
2. stack is used to maintain the order of push while vector[i] = the minimal value of stack with size i

*/


class MinStack {
private:
    stack<int> stk;
    vector<int> mins;

public:
    MinStack() {}
    
    void push(int val) {
        // push to stack
        stk.push(val);

        // push mins to vector
        if (mins.size() == 0) {
            mins.push_back(val);
        } else {
            int curMin = mins[mins.size()-1];
            if (curMin < val) mins.push_back(curMin);
            else mins.push_back(val);
        }
    }
    
    void pop() {
        stk.pop();
        mins.pop_back();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mins[mins.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */