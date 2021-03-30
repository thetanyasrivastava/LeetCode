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
    /*int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        if(!root)
            return ans;
        inorder(root,k,ans);
        return ans;
    }
    void inorder(TreeNode* root, int &k, int &ans)
    {
        if(!root)
            return;
        if(k<1) return;
        
        inorder(root->left,k,ans);
        
        k--;
        if(k == 0)
        {                                       //TC = O(k)
            ans = root->val;
            //return;
        }
        
        inorder(root->right,k,ans);
    }*/
    
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        vector<int> v;
        inorder(root,k,v);
        return v[k-1];
    }
    void inorder(TreeNode* root, int &k, vector<int> &v)
    {
        if(!root) return;
        inorder(root->left,k,v);
        
        v.push_back(root->val);
        
        inorder(root->right,k,v);
    }
    
    /*int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while(curr || !s.empty())
        {
            while(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
                                                                 
            curr=s.top();
            s.pop();
            k--;
            if(k==0) return curr->val;
            
            curr=curr->right;
        }
        return 0;
    }
    
    /*T.C. = O(H+k) 
    for balanced tree, O(log N + k) and O(N + k) for unbalanced tree with all the nodes in the left subtree
    
    S.C. = O(H)
    O(N) = worst case(skewed tree)
    O(log N) = average case of balanced tree */
};
