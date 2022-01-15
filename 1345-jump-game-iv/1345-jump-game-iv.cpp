class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1){
            return 0;
        }
       unordered_map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        vector<int> dis(n,INT_MAX);
        dis[0]=0;
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int index = q.front();
            q.pop();
            
            if(index==n-1){
                return dis[index];
            }
            
            vector<int> &list = mp[arr[index]];
            list.push_back(index-1);
            list.push_back(index+1);
            
            for(auto &x : list){
                if(x>=0 && x<arr.size() && dis[x]>dis[index]+1){
                    dis[x]=dis[index]+1;
                    q.push(x);
                }
            }
            list.clear();
        }
       
        
        return -1;
        
    }
};