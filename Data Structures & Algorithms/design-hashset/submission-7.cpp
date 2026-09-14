class MyHashSet {
private:
   struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key){
      val = key;
      left = NULL;
      right = NULL;
    }
   };
   
   TreeNode* add(TreeNode* root, int key){
     if(root == NULL){
        return new TreeNode(key);
     }
     else if(key < root->val){
       root->left = add(root->left, key);
     }
     else if(key > root->val){
       root->right = add(root->right, key);
     }
     return root;
   }

   TreeNode* remove(TreeNode* root, int key){
       if(root == NULL){
        return NULL;
       }
       else if(key < root->val){
          root->left = remove(root->left, key);
       }
       else if(key > root->val){
        root->right = remove(root->right, key);
       }
       else{
        if(root->left == NULL){
           TreeNode* temp = root->right;
           delete root;
           return temp;
        }
        if(root->right == NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = root->right;
        
        while(temp->left != NULL){
            temp = temp->left;
        }

        root->val = temp->val;

        root->right = remove(root->right, temp->val);
       }

       return root;
   }

   bool contains(TreeNode* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->val < key){
      return contains(root->right, key);
    }
    else if(root->val > key){
        return contains(root->left, key);
    }
    else{
        return true;
    }
    return false;
   }

   vector<TreeNode*> v;

   int hash_fun(int key){
    return key%1000;
   }

public:
    MyHashSet() {
        v.resize(1001);
    }
    
    void add(int key) {
       v[hash_fun(key)] = add(v[hash_fun(key)], key);
    }
    
    void remove(int key) {
       v[hash_fun(key)] = remove(v[hash_fun(key)], key);
    }
    
    bool contains(int key) {
        return contains(v[hash_fun(key)], key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */