class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        //sort(array.begin(),array.end());
        
        int lo=0,mid=0,hi=array.size()-1;
        while(mid<=hi)
        {
            if(array[mid]<a)
            {
                swap(array[lo++],array[mid++]);
            }
            else if(array[mid]>b)
            {
                swap(array[mid],array[hi--]);
            }
            else
                mid++;
        }
    }
};
