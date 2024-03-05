class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if (n == 1) return 1;
        int left = 0;
        int right = n - 1;
        while (left < right) {
             if (s[left] != s[right]) {
                break;}
            else{
                char word = s[left];
            while (left < right + 1 && s[left] == word) {
                left++;
            }
            while (left - 1 < right && s[right] == word) {
                right--;  
            }

            }
            
        }
        return (right - left + 1);
    }
};
