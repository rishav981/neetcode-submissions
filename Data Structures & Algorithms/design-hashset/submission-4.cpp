class MyHashSet {
private:
  struct ListNode {
       int data;
       ListNode* next;

       ListNode( int val ){
        this->data = val;
        this->next = NULL;
       }
  };

  int Hashing_fun(int key){
    return key % 1000;
  }

  vector<ListNode*>v;  
    
public:
    MyHashSet() {
        v.resize(1001);
        for(auto& it : v){
            it = new ListNode(0);
        }
    }
    
    void add(int key) {
       ListNode* head = v[Hashing_fun(key)];

       while(head->next){
        if(head->next->data == key){
            return;
        }
        head = head->next;
       }
       head->next = new ListNode(key); 
       return;            
    }
    
    void remove(int key) {
        ListNode* head = v[Hashing_fun(key)];

        while(head->next){
            if(head->next->data == key){
                ListNode* cur = head->next;
                head->next = cur->next;
                delete(cur);
                return;
            }
            head = head->next;
        }
        return;
    }
    
    bool contains(int key) {
        ListNode* head = v[Hashing_fun(key)];
        
        while(head->next){
            if(head->next->data == key){
                return true;
            }
            head = head->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */