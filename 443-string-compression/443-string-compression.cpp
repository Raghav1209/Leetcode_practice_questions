class Solution {
public:
    int compress(vector<char>& chars) {
        
        vector<pair<char,int>> v;
        string str = "";
        int count = 0;
        for(int i=0;i<chars.size()-1;i++){
            
            if(chars[i]==chars[i+1]){
                count++;
                continue;
            }else{
                count++;
                v.push_back({chars[i],count});
                count = 0;
            }
             
            
        }
        
        count++;
        v.push_back({chars[chars.size()-1],count});
        
        for(auto x : v){
            
            if(x.second>1){
                str += x.first;
                str += to_string(x.second);
            }else if(x.second==1){
                str += x.first;
            }
            
        }
        
        chars.clear();
        
        for(int i=0;i<str.size();i++){
            chars.push_back(str[i]);
        }
        
        return chars.size();
        
    }
};