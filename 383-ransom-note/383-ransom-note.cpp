class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> mp1;
         unordered_map<char,int> mp2;
        
        for(int i=0;i<ransomNote.size();i++){
            mp1[ransomNote[i]]++;
        }
        
        
        for(int i=0;i<magazine.size();i++){
            mp2[magazine[i]]++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
            if(mp1[ransomNote[i]]>mp2[ransomNote[i]]){
                return false;
            }
        }
        
        return true;
        
    }
};