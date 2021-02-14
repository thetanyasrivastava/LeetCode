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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string curr="";
        pathsUtil(root,v,curr);
        return v;
    }
    
    void pathsUtil(TreeNode* root, vector<string> &v,string curr)
    {
        if(!root) return;
        
        if(root->left || root->right)
            curr += (to_string(root->val)) + "->";
        else if(!(root->left) && !(root->right))
        {
            curr += (to_string(root->val));
            v.push_back(curr);
        } 
        pathsUtil(root->left,v,curr);
        pathsUtil(root->right,v,curr);
        
    }
};
