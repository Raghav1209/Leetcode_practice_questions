class WordDictionary {
public:
    // unordered_set<string> s;
    unordered_map<int,vector<string>> mp;
    
    WordDictionary() {
        mp[0].push_back("");
    }
    
    void addWord(string word) {
        // s.insert(word);
        mp[word.length()].push_back(word);
    }
    
    bool search(string word) {
        
        int flag = 0;
        int flag2;
        for(int i=0;i<word.length();i++){
            if(word[i]=='.'){
                flag=1;
                break;
            }
        }
        
        if(flag){
           for(auto x : mp[word.length()]){
               int i=0;
               while(i<word.length()){
                   if(word[i]==x[i] || word[i]=='.'){
                       i++;
                       flag2 = 1;
                       continue;
                   }else{
                       flag2=0;
                       break;
                   }
               }
               if(flag2){
                   mp[word.length()].push_back(word);
                   return true;
               }
           }
        }else{
            for(auto x : mp[word.length()]){
                if(x==word){
                    mp[word.length()].push_back(word);
                    return true;
                }
            }
        }
        return false;
        
        
        
        
        
        
        
        
        
        
//         int flag = 0;
//         int flag2;
//         for(int i=0;i<word.length();i++){
//             if(word[i]=='.'){
//                 flag=1;
//                 break;
//             }
//         }
        
//         if(flag){
//             for(auto x : s){
//                 if(x.length()!=word.length()){
//                     continue;
//                 }
//                 for(int i=0;i<x.length();i++){
//                     if(word[i]==x[i] || word[i]=='.'){
//                         flag2=1;
//                         continue;
//                     }else{
//                         flag2 = 0;
//                         break;
//                     }
//                 }
//                  if(flag2){
//                     s.insert(word);
//                     return true;
//                 }
//         }
//             return false;
//         }else{
//             if(s.find(word)!=s.end()){
//                 s.insert(word);
//                 return true;
//             }else{
//                 return false;
//             }
//         }
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */