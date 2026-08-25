/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        vector<vector<int>> ret;

        if (!root) return {};
        dfs(root, targetSum, 0, ret, cur);

        return ret;
    }
private:
    void dfs(TreeNode* root, 
            int targetSum, int sum, 
            vector<vector<int>>& ret, vector<int> cur
    ) {
        sum += root->val;
        cur.push_back(root->val);
        if (!root->left and !root->right) {
            if (sum == targetSum) ret.push_back(cur);
        }

        if (root->left) dfs(root->left, targetSum, sum, ret, cur);
        if (root->right) dfs(root->right, targetSum, sum, ret, cur);

        return;
    }
};