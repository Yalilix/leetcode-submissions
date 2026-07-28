typedef long long ll;

class Solution {
public:
    string smallestPalindrome(string s) {
        int count[26] = {};
        for (auto c : s) {
            count[c - 'a']++;
        }

        int len = s.length();
        string ret(len, ' ');
        string left, right;

        char odd_char = ' ';
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;

            int halfLen = count[i] / 2;
            char c = 'a' + i;
            left.append(halfLen, c);
            right.append(halfLen, c);
            if (count[i] % 2) odd_char = c;
        }   

        reverse(right.begin(), right.end());

        if (odd_char == ' ') return left + right;
        return left + odd_char + right;
    }
};