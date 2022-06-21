// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    struct mycmp {

	bool operator()(pair<int,int> l,pair<int,int> r)

	{
		return (l.second > r.second);
	}
};
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> v;
    	
    	for(int i=0;i<n;i++){
    	    v.push_back({arr[i],dep[i]});
    	}
    	
    	sort(v.begin(),v.end());
    	
    // 	for(auto x : v){
    // 	    cout<<x.first<<" "<<x.second<<endl;
    // 	}
    	
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycmp> pq;
        
        // for(auto x : v){
        //     pq.push(x);
        // }
        
        // while(!pq.empty()){
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        
        // int res = 1;
        pq.push(v[0]);
        for(int i=1;i<n;i++){
            pair<int,int> x = pq.top();
            if(v[i].first>x.second){
                pq.pop();
                pq.push(v[i]);
            }else{
                // pq.pop();
                pq.push(v[i]);
            }
        }
        
        return pq.size();
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends