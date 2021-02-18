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
     /*bool isSameTree(TreeNode* p, TreeNode* q) {
                                                                 //RECURSIVE
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }*/
    bool isSameTree(TreeNode* p, TreeNode* q) {
                                                                //ITERATIVE
       // if(!p && !q) return true;     
       // if(!p || !q) return false;
        
        queue<TreeNode*> Q;
        Q.push(p); Q.push(q);
        while(!Q.empty())
        {
            TreeNode* tree1=Q.front(); Q.pop();
            TreeNode* tree2=Q.front(); Q.pop();
            
            if(!tree1 && !tree2) continue;
            if(!tree1 || !tree2) return false;
            if(tree1->val != tree2->val) return false;
            
            Q.push(tree1->left);
            Q.push(tree2->left);
            
            Q.push(tree1->right);
            Q.push(tree2->right);
        }
        return true;
    }
};
