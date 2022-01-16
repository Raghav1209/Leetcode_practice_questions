class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
//         int n = seats.size();
//         int maxdis = INT_MIN;
//         int minn;
//         unordered_map<int,vector<int>> mp;
//         for(int i=0;i<n;i++){
//             mp[seats[i]].push_back(i);
//         }
        
//         vector<int> v = mp[1];
        
//         for(auto x : mp[0]){
//             minn = INT_MAX;
//                 for(int i=0;i<v.size();i++){
//                     int j = i+1;
                    
//                         if(x<v[i]){
//                               minn = abs(x-v[i]);
//                             break;
//                         }else if(j==v.size()){
//                             minn = abs(x-v[i]);
//                             break;
//                         }else{
//                             minn = min(abs(x-v[i]),abs(x-v[j]));
//                             break;
//                         }
//                     }
//                 maxdis = max(minn,maxdis);
//             }
//         return maxdis;
        
        int ans = INT_MIN;
        int count = 0;
        int flag = 0;
        int n = seats.size();
        
        for(int i=0;i<n;i++){
            if(seats[i]==0){
                count++;
            }else{
                if(flag==0){
                    ans = max(ans,count);
                }else{
                    ans = max(ans,(count+1)/2);
                }
                flag = 1;
                count = 0;
            }
        }
        if(count>0){
            ans = max(ans,count);
        }
        return ans;
    }
};

//1-->  0
// 0--> 1,2,3

