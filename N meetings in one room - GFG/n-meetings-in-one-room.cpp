// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    static bool mycmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
    vector<pair<int,int>> v;
    // int n = start.size();
    for(int i=0;i<n;i++){
        v.push_back({start[i],end[i]});
    }
    // vector<int> ans;
    int res = 1;
    sort(v.begin(),v.end(),mycmp);
    
    // for(auto x : v){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    
    // ans.push_back(1);
    int prev=0;
    for(int i=1;i<v.size();i++){
        if(v[i].first>v[prev].second){
            res++;
            prev=i;
        }
    }
    
    return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends