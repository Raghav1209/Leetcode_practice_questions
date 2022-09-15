class Solution {
public:
    int partitionString(string s) {
        
        set<char> ss;
        int count = 0;
        
        for(int i=0;i<s.size();i++){
            if(ss.find(s[i])!=ss.end()){
                ss.clear();
                count++;
                i--;
            }else{
                ss.insert(s[i]);
            }
        }
        
        if(s.size()!=0){
            count++;
        }
        
        return count;
        
    }
};