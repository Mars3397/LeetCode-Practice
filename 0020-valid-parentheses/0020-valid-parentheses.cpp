/*
Approach
1. use a stack to store the left parentheses for validation
2. pop the stack top when encountering right parentheses to validate
3. return false when invalid
4. stack must be empty when finish checking all the characters

Analysis
1. time: O(n) where n = s.size()
2. space: O(n) where n = s.size()
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n = s.size();

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                // avoid use top when stack is empty
                if (stk.empty()) return false;

                // validate
                if (c == ')' && stk.top() != '(') return false;
                if (c == ']' && stk.top() != '[') return false;
                if (c == '}' && stk.top() != '{') return false;

                stk.pop();
            }
        }

        return stk.empty();
    }
};