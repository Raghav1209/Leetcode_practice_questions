class LRUCache {
public:
    
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;

            node(int _key,int _val){
                key = _key;
                val = _val;
            }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int c;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        
        c = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    void addNode(node* newnode){
        node* temp = head->next;
        newnode->prev = head;
        newnode->next = temp;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            node* existingNode = mp[key];
            int value = existingNode->val;
            mp.erase(key);
            deleteNode(existingNode);
            addNode(existingNode);
            mp[key] = head->next;
            return value;
        }
        return -1;
        
        
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        
        if(mp.size()==c){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key,value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */