class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
                vector<string> code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        
        for(int i=0;i<words.size();i++){
            string str = "";
            string ss = words[i];
            for(int j=0;j<ss.size();j++){
                
                str += code[ss[j]-'a'];
                
            }
            
            s.insert(str);
            
        }
        
        return s.size();
        
    }
};