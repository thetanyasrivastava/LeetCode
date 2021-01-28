//Using Priority Queue - Max Heap

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        if(points.size()==0)
            return res;
        priority_queue<pair<int,pair<int,int>>> maxH;
        for(int i=0;i<points.size();i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            
            maxH.push({(x*x+y*y),{x,y}});
            if(maxH.size()>K)
                maxH.pop();
        }
        
        while(maxH.size()>0)
        {
            
            res.push_back({maxH.top().second.first,maxH.top().second.second});
            maxH.pop();
        }
        return res;
    }
};
