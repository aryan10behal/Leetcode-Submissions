class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key,int val){
            this->key=key;
            this->val=val;
        }
    };
    
    node *head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    int cap;
    unordered_map<int,node*>mp;
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(node* res){
        node* temp=head->next;
        head->next=res;
        res->prev=head;
        temp->prev=res;
        res->next=temp;
        return;
    }
    
    void deleteNode(node *res){
        node* resPrev=res->prev;
        node* resNext=res->next;
        resPrev->next=resNext;
        resNext->prev=resPrev;
        return;
    }
    
    int get(int key_) {
        if(mp.count(key_)){
            node* resnode=mp[key_];
            int res=resnode->val;
            mp.erase(key_);
            deleteNode(resnode);
            addNode(resnode);
            mp[key_]=head->next;
            return res;
        }
        else{
            return -1;
        }
    }
    
    void put(int key_, int value_) {
        if(mp.count(key_)){
            node* resnode=mp[key_];
            mp.erase(key_);
            deleteNode(resnode);
        }   
        if(cap==mp.size()){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key_,value_));
        mp[key_]=head->next;
    }
};
