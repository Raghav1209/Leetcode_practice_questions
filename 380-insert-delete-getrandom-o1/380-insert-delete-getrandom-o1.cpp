#include <cstdlib>
class RandomizedSet {
public:
    unordered_map<int,int> s;
    vector<int> v;
    int size;
    RandomizedSet() {
        size = 0;
    }
    
    bool insert(int val) {
        if(s.find(val)==s.end()){
            s[val] = size;
            v.push_back(val);
            size++;
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(s.find(val)!=s.end()){
           int idx = s[val];
            v[idx] = v[size-1];
            s[v[idx]] = idx;
            v.pop_back();
            s.erase(val);
            size--;
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        
        int ans = rand()%size;
        return v[ans];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */