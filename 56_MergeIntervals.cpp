class Solution {
public:
    /*vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> resmerge;
        if(intervals.size()==0)
            return resmerge;
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]<=temp[1])
                temp[1]=max(intervals[i][1],temp[1]);
            else
            {
                resmerge.push_back(temp);
                temp=intervals[i];
            }
        }
        resmerge.push_back(temp);
        return resmerge;
    }*/


vector<vector<int>> merge(vector<vector<int>> &intervals)
{
	vector<vector<int>> resmerge;
	sort(intervals.begin(),intervals.end());
    vector<int> temp=intervals[0];
    for(auto it:intervals)
    {
        if(it[0]<=temp[1])
            temp[1]=max(it[1],temp[1]);
        else
        {
            resmerge.push_back(temp);
            temp=it;
        }
    }
    resmerge.push_back(temp);
    return resmerge;
}
};
