class Node{
    public:
        unordered_map<char,Node*> mp;
        bool final=false;   
};

class PrefixTree {
public:
    PrefixTree() {
    }
    Node* root=new Node();
    void insert(string word) {
        Node* head=root;
        for(char c:word){
            if(!head->mp[c]){
                head->mp[c]=new Node();
            }
            head=head->mp[c];
        }
        head->final=true;
    }
    
    bool search(string word) {
        Node* head=root;
        for(char c:word){
            if(!head->mp[c])
                return false;
            head=head->mp[c];
        }
        return head->final;
    }
    
    bool startsWith(string prefix) {
        Node* head=root;
        for(char c:prefix){
            if(!head->mp[c])
                return false;
            head=head->mp[c];
        }
        return true;    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */