#include <vector>
#include <string>

class Solution {
public:
    void getPath(int open, int close, int n, const string &output, vector<string> &ans) {
        if (open > n || close > n || open < close) {
            return;
        }
        if (output.size() == 2 * n) {
            ans.push_back(output);
            return;
        }
        getPath(open + 1, close, n, output + '(', ans);
        getPath(open, close + 1, n, output + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        getPath(0, 0, n, output, ans);
        return ans;
    }
};
