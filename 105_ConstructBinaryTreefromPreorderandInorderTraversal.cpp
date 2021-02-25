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

/*  
  BRUTE FORCE APPROACH
    T.C. - O(n^2)
*/


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start = 0;
        int inS=0, inE=preorder.size()-1;
        TreeNode* root = build(preorder,inorder,start,inS,inE);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &start, int inS, int inE)
    {
        if(inS>inE)
            return NULL;
        TreeNode* root= new TreeNode(preorder[start]);
        
        int mid = search(preorder,inorder,inS,inE,preorder[start]);
        start++;
        
        root->left=build(preorder,inorder,start,inS,mid-1);
        root->right=build(preorder,inorder,start,mid+1,inE);
        
        return root;
    }
    
    int search(vector<int>& preorder,vector<int>& inorder, int low, int high, int num)
    {
        for(int i=0;i<preorder.size();i++)
        {
            if(num==inorder[i])
                return i;
        }
        return -1;
    }
    
};







/*  
  EFFICIENT/OPTIMAL APPROACH
    T.C. - O(n)
*/


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int start = 0;
        int inS=0, inE=preorder.size()-1;
        
        //store all the indices to get start and end for each node's left and right nodes
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        TreeNode* root = build(preorder,inorder,start,inS,inE,m);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &start, int inS, int inE,unordered_map<int,int> &m)
    {
        if(inS>inE)
            return NULL;
        TreeNode* root= new TreeNode(preorder[start]);
        
        int mid = m[preorder[start]];
        start++;
        
        root->left=build(preorder,inorder,start,inS,mid-1,m);
        root->right=build(preorder,inorder,start,mid+1,inE,m);
        
        return root;
    }    
};
