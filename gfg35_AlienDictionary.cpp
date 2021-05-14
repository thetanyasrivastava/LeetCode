class Solution{
    public:
    void dfs(int start,vector<vector<int>> &g,vector<int> &vis,stack<char> &s)
    {
        vis[start]=1;
        for(auto neig: g[start])
        {
            if(!vis[neig])
                dfs(neig,g,vis,s);
        }
        
        char ch = start + 'a';
        // ans = ch + ans;
        s.push(ch);
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> g(K);
        for(int i=0;i<N-1;i++)
        {
            string w1=dict[i];
            string w2=dict[i+1];
            //int minLen=min(dict[i].length(),dict[i+1].length());
            
            for(int j=0;j<min(w1.length(),w2.length());j++)
            {
                if(w1[j]!=w2[j])
                {
                    g[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
            }
        }
        
        stack<char> s;
        vector<int> vis(K,0);
         string ans="";
        for(int i=0;i<K;i++)
        {
            if(!vis[i])
                dfs(i,g,vis,s);
        }
        
        
        while(!s.empty())
        {
            ans += s.top();
            s.pop();
        }
        
        return ans;
    }
};
