class Solution {
public: 
    //Method - 1 Recursion  T.C. = O(k) S.C. = O(1)
    int kthGrammar(int n, int k) {
        if(n==1 && k==1)
            return 0;
        
        int mid = pow(2,n-1)/2;
        
        if(k<=mid)
            return kthGrammar(n-1,k);
        
        return !kthGrammar(n-1,k-mid);
    }
    
    /*//Method-2 Brute Force - TLE
    int kthGrammar(int n, int k) {
        vector<int> nums;
        nums.push_back(0);
        while(n--)
        {
            solve(nums);
        }
        return nums[k-1];
    }
    
    void solve(vector<int> &nums)
    {
        if(nums.size()==0)
            return;
        
        int val=nums.back();
        nums.pop_back();
        solve(nums);
        
        if(val==1)
        {
            nums.push_back(1);
            nums.push_back(0);
        }
        else
        {
            nums.push_back(0);
            nums.push_back(1);
        }
    }*/
};

