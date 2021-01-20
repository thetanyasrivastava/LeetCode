class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();        //for rows
        if(n==0)
            return 0;
        
        int m=matrix[0].size();     //for columns
      
        
        vector<int> v;
       for(int j=0;j<m;j++)
       {
          int x = (int)matrix[0][j] - 48;
           v.push_back(x);
          
       }
           
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        int mx= MAH(v);
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(matrix[i][j]=='0')
                    v[j]=0;
                else
                { 
                   
                    int x = (int)matrix[i][j] - 48;
                    v[j]=v[j]+x;
                 
                }
            }
            mx=max(mx,MAH(v));
           
        }
        return mx;
   }
     
    int MAH(vector<int>& heights)
    {
        
        vector<int> nsr = findNSR(heights);
        vector<int> nsl = findNSL(heights);
        int res = findHistogram(heights,nsr,nsl);
        
        return res;
    }
    
vector<int> findNSR(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> s1;
        vector<int> v1;
        s1.push(n-1);
        v1.push_back(n);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && heights[s1.top()]>=heights[i])
                s1.pop();
            
            int ns1=(s1.empty())?(n):(s1.top());
            v1.push_back(ns1);
            s1.push(i);
        }
        reverse(v1.begin(),v1.end());
        
        return v1;
   }
    
    vector<int> findNSL(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> s2;
        vector<int> v2;
        s2.push(0);
        v2.push_back(-1);
        
        for(int i=1;i<n;i++)
        {
            while(!s2.empty() && heights[s2.top()]>=heights[i])
                s2.pop();
            
            int ns2=(s2.empty())?(-1):(s2.top());
            v2.push_back(ns2);
            s2.push(i);
        }
        return v2;
    }
    
    int findHistogram(vector<int>& heights,vector<int> nsr,vector<int> nsl)
    {
        int maxArea=0;
        int units=0, area=0;
        
        for(int i=0;i<heights.size();i++)
        {
            units=(nsr[i]-nsl[i])-1;
            
            area=units*heights[i];
            
            maxArea = max(maxArea,area);
        }
        //cout<<maxArea;
        return maxArea;
    }
};
