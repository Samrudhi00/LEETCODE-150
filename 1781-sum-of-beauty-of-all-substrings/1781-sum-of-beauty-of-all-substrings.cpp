class Solution {
public:
    int MaxCnt(vector<int>& charCnt) {
        int max = INT_MIN;
        for (int i = 0; i < charCnt.size(); i++) {
            if (charCnt[i] != 0) {
                max = std::max(max, charCnt[i]);
            }
        }
        return max;
    }

    int MinCnt(vector<int>& charCnt) {
        int min = INT_MAX;
        for (int i = 0; i < charCnt.size(); i++) {
            if (charCnt[i] != 0) {
                min = std::min(min, charCnt[i]);
            }
        }
        return min;
    }

    int beautySum(string s) {
        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            vector<int> charCnt(26, 0);

            for (int j = i; j < n; j++) {
                ++charCnt[s[j] - 'a'];

                int beauty = MaxCnt(charCnt) - MinCnt(charCnt);
                sum += beauty;
            }
        }

        return sum;
    }
};