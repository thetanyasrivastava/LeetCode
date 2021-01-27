//Using HEAP


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        if(arr.size()==0)
            return res;
        
       priority_queue<pair<int,int>> maxH;
      
        for(int i=0;i<arr.size();i++)
        {
            maxH.push({abs(arr[i]-x),arr[i]});
            
            while(maxH.size()>k)
                maxH.pop();
      
        }
        while(maxH.size()>0)
        {
            res.push_back(maxH.top().second);
            maxH.pop();
        }
       
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> minH;
        for(int i=0;i<res.size();i++)
        {
            minH.push(res[i]);
            
            while(minH.size()>k)
                minH.pop();
        }
        
        while(minH.size()>0)
        {
            ans.push_back(minH.top());
            minH.pop();
        }
        return ans;
    }
};
