class Solution {
public:
    int maximumGain(string s, int x, int y) {
        auto countPairs = [](string& text, string pair, int& primaryCount) {
            char firstChar = pair[0], secondChar = pair[1];
            int index = 1;
            while (index < text.length()) {
                if (index > 0 && text[index - 1] == firstChar && text[index] == secondChar) {
                    primaryCount++;
                    text.erase(index - 1, 2);
                    index--;
                    continue;
                }
                index++;
            }
        };

        int totalScore = 0;

        if (x > y) {
            int abCount = 0, baCount = 0;
            countPairs(s, "ab", abCount);
            totalScore += abCount * x;
            countPairs(s, "ba", baCount);
            totalScore += baCount * y;
        } else {
            int baCount = 0, abCount = 0;
            countPairs(s, "ba", baCount);
            totalScore += baCount * y;
            countPairs(s, "ab", abCount);
            totalScore += abCount * x;
        }

        return totalScore;
    }
};
