class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    

    map<vector<int>,vector<string>> mp;
    vector<vector<string>> ans;
    // vector<int> v;

    for(int i=0;i<strs.size();i++){
        string str = strs[i];
        vector<int> count(256,0);
        for(int i=0;i<str.size();i++){
            count[str[i]-'a']++;
        }

        // if(mp.find(count)==mp.end()){
        //     mp[count].push_back(strs[i]);
        // }else{
        //     mp[count].push_back(strs[i]);
        // }
        
        mp[count].push_back(strs[i]);

    }

    // unordered_map<vector<int>,vector<string>> :: iterator it;

    for(auto &x : mp){
        vector<string> res = x.second;
        ans.push_back(res);
    }

    return ans;
}
    




// strs = ["eat","tea","tan","ate","nat","bat"]
// [eat, tea, ate],  [tan, nat], [bat]

// O(n * klogk)
};