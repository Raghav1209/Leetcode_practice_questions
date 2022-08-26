class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<pair<char,int>> st;
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push({'(',res.size()});
                
            }else if(s[i]==')'){
                
                if(st.empty()){
                    continue;
                }
                
                if(st.top().first=='('){
                    res.insert(st.top().second,"(");
                }
                res += ')';
                st.pop();
            }else{
                res.push_back(s[i]);
            }
        }
        
        return res;
        
    }
};