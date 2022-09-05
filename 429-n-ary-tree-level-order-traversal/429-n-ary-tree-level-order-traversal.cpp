/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    void traversal(Node *root, int level, vector<vector<int>> &output) {
        if (root == NULL) {
            return;
        }
        
        if (level > output.size()) {
            output.push_back({root->val});
        } else {
            output[level-1].push_back(root->val);
        }
        
        for (int i = 0; i < root->children.size(); i++) {
            traversal(root->children[i], level+1, output);
        }
        
        return;
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> output;
        
        traversal(root, 1, output);
        
        return output;
    }
};