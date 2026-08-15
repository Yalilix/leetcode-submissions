class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> hm1;
        unordered_map<char, int> hm2;

        for (int i = 0; i < s.size(); i++) {
            hm1[s[i]]++;
            hm2[t[i]]++;
        }

        return hm1 == hm2;
    }
};