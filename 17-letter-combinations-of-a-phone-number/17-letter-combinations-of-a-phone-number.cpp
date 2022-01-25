class Solution {
public:
    
    vector<string> merge(vector<string> a,vector<string> b){
        vector<string> req;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b.size();j++){
                string str = "";
                str += a[i];
                str += b[j];
                req.push_back(str);
            }
        }
        return req;
    }
    
    vector<string> letterCombinations(string digits) {
    
        int n = digits.length();
        
          if(n==0){
              vector<string> ans;
            return ans;
        }
    
        map<char,vector<string>> m;
        m.insert({'2',{"a","b","c"}});
         m.insert({'3',{"d","e","f"}});
         m.insert({'4',{"g","h","i"}});
         m.insert({'5',{"j","k","l"}});
         m.insert({'6',{"m","n","o"}});
         m.insert({'7',{"p","q","r","s"}});
         m.insert({'8',{"t","u","v"}});
         m.insert({'9',{"w","x","y","z"}});
        
        // if(n==1){
        //     return m[digits[0]].second;
        // }else if(n==2){
        //     return merge(m[digits[0]].second,m[digits[1]].second);
        // }else if(n==3){
        //     vector<string> v = merge(m[digits[0]].second,m[digits[1]].second);
        //     return merge(v,m[2].second);
        // }else{
        //     vector<string> v = merge(m[digits[0]].second,m[digits[1]].second);
        //     vector<string> v1 = merge(m[digits[2]].second,m[digits[3]].second);
        //     return merge(v,v1);
        // }
        
        if(n==1){
            return m[digits[0]];
        }else if(n==2){
            return merge(m[digits[0]],m[digits[1]]);
        }else if(n==3){
            vector<string> v = merge(m[digits[0]],m[digits[1]]);
            return merge(v,m[digits[2]]);
        }else{
            vector<string> v = merge(m[digits[0]],m[digits[1]]);
            vector<string> v1 = merge(m[digits[2]],m[digits[3]]);
            return merge(v,v1);
        }
        
        
        
            
    }
};