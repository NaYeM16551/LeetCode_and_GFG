//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	   // stack<int> s;
	   // for(int i=n-1;i>=0;--i)
	   // {
	   //     int val=arr[i];
	   //     if(s.empty())
	   //     {
	   //         arr[i]=-1;
	   //     }
	   //     else
	   //     {
	   //         while(!s.empty() && s.top()>=val)
	   //          s.pop();
	   //         if(s.empty())
	   //           arr[i]=-1;
	   //          else
	   //           arr[i]=s.top();
	   //     }
	   //     s.push(val);
	          
	   // }
	   
	   for(int i=0;i<n-1;++i)
	   {
	       if(arr[i]>arr[i+1])
	         arr[i]=arr[i+1];
	        else
	          arr[i]=-1;
	   }
	   arr[n-1]=-1;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends