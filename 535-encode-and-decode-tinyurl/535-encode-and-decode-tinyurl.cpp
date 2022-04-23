class Solution {
public:
    map<string,string> mp;
    const int MAX = 62;
    // Encodes a URL to a shortened URL.
    
 
    string encode(string longUrl) {
        
        string str = "http://tinyurl.com/";
        
    vector<string>alphabet{ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m","n",
                          "o", "p", "q", "r", "s", "t", "u",
                          "v", "w", "x", "y", "z","A" ,"B" ,"C", "D","E", "F", "G",
                          "H", "I", "J", "K", "L", "M", "N",
                          "O", "P", "Q", "R", "S", "T", "U",
                          "V", "W", "X", "Y", "Z","0","1","2","3","4","5","6","7","8","9"};
                         
        
        for(int i=0;i<6;i++){
            str += alphabet[rand()%MAX];
        }
        
        mp.insert({longUrl,str});
        
        return str;
        
        
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        
        for(auto x : mp){
            if(x.second==shortUrl){
                return x.first;
            }
        }
        
        return "";
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));