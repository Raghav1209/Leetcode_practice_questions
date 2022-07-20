class Solution {
public:
    
    int bs(vector<int> &arr,int x){
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        while(start<=end){
            int mid = (start+end)/2;
            
            if(arr[mid]<=x){
                start = mid+1;
            }else{
                ans = mid;
                end = mid-1;
            }
            
        }
        
        if(ans==-1){
            return ans;
        }else{
            return arr[ans];
        }
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
//         int count=0;
//         for(int i=0;i<words.size();i++){
//             string str = words[i];
//             int idx = 0;
//             int k=0;
//             for(int j=0;j<s.size();j++){
//                 if(idx<str.size() && s[j]==str[idx]){
//                     idx++;
//                     k++;
//                 }
//                 if(k==str.size()){
//                     count++;
//                     break;
//                 }
//             }
            
//         }
        
//         return count;
        
        
        
        unordered_map<char,vector<int>> mp;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        
        int count = words.size();
        
        for(auto w : words){
            int prev = -1;
            for(int j=0;j<w.size();j++){
                int x = bs(mp[w[j]],prev);
                if(x==-1){
                    count--;
                    break;
                }else{
                    prev = x;
                }
                
            }
        }
        
        return count;
        
    }
};