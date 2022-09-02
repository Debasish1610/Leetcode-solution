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
    void findTotalNodeInALevel(TreeNode* root, int level, vector<pair<double,double>> &totalNodeSumPair) {
        if (root == NULL) return;
        
        if (totalNodeSumPair.size() < level) {
            totalNodeSumPair.push_back({0, 0});
        }
        
        totalNodeSumPair[level-1].first++;
        totalNodeSumPair[level-1].second += (double)root->val;
        
        findTotalNodeInALevel(root->left, level + 1, totalNodeSumPair);
        findTotalNodeInALevel(root->right, level + 1, totalNodeSumPair);
        return;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double,double>> totalNodeSumPair;
        vector<double> output;
        findTotalNodeInALevel(root, 1, totalNodeSumPair);
        
        for (int i = 0; i < totalNodeSumPair.size(); i++) {
            output.push_back(totalNodeSumPair[i].second/totalNodeSumPair[i].first);
        }
        
        return output;
    }
};