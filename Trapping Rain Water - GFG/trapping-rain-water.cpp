//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int leftMax[n],rightMax[n];
        
        int leftMaxi=INT_MIN,rightMaxi=INT_MIN;
        for(int i=0;i<n;++i)
        {
            leftMaxi=max(leftMaxi,arr[i]);
            leftMax[i]=leftMaxi;
        }
        for(int i=n-1;i>=0;--i)
        {
            rightMaxi=max(rightMaxi,arr[i]);
            rightMax[i]=rightMaxi;
        }
       
        long long int totalWaterTrapped=0;
        for(int i=0;i<n;++i)
        {
            totalWaterTrapped+=min(leftMax[i],rightMax[i])-arr[i]*1LL;
            
            
        }
        return totalWaterTrapped;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends