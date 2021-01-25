// using min_heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0)
            return 0;
        
        priority_queue<int,vector<int>,greater<int>> minH;
        
        for(int i=0;i<n;i++)
        {
            minH.push(nums[i]);
            if(minH.size()>k)
                minH.pop();
        }
        return minH.top();
    }
};
