class Solution {
public:
    //T.C.= O(n^2)
    
    bool isValidSudoku(vector<vector<char>>& board) {
        //cout<<board.size()<<" "<<board[0].size()<<endl;
        for(int i=0;i<9;i++)        //here,9=board.size()
        {
            for(int j=0;j<9;j++)    //9=board[0].size()
            {
                if(board[i][j]!='.' && !valid(board,i,j))
                    return false;
            }
        }
        return true;
    }
    
    bool valid(vector<vector<char>> &board,int row,int col)
    {
        //cout<<board[row][col]<<endl;
        int c=board[row][col]-'0';
        cout<<c<<" ";
        board[row][col]='.';
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
                return false;
            if(board[i][col]==c)
                return false;
            if(board[ 3*(row/3) + i/3 ][3*(col/3) + i%3]==c)
                return false;
        }
        
        board[row][col]=c;
        return true;
    }
};
