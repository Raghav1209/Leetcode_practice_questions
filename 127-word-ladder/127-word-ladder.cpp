class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        unordered_set<string> s;
        
        
        for(string str : wordList){
            s.insert(str);
        }
        
        if(s.find(endWord)==s.end()){
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int d = 0;
        
        while(!q.empty()){
            int n = q.size();
            
            d++;
            
            for(int i=0;i<n;i++){
                string curr = q.front();
                q.pop();
                
                for(int i=0;i<curr.size();i++){
                    string temp = curr;
                    for(char c='a';c<='z';c++){
                        temp[i] = c;
                        
                        if(temp==curr){
                            continue;
                        }
                        
                        if(temp==endWord){
                            return d+1;
                        }
                        
                        if(s.find(temp)!=s.end()){
                            q.push(temp);
                            s.erase(temp);
                        }
                        
                        
                        
                    }
                }
                
            }
            
        }
        
        return 0;
        
    }
};