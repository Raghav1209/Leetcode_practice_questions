class Solution {
public:
    string smallestNumber(string pattern) {
        string num = "";
        stack<int> st;
        
        for(int i=0;i<=pattern.size();i++){
            
            st.push(i+1);
            
            if(i==pattern.size() || pattern[i]=='I'){
                while(!st.empty()){
                    num += to_string(st.top());
                    st.pop();
                }
            }
            
        }
        
        return num;
        
    }
};