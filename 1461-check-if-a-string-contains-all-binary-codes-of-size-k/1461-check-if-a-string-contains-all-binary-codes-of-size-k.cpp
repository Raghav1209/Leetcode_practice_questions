class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if(s.length()<k){
            return false;
        }
        
        unordered_set<string> ss;
        
        for(int i=0;i<s.length()-k+1;i++){
            string str = s.substr(i,k);
            ss.insert(str);
        }
        
        // for(auto x : ss){
        //     cout<<x<<endl;        }
        
        if(ss.size()==pow(2,k)){
            return true;
        }else{
            return false;
        }
    }
};