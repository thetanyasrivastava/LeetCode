class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> m;
        int n=arr.size();
        for(int i=0;i<n;i++)
            m[arr[i]]++;
        
        /*int t;
        int lucky_no=-1;;
        for(int i=0;i<n;i++)
        {
            if(m[arr[i]]==arr[i])
            {
                t=arr[i];
                lucky_no=max(lucky_no,t);
            }
        }
        
        return lucky_no;*/
        
        
        int maxm=-1;
        for(auto x:m)
        {
            if(x.first==x.second)           //x.first=arr[i], x.second=m[arr[i]]
            {
                maxm=max(maxm,x.first);     
            }
        }
        return maxm;
    }
};
