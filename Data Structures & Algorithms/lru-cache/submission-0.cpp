class LRUCache {
public:
    struct Node{
        int value;
        int key;
        Node* next;
        Node* prev;
    };
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    Node* head=nullptr;
    Node* tail=nullptr;
    unordered_map<int,Node*> mp;
    int count=0;

    void del(Node* n){
        Node* t;
        if(n==head){
            t=head;
            head=head->next;
            if(head)
                head->prev=nullptr;
            else
                tail=nullptr;
        }
        else if(n==tail){
            t=tail;
            tail=tail->prev;
            tail->next=nullptr;
        }
        else{
            t=n;
            t->next->prev=t->prev;
            t->prev->next=t->next;
        }
        mp.erase(t->key);
        count--;
    }
    void add(int key,int value){
        Node* n = new Node();
        n->key=key;
        n->value=value;
        mp[n->key]=n;
        count++;
        if(tail!=nullptr){
            tail->next=n;
            n->prev=tail;}
        else{
            head=n;
        }
        tail=n;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            put(key,mp[key]->value);
            return mp[key]->value;}
        else
            return -1;
    }
    
    void put(int key, int value) {
         
        if(mp.find(key)!=mp.end()){
            del(mp[key]);
        }
        else if(count==cap){
            Node* t=head;
            del(t);
        }
        add(key,value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */