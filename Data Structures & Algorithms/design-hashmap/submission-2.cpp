class MyHashMap {
private:
    struct ListNode{
        int key, val;
        ListNode* next;

        ListNode(int key, int val){
           this->val = val;
           this->key = key;
           this->next = NULL;
        }
    };

    vector<ListNode*> v;

    int hash(int key){
        return key%1000;
    }

public:
    MyHashMap() {
        v.resize(1001);
        for(auto& it : v){
            it = new ListNode(0,0);
        }
    }
    
    void put(int key, int value) {
        ListNode* cur = v[hash(key)];
        while(cur->next){
           if(cur->next->key == key){
            cur->next->val = value;
            return;
           }
           cur = cur->next;
        }
        cur->next = new ListNode(key,value);
    }
    
    int get(int key) {
         ListNode* cur = v[hash(key)];
        while(cur->next){
           if(cur->next->key == key){
            return cur->next->val;
           }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* cur = v[hash(key)];
        while(cur->next){
           if(cur->next->key == key){
            ListNode* temp = cur->next;
            cur->next = temp->next;
            delete(temp);
            return;
           }
            cur = cur->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */