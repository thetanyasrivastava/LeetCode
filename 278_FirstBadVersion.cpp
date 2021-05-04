// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1;
        int high=n;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(!isBadVersion(mid))
                low=mid+1;
            else
                high=mid-1;
        }
        return high+1;
    }
};

/*We can use binary search for this. Search space is [1:n], goal is to find the first 
bad/defective one. Now all the version after the first version are also defective, so take out the mid and check if it is defective, if it is not that means we are before the defective one so we will move right, else if it defective we will go left till we end the search space. Since our high will always point to defective version so high+1 will give the answer [as at the end when low>high , high will point to one before the answer, so high+1]

TC: O(logN), SC: O(1)



*/
