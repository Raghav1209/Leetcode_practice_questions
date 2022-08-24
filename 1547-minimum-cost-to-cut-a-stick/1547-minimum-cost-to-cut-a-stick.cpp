class Solution {
public:
    
    int solve(int startInd,int endInd,int startVal,int endVal,vector<vector<int>> &dp,vector<int> &cuts){
        
        if(startInd>endInd){
            return 0;
        }
        
        if(dp[startInd][endInd]!=-1){
            return dp[startInd][endInd];
        }
        
        int minn = INT_MAX;
        int currCost = endVal-startVal;
        for(int i=startInd;i<=endInd;i++){
            minn = min(minn,currCost+solve(startInd,i-                                                          1,startVal,cuts[i],dp,cuts)+solve(i+1,endInd,cuts[i],endVal,dp,cuts));
            
        }
        
        return dp[startInd][endInd] = minn;
        
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        
        return solve(0,cuts.size()-1,0,n,dp,cuts);
        
        
    }
};