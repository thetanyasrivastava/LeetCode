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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int curr=n-1;
        int inS=0, inE=n-1;
        unordered_map<int,int> m;
        
        for(int i=0; i<inorder.size(); i++)
            m[inorder[i]]=i;
        
        TreeNode* root=build(inorder,postorder,curr,inS,inE,m);
        
        return root;
    }
    
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int &curr,int inS,int inE,unordered_map<int,int> &m)
    {
        if(inS>inE) return NULL;
        TreeNode* root = new TreeNode(postorder[curr]);
        int mid=m[postorder[curr--]];
        
        root->right=build(inorder,postorder,curr,mid+1,inE,m);
        root->left=build(inorder,postorder,curr,inS,mid-1,m);
        
        return root;
    }
};
