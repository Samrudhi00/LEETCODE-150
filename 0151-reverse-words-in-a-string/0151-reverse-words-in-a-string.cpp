class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return s;
        }            

        stack<string> stk;
        string output;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                continue;
            }

            string word;
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            stk.push(word);
        }

        while (!stk.empty()) {
            output += stk.top();
            stk.pop();
            if (!stk.empty()) {
                output += " ";
            }
        }

        return output;
    }
};
