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
    int checkPalindrome(vector<int> &flag) {
        int even = 0, odd = 0;
        for (int i = 1; i < 10; i++) {
            if (flag[i] % 2) {
                odd++;
            } else {
                even++;
            }
        }
        return (odd <= 1) ? 1 : 0;
    }
    int palindromicPaths (TreeNode* root, vector<int> &flag) {
        if (root == NULL) {
            return 0;
        }
        
        flag[root->val]++;
        if (root->left == NULL && root->right == NULL) {
            int temp = checkPalindrome(flag);
            flag[root->val]--;
            return temp;
        }
        int sum = palindromicPaths(root->left, flag) + palindromicPaths(root->right, flag);
        
        flag[root->val]--;
        return sum;
    }
    
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int>flag(10, 0);
        return palindromicPaths(root, flag);
    }
};