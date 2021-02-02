class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            res ^= nums[i];                 //Using property of XOR 
        }                                   // 0^n=n, n^n=0
        return res;
    }
};
