class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        unordered_map<string, int> curr_map;
        int i = 0, n = formula.size();

        while (i < n) {
            if (formula[i] == '(') {
                stk.push(curr_map);
                curr_map.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                string cnt_str = "";
                while (i < n && isdigit(formula[i])) {
                    cnt_str += formula[i++];
                }
                int cnt = cnt_str.empty() ? 1 : stoi(cnt_str);

                if (!stk.empty()) {
                    unordered_map<string, int> prev_map = stk.top();
                    stk.pop();
                    for (auto &elem : curr_map) {
                        prev_map[elem.first] += elem.second * cnt;
                    }
                    curr_map = prev_map;
                }
            } else {
                string element = "";
                element += formula[i++];
                if (i < n && islower(formula[i])) {
                    element += formula[i++];
                }

                string cnt_str = "";
                while (i < n && isdigit(formula[i])) {
                    cnt_str += formula[i++];
                }
                int cnt = cnt_str.empty() ? 1 : stoi(cnt_str);
                curr_map[element] += cnt;
            }
        }

        map<string, int> sorted_map(curr_map.begin(), curr_map.end());
        string result = "";
        for (auto &elem : sorted_map) {
            result += elem.first;
            if (elem.second > 1) {
                result += to_string(elem.second);
            }
        }

        return result;
    }
};
