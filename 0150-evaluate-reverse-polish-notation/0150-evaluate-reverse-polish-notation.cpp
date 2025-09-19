/*
Approach
1. use a stack to help us to calculate
2. push number to stack and pop them when encountering operations
3. push the result number back to the stack

Analysis
1. time: O(n) where n = token.size()
2. space: O(n) where n = token.size()
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            if (tokens[i] == "+") {
                int n2 = stk.top(); stk.pop();
                int n1 = stk.top(); stk.pop();
                stk.push(n1 + n2);
            } else if (tokens[i] == "-") {
                int n2 = stk.top(); stk.pop();
                int n1 = stk.top(); stk.pop();
                stk.push(n1 - n2);
            } else if (tokens[i] == "*") {
                int n2 = stk.top(); stk.pop();
                int n1 = stk.top(); stk.pop();
                stk.push(n1 * n2);
            } else if (tokens[i] == "/") {
                int n2 = stk.top(); stk.pop();
                int n1 = stk.top(); stk.pop();
                stk.push(n1 / n2);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }

        return stk.top();
    }
};