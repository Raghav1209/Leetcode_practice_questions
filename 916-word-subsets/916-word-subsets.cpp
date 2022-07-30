class Solution {
public:
    
    vector<int> count_freq(string word){
        vector<int> count(26,0);
        for(int i=0;i<word.size();i++){
            count[word[i]-'a']++;
        }
        return count;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> max_freq(26,0);
        vector<string> ans;
        
        for(string w1 : words2){
            vector<int> freq = count_freq(w1);
            
            for(int i=0;i<26;i++){
                max_freq[i] = max(max_freq[i],freq[i]);
            }
            
        }
        
        for(string w2 : words1){
            
            vector<int> freq = count_freq(w2);
            
            int flag = 1;
            
            for(int i=0;i<26;i++){
                if(freq[i]<max_freq[i]){
                    flag=0;
                    break;
                }
            }
            
            if(flag){
                ans.push_back(w2);
            }
            
            
        }
        return ans;
    }
};