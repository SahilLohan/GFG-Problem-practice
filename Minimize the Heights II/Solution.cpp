// Link : https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1


// Code : 
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        
        int ans = arr[n-1] - arr[0];
        
        int temp_min,temp_max;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i] < k) continue;
            
            temp_min = min(arr[0]+k , arr[i]-k);
            temp_max = max(arr[n-1]-k,arr[i-1]+k);
            
            ans = min(ans , temp_max-temp_min);
        }
        
        return ans;
    }
};
