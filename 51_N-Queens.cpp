class Solution {
public:
    //Method - 1
    
    /*vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> nqueenpuzzle;
        vector<string> board(n);
        string s(n,'.');
        
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
            cout<<board[i]<<endl;
        }
            
        
        solve(0,n,board,nqueenpuzzle);
        return nqueenpuzzle;
    }
    
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &nqueenpuzzle)
    {
        if(col==n)
        {
            nqueenpuzzle.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col]='Q';
                solve(col+1,n,board,nqueenpuzzle);
                board[row][col]='.';
            }
        }
    }
    
    bool isSafe(int row,int col, int n,vector<string> &board)
    {
        //creating copies so that for checking all the 3 safe conditions, row and col starts         //with the same value
        
        int rowcopy=row;
        int colcopy=col;
        while(row>=0 && col>=0)         //for upper-left diagonal
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row=rowcopy;
        col=colcopy;
        while(col>=0)                   //for left side
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        
        row=rowcopy;
        col=colcopy;
        while(row<n && col>=0)          //for lower-left diagonal
        {
            if(board[row][col]=='Q')
                return false;
            
            row++;
            col--;
        }
        
        return true;
    }*/
    
    //Method - 2 Hashing/ Vector
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> nqueenpuzzle;
        vector<string> board(n);
        string s(n,'.');
        
        
        for(int i=0;i<n;i++)
        {
            board[i]=s;
            cout<<board[i]<<endl;
        }
            
        vector<int> leftRow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        
        solve(0,n,board,nqueenpuzzle,leftRow,upperDiagonal,lowerDiagonal);
        return nqueenpuzzle;
    }
    
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &nqueenpuzzle,
      vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal)
    {
        if(col==n)
        {
            nqueenpuzzle.push_back(board);
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
                solve(col+1,n,board,nqueenpuzzle,leftRow,upperDiagonal,lowerDiagonal);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
    
};
