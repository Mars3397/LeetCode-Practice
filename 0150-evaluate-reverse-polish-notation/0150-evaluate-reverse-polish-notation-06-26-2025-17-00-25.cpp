/*
Approach
1. use a stack to store numbers 
2. iterate through tokens, push numbers to stack
3. pop 2 numbers from stack when encounter ops and push result back to stack

Analysis
1. time: O(n) where n = tokens.size()
2. space: O(n) where n = tokens.size()
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                
                if (token == "+") stk.push(num1 + num2);
                else if (token == "-") stk.push(num1 - num2);
                else if (token == "*") stk.push(num1 * num2);
                else stk.push(num1 / num2);
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};