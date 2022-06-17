// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int sum = 0;
        unordered_map<int,int> mp;
        int maxx = 0;
        for(int i=0;i<n;i++){
            
            sum += A[i];
            
            if(sum==0){
                maxx = i+1;
            }else{
                
            
            
            if(mp.find(sum)!=mp.end()){
                
                // vector<int> vc = mp[sum];
                // for(int j=0;j<vc.size();j++){
                    maxx = max(maxx,i-mp[sum]);
                // }
                
            }else{
                mp[sum] = i ;
            }
            }
            
            
            
        }
        
        return maxx;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends