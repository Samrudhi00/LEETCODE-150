class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        string result = "";
        stack<int> indices;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                indices.push(i);
            } else if (s[i] == ')') {
                int start = indices.top() + 1;
                int end = i;
                reverse(s.begin() + start, s.begin() + end);
                indices.pop();
            }
        }

        for (char ch : s) {
            if (ch != '(' && ch != ')') {
                result += ch;
            }
        }

        return result;
    }
};
