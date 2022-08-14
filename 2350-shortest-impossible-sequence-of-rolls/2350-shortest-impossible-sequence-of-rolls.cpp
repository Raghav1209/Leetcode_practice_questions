#define pi pair<int,int>
class Solution {
public:
    
    int shortestSequence(vector<int>& rolls, int k) {
        
        set<pi> all;
        
        vector<int> last(k+1,0);
        
        for(int i=1;i<=k;i++){
            all.insert({0,i});
        }
        
        for(int i=rolls.size()-1;i>=0;i--){
            
            int minn = all.begin()->first;
            
            all.erase({last[rolls[i]],rolls[i]});
            last[rolls[i]] = minn+1;
            all.insert({last[rolls[i]],rolls[i]});
            
        }
        
        return all.begin()->first+1;
        
    }
};