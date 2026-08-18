class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = m;
        int top = 0, bottom = n;

        vector<int> ret;
        while (left < right && top < bottom) {
            // top row insertion
            for (int i = left; i < right; i++) {
                ret.push_back(matrix[left][i]);
            }
            top += 1;

            // right column insertion
            for (int i = top; i < bottom; i++) {
                ret.push_back(matrix[i][right - 1]);
            }
            right -= 1;

            if (!(left < right && top < bottom)) break;

            // bottom row insertion
            for (int i = right - 1; i >= left; i--) {
                ret.push_back(matrix[bottom - 1][i]);
            }
            bottom -= 1;

            // left column insertion
            for (int i = bottom - 1; i >= top; i--) {
                ret.push_back(matrix[i][left]);
            }
            left += 1;
        }

        return ret;
    }
};