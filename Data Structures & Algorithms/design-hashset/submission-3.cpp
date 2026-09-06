class MyHashSet {
    private:
     struct Node{
        int data;
        Node* next;

        Node(int val){
            this->next = NULL;
            this->data = val;
        }
     };

     vector<Node*> v;

     int HashBucket(int key){
        return key%1000;
     }

public:
    MyHashSet() {
        v.resize(1001);
        for(auto& it : v){
            it = new Node(0);
        }
    }
    
    void add(int key) {
        Node* cur = v[HashBucket(key)];

        while(cur->next){
            if(cur->next->data == key){
                return;
            }
            cur = cur->next;
        }
        cur->next = new Node(key);
    }
    
    void remove(int key) {
        Node* cur = v[HashBucket(key)];

        while(cur->next){
            if(cur->next->data == key){
                Node* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
        return;
    }
    
    bool contains(int key) {
        Node* cur = v[HashBucket(key)];
        while(cur->next){
            if(cur->next->data == key){
                return true;
            }
            cur = cur->next;
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