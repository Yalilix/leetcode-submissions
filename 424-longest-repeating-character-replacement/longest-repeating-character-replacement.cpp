class Solution {
public:
    int characterReplacement(string s, int k) {
        // slide a window
        // track the freq of each char in a map
        // we take the largest freq from the map
        // and check whether it satisfy window length - k >= 0 

        int l = 0, r = 0;
        map<char, int> hm;
        int n = s.size();

        int ret = 0;
        while (r < n) {
            hm[s[r]]++;
            auto maxFreq = max_element(hm.begin(), hm.end(), [](auto& a, auto& b) {
                return a.second < b.second;
            })->second;
            
            while ((r - l + 1) - k > maxFreq) {
                hm[s[l]]--;
                l++;
                maxFreq = max_element(hm.begin(), hm.end(), [](auto& a, auto& b) {
                    return a.second < b.second;
                })->second;
            }

            ret = max(ret, r - l + 1);
            r++;
        }

        return ret;
    }
};