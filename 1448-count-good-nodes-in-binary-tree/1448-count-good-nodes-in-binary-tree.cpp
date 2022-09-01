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
    int goodNodes(TreeNode* root, int maxvalue = INT_MIN) {
        if (root == NULL) {
            return 0;
        }
        
        if (root->val >= maxvalue) {
            return goodNodes(root->left, root->val) + goodNodes(root->right, root->val) + 1;
        }
        
        return goodNodes(root->left, maxvalue) + goodNodes(root->right, maxvalue) + 0;
    }
};