class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minH;
    int size;
    KthLargest(int k, vector<int>& nums) {
        
        size=k;
        for(int i=0;i<nums.size();i++)
        {
            minH.push(nums[i]);
            if(minH.size()>k)
                minH.pop();
                
        }
        
    }
    
    int add(int val) {
       minH.push(val);
        if(minH.size()>size)
            minH.pop();
        
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
