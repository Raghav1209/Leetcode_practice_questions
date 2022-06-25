// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
struct Triplet{
    int val,apos,vpos;
    Triplet(int v,int ap,int vp){
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct mycmp{
    bool operator() (Triplet &t1,Triplet &t2){
        return t1.val>t2.val;
    }
};

class Solution
{
    public:

    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> res;
    priority_queue<Triplet,vector<Triplet>,mycmp> pq;
    
    for(int i=0;i<arr.size();i++){
        Triplet t(arr[i][0],i,0);
        pq.push(t);
    }
    
    while(!pq.empty()){
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        
        int ap = curr.apos;
        int vp = curr.vpos;
        
        if(vp+1<arr[ap].size()){
            Triplet t(arr[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
        
    }
    
    return res;
    
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends