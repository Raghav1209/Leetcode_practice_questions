class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        map<char,int> mp1;
        map<int,int> mp2;
        
        for(int i=0;i<suits.size();i++){
            mp1[suits[i]]++;
        }
        
        for(int i=0;i<ranks.size();i++){
            mp2[ranks[i]]++;
        }
        
        for(auto x : mp1){
            if(x.second==5){
                return "Flush";
            }
        }
        
        
                
        for(auto x : mp2){
            if(x.second>=3){
                return "Three of a Kind";
            }
        }
        
        for(auto x : mp2){
            if(x.second==2){
                return "Pair";
            }
        }
        
        return "High Card";
        
    }
};