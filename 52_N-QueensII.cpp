class Solution {
public:
    //Method -1
    /*int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            board[i]=s;
        
        int count=0;
        solve(0,n,board,count);
        return count;
    }
    
    void solve(int col,int n, vector<string>& board, int &count)
    {
        if(col==n)
        {
            count++;
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col]='Q';
                solve(col+1,n,board,count);
                board[row][col]='.';
            }
        }
    }
    
    bool isSafe(int row,int col,int n,vector<string> &board)
    {
        int rowcopy=row;
        int colcopy=col;
        
        //for upper-left-diagonal
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        //for left side
        row=rowcopy;
        col=colcopy;
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        
        
        //for lower-left-diagonal
        row=rowcopy;
        col=colcopy;
        
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        
        return true;
    }*/
    
    //Method - 2 Hashing/Vector
    
    //Method - 2 Hashing/ Vector
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
            cout<<board[i]<<endl;
        }
            
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        
        int count=0;
        solve(0,n,board,count,leftRow,upperDiagonal,lowerDiagonal);
        return count;
    }
    
    void solve(int col,int n,vector<string> &board,int &count,
      vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal)
    {
        if(col==n)
        {
            count++;
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1,n,board,count,leftRow,upperDiagonal,lowerDiagonal);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
    
};
