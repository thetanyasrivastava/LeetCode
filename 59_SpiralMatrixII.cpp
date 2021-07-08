class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n,vector<int>(n));   //creating vector of vectors
        
        //Using four pointers top,down,left and right pointing to first row, last row,
        // first column and last column respectively.
        int top=0, down=n-1;
        int left=0,right=n-1;
        int dir=0;
        int num=1;      //a number to assign
        
        //traversing the matrix spirally
        while(top<=down && left<=right)
        {
            if(dir==0)
            {   //dir = left->right
                for(int i=left;i<=right;i++)
                {
                    spiral[top][i]=num;
                    num++;
                }
                top++;
            }
            else if(dir==1)
            {   //dir = top->down
                for(int i=top;i<=down;i++)
                {
                    spiral[i][right]=num;
                    num++;
                }
                right--;
            }
            else if(dir==2)
            {   ////dir = right->left
                for(int i=right;i>=left;i--)
                {
                    spiral[down][i]=num;
                    num++;
                }
                down--;
            }
            else if(dir==3)
            {   //dir = down->top
                for(int i=down;i>=top;i--)
                {
                    spiral[i][left]=num;
                    num++;
                }
                left++;
            }
            
            dir=(dir+1)%4;      //calculating direction to travel
        }
        
        return spiral;
    }
};
