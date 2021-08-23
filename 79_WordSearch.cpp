class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(board,word,i,j,0))
                    return true;
                    
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word,int r,int c,int index)
    {
        if(index==word.length())
            return true;
        if(r<0 || c<0 || r>board.size()-1 || c>board[0].size()-1 || word[index]!=board[r][c])
            return false;
        
        char ch = board[r][c];
        board[r][c]='#';
        
        if(dfs(board,word,r+1,c,index+1) || dfs(board,word,r-1,c,index+1)|| dfs(board,word,r,c+1,index+1) || dfs(board,word,r,c-1,index+1))
            return true;
        
        board[r][c]=ch;
        return false;
    }
    
    
    /*//MEthod -2 
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(board,word,i,j,0,vis,m,n))
                    return true;
                    
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word,int r,int c,int index,vector<vector<bool>> &vis,int m,int n)
    {
        if(board[r][c]==word[index])
        {
            vis[r][c]=true;
            
            if(index == word.length()-1)
                return true;
            
            if(r-1>=0 && !vis[r-1][c])
                if(dfs(board,word,r-1,c,index+1,vis,m,n))
                    return true;
            
             if(r+1<m && !vis[r+1][c])
                if(dfs(board,word,r+1,c,index+1,vis,m,n))
                    return true;
            
             if(c-1>=0 && !vis[r][c-1])
                if(dfs(board,word,r,c-1,index+1,vis,m,n))
                    return true;
            
             if(c+1<n && !vis[r][c+1])
                if(dfs(board,word,r,c+1,index+1,vis,m,n))
                    return true;
            
            vis[r][c]=false;
            return false;
        }
        
        
        return false;
    }*/
};
