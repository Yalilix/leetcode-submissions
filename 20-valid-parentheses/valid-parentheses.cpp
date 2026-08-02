class Solution {
public:
    bool isValid(string s) {
        map<char, char> hm = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        stack<char> b;

        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                b.push(c);
            } else {
                if (b.empty()) return false;
                if (hm[c] != b.top()) return false;
                b.pop();
            }
        }

        return b.empty();
    }
};