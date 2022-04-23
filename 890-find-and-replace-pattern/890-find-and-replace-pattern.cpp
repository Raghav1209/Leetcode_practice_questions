class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<char,int> p;
        vector<string> ans;
        bool is_right;
        
        for(int i=0;i<pattern.length();i++)
            p[pattern[i]]++;
        for(int i=0;i<words.size();i++)
        {
            map<char,char> mp;
            map<char,int> w;
            is_right = true;
            string word = words[i];
            for(int j=0;j<word.length();j++)
            {
                w[word[j]]++;
            }
            if(w.size() == p.size()){
                for(int j=0;j<p.size();j++){
                    if(p[pattern[j]] != w[word[j]])
                        continue;
                }
            }else{
                continue;
            }
            for(int j=0;j<word.length();j++)
            {
                if(mp.find(pattern[j]) == mp.end())
                    mp[pattern[j]] = word[j];
                else{
                    if(mp[pattern[j]] == word[j])
                        is_right = true;
                    else
                    {
                        is_right = false;
                        break;
                    }   
                }
            }
            if(is_right)
                ans.push_back(word);
        }
        return ans;
        
    }
};