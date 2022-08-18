class Solution {
public:
    
    static bool mycmp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    
    int minSetSize(vector<int>& arr) {
        
        int n = arr.size();
        
        vector<pair<int,int>> v;
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        
        for(auto x : mp){
            v.push_back({x.first,x.second});
        }
        
        int count = 0;
        
        sort(v.begin(),v.end(),mycmp);
        
        for(auto i : v){
            n -= i.second;
            count++;
            if(n<=arr.size()/2){
                return count;
            }
        }
        
        return count;
        
    }
};