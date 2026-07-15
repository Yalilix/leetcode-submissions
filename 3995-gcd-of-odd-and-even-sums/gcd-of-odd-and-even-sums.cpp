class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 0;
        int sumEven = 0;
        int k = 1;

        while (k <= n * 2) {
            if (k % 2) sumOdd += k;
            else sumEven += k; 
            k++;
        }

        return gcd(sumEven, sumOdd);
    }
};