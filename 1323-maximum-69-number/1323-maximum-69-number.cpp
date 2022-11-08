class Solution {
public:
    int maximum69Number (int num) {
        
        
        
        string str = to_string(num);
        string check = str;
        string maxx = str;
        
        for(int i=0;i<str.size();i++){
            if(str[i]=='6'){
                check[i] = '9';
                maxx = max(maxx,check);
                break;
            }
        }
        
        return stoi(maxx);
        
    }
};