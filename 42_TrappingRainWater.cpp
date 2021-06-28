class Solution {
public:
    /*
    //Method - 2 
    //T.C. = O(N) S.C. = O(N)
    int trap(vector<int>& height) {
        if(height.empty())
            return 0;
        
        int totalWater=0;
        int length=height.size();
        
        vector<int> leftMax(length), rightMax(length);
        
        leftMax[0]=height[0];
        
        for(int i=1;i<length;i++)
        {
            leftMax[i]=max(height[i],leftMax[i-1]);
        }
        
        rightMax[length-1]=height[length-1];
        
        for(int i=length-2;i>=0;i--)
        {
            rightMax[i]=max(height[i],rightMax[i+1]);
        }
        
        for(int i=1;i<length-1;i++)
        {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return totalWater;
 
    }*/
    
    ////Method - 3
    //T.C. = O(N) S.C. = O(1)
    
    int trap(vector<int>& height)
    {
        int n=height.size();
        int l=0,r=n-1;
        int leftMax=0, rightMax=0;
        int res=0;
        
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=leftMax)
                    leftMax=height[l];
                else
                    res+=leftMax-height[l];
                l++;
            }
            else
            {
                if(height[r]>=rightMax)
                    rightMax=height[r];
                else
                    res+=rightMax-height[r];
                r--;
            }
        }
        return res;
    }
};
