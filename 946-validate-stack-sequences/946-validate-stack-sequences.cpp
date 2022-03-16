class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int n = pushed.size();
        int m = popped.size();
        int j = 0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() && j<m && st.top()==popped[j]){
                st.pop();
                j++;
            }
        }
        
        while(!st.empty()){
            if(popped[j]==st.top()){
                st.pop();
                j++;
            }else{
                return false;
            }
        }
        
        return true;
        
    }
};