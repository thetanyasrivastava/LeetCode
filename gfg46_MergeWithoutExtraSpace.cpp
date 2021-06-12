//https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

class Solution{
public:

    int nextGap(int gap)
    {
        if(gap<=1)
            return 0;
        return (gap/2) + (gap%2);
    }
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    /*Method -1
	    T.C. = O(s log s) + O(s) + O(s)
	    
	    int s=n+m;
	    int arr3[s];
	    int k=0;
	    for(int i=0;i<n;i++)
	        arr3[k++]=arr1[i];
	   
	   for(int i=0;i<m;i++)
	        arr3[k++]=arr2[i];
	        
	        sort(arr3,arr3+s);
	        
	        k=0;
	        for(int i=0;i<n;i++)
	            arr1[i]=arr3[k++];
	       
	        for(int i=0;i<m;i++)
	            arr2[i]=arr3[k++];*/
	            
	  
	 
	  
	  
	  //Method-3 : Gap Method
	  int i,j,gap=n+m;
	  for(gap=nextGap(gap);gap>0;gap=nextGap(gap))
	  {
	      //for comparing elements in the first array
	   for(i=0;i+gap<n;i++)
    	  {
    	      if(arr1[i]>arr1[i+gap])
    	      {
    	          swap(arr1[i],arr1[i+gap]);
    	      }
    	  }
    	  
    	  //for comparing elements in both the arrays
    	  for(j=gap>n?gap-n:0; i<n&&j<m; i++,j++)
    	  {
    	      if(arr1[i]>arr2[j])
    	      {
    	          swap(arr1[i],arr2[j]);
    	      }
    	  }
    	  
    	  //for comparing elements in the second array
    	  if(j<m)
    	  {
    	      for(j=0;j+gap<m;j++)
    	      {
    	          if(arr2[j]>arr2[j+gap])
    	          {
    	              swap(arr2[j],arr2[j+gap]);
    	          }
    	       }
	        }
    	 
    	}
	}
};
