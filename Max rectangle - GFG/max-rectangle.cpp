//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    private:
     vector<int> leftSmaller(int n,int a[],int x){
        // code here
      stack<int> s;
        vector<int> ans(n);
        int j=x;
        for(int i=0;i<n;++i)
        {
            if(!j)
              x=2*i;
           
            if(s.empty())
            {
                 if(!j)
                  ans[x-i]=-1;
                else
                  ans[x-i]=n; 
            }
            else
            {
                while(!s.empty() && a[s.top()]>=a[x-i])
                  s.pop();
                  
                if(s.empty())
            {
                 if(!j)
                  ans[x-i]=-1;
                else
                  ans[x-i]=n; 
            }
            
            else
              ans[x-i]=s.top();
            }
            s.push(x-i);
         
            
        }
        return ans;
     }

    //Function to find largest rectangular area possible in a given histogram.
    int getMaxArea(int arr[], int n)
    {
        // Your code here
       
        auto leftAns=leftSmaller(n,arr,0);
       // show(leftAns);
       
        auto rightAns=leftSmaller(n,arr,n-1);
        //show(rightAns);
        
        int  ans=INT_MIN;
        for(int i=0;i<n;++i)
        {
            leftAns[i]=max(rightAns[i]-leftAns[i]-1,1);
            int area=arr[i]*leftAns[i];
            ans=max(ans,area);
            
        }
        return ans;
        
        
        
        
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int arr[m];
        //memset(arr,0,sizeof(a));
        int ans=INT_MIN;
        
        for(int i=0;i<n;++i)
        {
            if(!i)
            {
               for(int j=0;j<m;++j)
                arr[j]=M[i][j];
                ans=max(ans,getMaxArea(arr,m));
                
            }
            else
            {
                for(int j=0;j<m;++j)
                {
                    if(M[i][j]==0)
                      arr[j]=0;
                    else
                      arr[j]+=1;
                }
                 ans=max(ans,getMaxArea(arr,m));
                
            }
              
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends