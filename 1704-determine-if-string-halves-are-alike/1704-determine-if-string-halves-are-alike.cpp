class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size() / 2;
        string a, b;

        for (int i = 0; i < n; i++) {
            a += s[i];
        }
        for (int i = n; i < s.size(); i++) {
            b += s[i];
        }

        // counting the vowels
        int counta = 0, countb = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' ||
                a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' ||
                a[i] == 'O' || a[i] == 'U') {
                counta++;
            }
        }

        for (int i = 0; i < b.size(); i++) {
            if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' ||
                b[i] == 'u' || b[i] == 'A' || b[i] == 'E' || b[i] == 'I' ||
                b[i] == 'O' || b[i] == 'U') {
                countb++;
            }
        }

        if (counta == countb) {
            return true;
        }

        return false;
    }
};