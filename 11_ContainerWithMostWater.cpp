class Solution {
public:
    int maxArea(vector<int>& height) {
        /*Method - 1
        //T.C. =O(n^2) S.C. =O(1)
        
        int maxarea=0;
        int l,b;
        for(int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                l=min(height[i],height[j]);
                b=j-i;
                maxarea=max(maxarea,l*b);
            }
        }
        return maxarea;*/
        
        /*Method - 2.a
        //T.C. =O(n) S.C. =O(1)
        int maxwater=0;
        int l=0,r=height.size()-1;
        
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                maxwater=max(maxwater,height[l]*(r-l));
                l++;
            }
            else
            {
                maxwater=max(maxwater,height[r]*(r-l));
                r--;
            }
        }
        return maxwater;*/
        
        //Method - 2.b
        //T.C. =O(n^2) S.C. =O(1)
        int l=0,r=height.size()-1;
        int maxwater=0;
        
        while(l<r)
        {
            int w=r-l;
            int h=min(height[l],height[r]);
            
            maxwater=max(maxwater, w*h);
            
            if(height[l]<=height[r])        //minm height will change
                l++;
            else
                r--;
        }
        
        return maxwater;
        
    }
};
