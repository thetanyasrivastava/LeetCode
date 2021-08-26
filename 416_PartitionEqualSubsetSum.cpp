class Solution {
public:
    
    //Method - 2.2. Bottom up - Tabulation - Dynamic Programming 
    //T.C. = O(n * sum of elements)
    //S.C. = O(n * sum of elements)
    /*bool canPartition(vector<int>& nums) {
        int sum=0; 
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        if(sum%2!=0)            //sum is odd
            return false;
        
        //sum is even
        return subsetSum(nums,sum/2);
    }
    
    bool subsetSum(vector<int>&nums,int target)
    {
        int n=nums.size();
        bool t[n+1][target+1];
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<target+1;j++)
            {
                if(i==0)
                    t[i][j]=false;
                if(j==0)
                    t[i][j]=true;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<target+1;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][target];
    }*/
    
    
    
    //Method - 2.1. TopDown - Memoization - Dynamic Programming 
    //T.C. = O(n * sum of elements)
    //S.C. = O(n * sum of elements)
    
    
    bool canPartition(vector<int>& nums) {
        int sum=0; 
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        
        if(sum%2!=0)            //sum is odd
            return false;
    
        int n=nums.size();
        vector<vector<int>> t(n+1, vector<int>(sum/2+1,-1));
        //sum is even
        return subSet(nums,sum/2,n,t);
    }
    
    
    
    bool subSet(vector<int> &nums,int target,int n,vector<vector<int>>& t)
    {
        if(n==0)
            return false;
        if(target==0)
            return true;
        
        if(t[n][target] != -1)
            return t[n][target];
        
        if(nums[n-1]<=target)
            return t[n][target]=subSet(nums,target-nums[n-1],n-1,t)||subSet(nums,target,n-1,t);
        
        return t[n][target] = subSet(nums,target,n-1,t);
        
    }
    };
