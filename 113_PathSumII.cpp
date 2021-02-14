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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath;
        int currSum=0;
        hasPathSum(root,targetSum,ans,currPath,currSum);
        return ans;
    }
    
    void hasPathSum(TreeNode* root,int targetSum,vector<vector<int>> &ans,vector<int> &currPath, int currSum)
    {
        if(!root) return;
        currSum += root->val;
        cout<<currSum<<" ";
        currPath.push_back(root->val);
        
        if(!(root->left) && !(root->right) && currSum == targetSum)
        {
                ans.push_back(currPath);                
        }
        hasPathSum(root->left,targetSum,ans,currPath,currSum);
        hasPathSum(root->right,targetSum,ans,currPath,currSum);
        
        currPath.pop_back();
        
    }
};
