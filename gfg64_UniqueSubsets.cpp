class Solution
{
    
    public:
    set<vector<int>> s;
    void solve(vector<int> arr,vector<int> &op)
    {
        if(arr.size()==0)
        {
            if(s.find(op)==s.end())
            {
                s.insert(op);
             }
             return;
        }
        
        vector<int> op1=op;
        vector<int> op2=op;
        
        op2.push_back(arr[0]);
        arr.erase(arr.begin()+0);
        
        solve(arr,op1);
        solve(arr,op2);
    }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        
        sort(arr.begin(),arr.end());
        vector<int> op={};
        
        solve(arr,op);
        
        vector<vector<int>> res;
        
        for(auto x:s)
            res.push_back(x);
        
        return res;
    }
};
