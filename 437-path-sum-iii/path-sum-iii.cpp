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
    int pathSum(TreeNode* root, int targetSum) {
        int total = 0;
        dfs(root, targetSum, total);
        return total;
    }
private:
    void dfs(TreeNode* root, int targetSum, int& total) {
        if (!root) return;
        helper(root, targetSum, 0, total);
        dfs(root->left, targetSum, total);
        dfs(root->right, targetSum, total);
    }

    void helper(TreeNode* root, int targetSum, long long sum, int& total) {
        if (!root) return;
        if (sum + root->val == targetSum) total++;
        
        helper(root->left, targetSum, sum + root->val, total);
        helper(root->right, targetSum, sum + root->val, total);

        return;
    }
};