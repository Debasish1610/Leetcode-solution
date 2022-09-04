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
    
    static bool compare(pair<int, pair<int,int>>firstPair, pair<int, pair<int,int>>secondPair) {
        if (firstPair.second.second == secondPair.second.second) {
            if (firstPair.second.first == secondPair.second.first) {
                return firstPair.first < secondPair.first;
            }
            return firstPair.second.first < secondPair.second.first;
        }
        
        return firstPair.second.second < secondPair.second.second;
    }
    
    void vTraversal(TreeNode* root, pair<int,int>rowColumn, vector<pair<int, pair<int,int>>> &storeNodeColumn) {
        if (root->left != NULL) {
            storeNodeColumn.push_back({root->left->val, {rowColumn.first+1, rowColumn.second-1}});
            vTraversal(root->left, {rowColumn.first+1, rowColumn.second-1}, storeNodeColumn);
        } 
        if (root->right != NULL) {
            storeNodeColumn.push_back({root->right->val, {rowColumn.first+1, rowColumn.second+1}});
            vTraversal(root->right, {rowColumn.first+1, rowColumn.second+1}, storeNodeColumn);
        }
        
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int, pair<int,int>>>storeNodeColumn;
        storeNodeColumn.push_back({root->val, {0,0}});
        vTraversal(root, {0,0}, storeNodeColumn);
        
        sort(storeNodeColumn.begin(), storeNodeColumn.end(), this->compare);
        
        int outputSize = storeNodeColumn[storeNodeColumn.size()-1].second.second - storeNodeColumn[0].second.second + 1;
        vector<vector<int>> output(outputSize);
        
        for (int i = 0; i < storeNodeColumn.size(); i++){
            output[storeNodeColumn[i].second.second - storeNodeColumn[0].second.second].push_back(storeNodeColumn[i].first);
        }
        
        return output;
    }
};