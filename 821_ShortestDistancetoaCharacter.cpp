class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        
        //T.C. = O(n)
        //S.C. = O(n)
          int len= s.size();
        
        vector<int> leftDis(len,INT_MAX);
        vector<int> rightDis(len,INT_MAX);
                                                            
        /*int leftDis[len];
        int rightDis[len];
        
        fill(leftDis,leftDis+len,INT_MAX);
        fill(rightDis,rightDis+len,INT_MAX);*/
        
        int runningDis = INT_MAX;
        
        //from left to right Direction
        for(int i=0;i<len;i++)
        {
            if(s[i]==c)
            {
                runningDis=0;
                leftDis[i] = runningDis;
            }
            else
            {
                if(runningDis!=INT_MAX)
                {
                    runningDis++;
                    leftDis[i]=runningDis;
                }
            }
        }
        
        runningDis = INT_MAX;
        
        //from right to left Direction
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]==c)
            {
                runningDis=0;
                rightDis[i] = runningDis;
            }
            else
            {
                if(runningDis!=INT_MAX)
                {
                    runningDis++;
                    rightDis[i]=runningDis;
                }
            }
        }
        
        vector<int> answer(len);
        
        for(int i=0;i<len;i++)
        {
            answer[i]=min(leftDis[i],rightDis[i]);
        }
        
        return answer;
        
    }
};
