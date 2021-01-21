class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int> v;
        if(n==0)
            return v;
        
        stack<int> s;
        s.push(n-1);
        
        v.push_back(0);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && T[i]>=T[s.top()])
                s.pop();
            
            int warm = (!s.empty()) ? (s.top()-i) : 0;
            v.push_back(warm);
            s.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
            
    }
};
