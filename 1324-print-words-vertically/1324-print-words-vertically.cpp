class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v;
        stringstream ss(s);
        string word;
        int maxx = 0;
        while(ss >> word){
            if(maxx<word.length()){
                maxx = word.length();
            }
        }
        cout<<maxx<<" ";
       
        int i = 0;
        // int flag = 1;
        while(i!=maxx){
            string str = "";
             stringstream sss(s);
            while(sss >> word){
               if(i<word.length()){
                   str += word[i];
               }else{
                   str += ' ';
               }
            }
            while(str[str.length()-1]==' '){
                str.pop_back();
            }
            i++;
            v.push_back(str);
        }
      
        
        return v;
        
    }
};