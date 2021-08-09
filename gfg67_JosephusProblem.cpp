class Solution {
  public:
    int safePos(int n, int k) {
        // code here
        vector<int> v(n);
        for(int i=0;i<n;i++)
            v[i]=i+1;
        k--;
        int index=0;
        int ans=-1;
        
        solve(v,k,index,ans);
        return ans;
    }
    void solve(vector<int> &v,int k, int index,int &ans)
    {
        if(v.size()==1)
        {
            ans=v[0];
            return;
        }
        
        index=(index+k)%v.size();
        v.erase(v.begin()+index);
        
        solve(v,k,index,ans);
        
        
    }
    
    /*int safePos(int n, int k) {
        // code here
        vector<int> v(n);
        for(int i=0;i<n;i++)
            v[i]=i+1;
        k--;
        int index=0;
        while(v.size()>1)
        {
            index=(index+k)%v.size();
            v.erase(v.begin()+index);
        }
        return v[0];
    }*/
    /*int safePos(int n, int k) {
        // code here
        return J(n,k);
    }
    
    int J(int n,int k)
    {
        if(n==1)
            return 1;
        return (J(n-1,k) + k-1) % n+1;
    }*/
};
