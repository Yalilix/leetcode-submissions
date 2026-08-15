class Solution {
public:
    int reverseBits(int n) {
        int ret = 0, i = 0;

        while (i < 32) {
            ret <<= 1;
            ret = ret | ((n >> i) & 1);
            i++; 
        }
        return ret;
    }
};