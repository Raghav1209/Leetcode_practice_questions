// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void solve(vector<int> arr,int n,vector<int> &v,int i,int sum){
        
        if(i==n){
            v.push_back(sum);
            return;
        }
        
    //   v.push_back(sum);
       solve(arr,n,v,i+1,sum);
       int x = sum+arr[i];
       solve(arr,n,v,i+1,x);
        
        
        
        

        
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        vector<int> v;
        
        // v.push_back(0);
        int sum = 0;
        solve(arr,N,v,0,sum);
        sort(v.begin(),v.end());
        return v;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends