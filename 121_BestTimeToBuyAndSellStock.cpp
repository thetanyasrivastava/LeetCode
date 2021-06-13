class Solution {
public:
    //Method - 3 
    //T.C. = O(n)  S.C. = O(1)
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int profit = 0;
        
        for(int i=0;i<prices.size();i++)
        {
            minSoFar = min(minSoFar, prices[i]);
            profit = max(profit, prices[i]-minSoFar);
        }
        return profit;
    }
    
    /*//Method - 2
    //T.C. = O(n)  S.C. = O(n)
    
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<int> aux(n);
        int maxSoFar=prices[n-1];
        int profit=0;
        
        for(int i=n-1;i>=0;i--)
        {
            maxSoFar=max(maxSoFar,prices[i]);
            aux[i]=maxSoFar;
            profit=max(profit,aux[i]-prices[i]);
        }
        return profit;
    }*/
    
    /*//Method-3
    //T.C. = O(n^2) S.C. = O(1)
    int maxProfit(vector<int>& prices)
    {
        int n =prices.size();
        return buyandsell(prices,0,n-1);
        
    }
    int buyandsell(vector<int>& prices,int start,int end)
    {
        if(end<=start)
            return 0;
        int maxprofit=0;
        for(int i=start;i<end;i++)
        {
            for(int j=i+1;j<=end;j++)
            {
                //profit=max(profit, prices[j]-pricesi]);
                int profit = prices[j] - prices[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
    }*/
    
     /*int maxProfit(vector<int>& prices)
     {
         int n =prices.size();
         if(n<2)
            return 0;
         // int arr[n];
         // copy(prices.begin(), prices.end(), arr);
         int maxprofit=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                // profit=max(profit, arr[j]-arr[i]);
                int profit = arr[j] - arr[i];
                if (profit > maxprofit)
                    maxprofit = profit;
            }
        }
        return maxprofit;
     }*/
};
