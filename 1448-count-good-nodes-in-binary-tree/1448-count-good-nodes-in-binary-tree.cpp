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
        
        int value = 0;
        
        if (root->val >= maxvalue) {
            value++;
        }
        
        return goodNodes(root->left, max(maxvalue, root->val)) + goodNodes(root->right, max(maxvalue, root->val)) + value;
    }
};