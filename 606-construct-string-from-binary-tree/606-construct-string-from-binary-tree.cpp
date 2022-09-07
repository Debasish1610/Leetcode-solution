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
    void makeStr(TreeNode* root, string &str) {
        if (root == NULL) return;
        int value = abs(root->val);
        if (root->val < 0) {
            str.push_back('-');
        }
        str = str + to_string(value);
        
        if (root->left == NULL && root->right != NULL) {
            str.push_back('(');
            str.push_back(')');
        } else if (root->left != NULL){
            str.push_back('(');
            makeStr(root->left, str);
            str.push_back(')');
        }
        
        if (root->right != NULL) {
            str.push_back('(');
            makeStr(root->right, str);
            str.push_back(')');
        }
        
        return;
    }
    string tree2str(TreeNode* root) {
        string output;
        makeStr(root, output);
        return output;
    }
};