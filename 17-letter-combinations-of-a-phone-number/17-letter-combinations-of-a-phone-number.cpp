class Solution {
public:
    
    unordered_map<char,string> mp;
    vector<string> ans;
    
    void solve(string digits,string str,int i,unordered_map<char,string> &mp){
        
        if(i==digits.size()){
            ans.push_back(str);
            return;
        }
        
        for(auto letters : mp[digits[i]]){
            str.push_back(letters);
            solve(digits,str,i+1,mp);
            str.pop_back();
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0){
            return ans;
        }
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        string str = "";
        solve(digits,str,0,mp);
        return ans;
        
    }
};