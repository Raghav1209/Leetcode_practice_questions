class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        vector<string> v;
        string word;
        
        while(ss >> word){
            reverse(word.begin(),word.end());
            v.push_back(word);
        }
        
        string ans = "";
        
        for(int i=0;i<v.size();i++){
            ans += v[i];
            ans += " ";
        }
        
        ans.pop_back();
        return ans;
        
    }
};