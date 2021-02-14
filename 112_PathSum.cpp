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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool isFound = false;
        int currSum=0;
        findSum(root,targetSum,currSum,isFound);
        return isFound;
    }
    
    void findSum(TreeNode* root, int targetSum, int currSum, bool &isFound)
    {
        if(!root)
            return;
        currSum += root->val;
        
        if(!(root->left) && !(root->right) && currSum==targetSum)
            isFound = true;
        
        findSum(root->left,targetSum,currSum,isFound);
        findSum(root->right,targetSum,currSum,isFound);
        
    }
};
