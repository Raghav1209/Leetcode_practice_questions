// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    static bool mycmp(pair<int,int> a,pair<int,int> b){
        double r1 = (double) a.first/a.second;
        double r2 = (double) b.first/b.second;
        
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back({arr[i].value,arr[i].weight});
        }
        
        sort(v.begin(),v.end(),mycmp);
        double ans = 0;
        for(int i=0;i<n;i++){
            if(v[i].second<=W){
                ans += v[i].first;
                W -= v[i].second;
            }else{
                ans = ans + (double)v[i].first*((double)W/(double)v[i].second);
                break;
            }
        }
        
        return ans;
        
        
        
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends