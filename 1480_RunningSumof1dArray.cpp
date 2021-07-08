class Solution {
public:
   /*//Method -1 
    //T.C. = O(N)   S.C. = O(N)
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            res.push_back(sum);
        }
        return res;
    }*/
    
    //Method - 2
    //T.C. = O(N)   S.C. = O(1)
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=nums[i-1];
        }
        return nums;
    }
};
