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
    void dfs(TreeNode* root, vector<int>&value) {
        if (root == NULL) return;
        dfs(root->left, value);
        value.push_back(root->val);
        dfs(root->right, value);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>value;
        dfs(root, value);
        int ans = INT_MAX;
        for(int i = 1; i < value.size(); i++) {
            ans = min(ans, value[i]-value[i-1]);
        }
        return ans;
    }
};