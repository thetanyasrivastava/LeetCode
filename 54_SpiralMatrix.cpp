class Solution {
public:
    /*
    Using Four Pointer Solution, T.C. = O(n)
    
    1. Four pointers: top,down,left,right
    2. Four Directions: 0,1,2,3
    
    dir 0 = left to right
    dir 1 = top to down
    dir 2 = right to left
    dir 3 = down to top
    
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
       int n=matrix.size();
        int m=matrix[0].size();
        int top=0,down=n-1;
        int left=0,right=m-1;
        int dir=0;
        
        while(top<=down && left<=right)
        {
            if(dir==0) //left->right
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir==1) //top->down
            {
                for(int i=top;i<=down;i++)
                    ans.push_back(matrix[i][right]);
                right--;
            }
            else if(dir==2) //right->left
            {
                for(int i=right;i>=left;i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }
            else if(dir==3) //down->top
            {
                for(int i=down;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
            
            dir=(dir+1)%4;      //finding the direction
        }
        return ans;
    }
};
