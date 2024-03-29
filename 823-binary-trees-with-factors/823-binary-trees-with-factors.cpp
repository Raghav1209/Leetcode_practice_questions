class Solution {
public:
    
    int solve(vector<int> &arr,int idx,unordered_map<int,long long> &mp){
        
        if(idx==arr.size()){
            return 0;
        }
        
        if(mp[arr[idx]]){
            return mp[arr[idx]];
        }
        
        long long count = 1;
        
        for(int i=0;i<idx;i++){
            int a = arr[i];
            if(arr[idx]%a != 0){
                continue;
            }
            int b = arr[idx]/a;
            
            if(mp.find(a)!=mp.end() && mp.find(b)!=mp.end()){
                count = (count + (mp[a]*mp[b]%mod))%mod;
            }
            
        }
        
        mp[arr[idx]] = count;
        return count;
        
    }
    
    int mod = 1000000007;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int c = 0;
        unordered_map<int,long long> mp;
        for(int i=0;i<arr.size();i++){
            c = (c+solve(arr,i,mp)%mod)%mod;
        }
        
        return c;
        
    }
};