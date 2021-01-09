class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int cnt = 0, maxm = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                cnt++;
                if(cnt>maxm)
                    maxm=cnt;
            }
            else
                cnt=0;
        }
        return maxm;
    }
};
