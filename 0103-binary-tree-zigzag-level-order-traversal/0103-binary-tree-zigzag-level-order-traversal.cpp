class Solution {
public:
    void preorder(TreeNode* root, vector<vector<int>>&vec, int level)
    {
        if(root == NULL)
            return;
        if(vec.size() == level)
        {
            vector<int>x;
            vec.push_back(x);
        }
        vec[level].push_back(root->val);
        preorder(root->left,vec,level+1);
        preorder(root->right,vec,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>vec;
        preorder(root, vec,0);
        for(int i=0;i<vec.size();i++)
        {
            if(i%2)
            {
                reverse(vec[i].begin(),vec[i].end());
            }
        }
        return vec;
    }
};