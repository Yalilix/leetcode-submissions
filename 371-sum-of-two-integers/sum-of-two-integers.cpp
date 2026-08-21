class Solution {
public:
    int getSum(int a, int b) {

        int cur = (a & b) << 1;
        int cur2 = a ^ b;
        while ((cur & cur2) != 0) {
            int temp = cur;
            cur = (cur & cur2) << 1;
            cur2 = temp ^ cur2;
        }

        return cur | cur2;
    }
};