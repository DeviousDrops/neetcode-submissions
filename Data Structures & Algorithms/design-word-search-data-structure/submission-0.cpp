class Node{
    public:
        unordered_map<char,Node*> d;
        bool final;
};
class WordDictionary {
public:
    WordDictionary() {

    }
    Node* root=new Node();
    void addWord(string word) {
        Node* head=root;
        for(char c:word){
            if(head->d[c]==nullptr)
                head->d[c]=new Node();
            head=head->d[c];
        }
        head->final=true;
    }
    
    bool search(string word) {
        return dfs(root,0,word);
    }

    bool dfs(Node* head,int i,string& word){
        if(i==word.size())
            return head->final;
        
        if(word[i]=='.'){
            for(auto& j:head->d){
                if(dfs(j.second,i+1,word))
                    return true;
            }
            return false;
        }
        if(head->d.find(word[i])==head->d.end())
            return false;
        head=head->d[word[i]];
        return dfs(head,i+1,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */