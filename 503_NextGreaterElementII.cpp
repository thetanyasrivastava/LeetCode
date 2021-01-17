class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> s;
        vector<int> v;
        int n = nums.size();
        if(n==0)
            return v;
        s.push(nums[n-1]);
         for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            
           s.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums[i])
                s.pop();
            
            int nng = (s.empty())?(-1):(s.top());
            v.push_back(nng);
            s.push(nums[i]);
        }
        reverse(v.begin(),v.end());
        return v;
        
        
    }
};
