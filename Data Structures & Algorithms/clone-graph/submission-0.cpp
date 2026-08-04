/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return node;
        unordered_map<int,Node*> s;
        deque<Node*> q1;
        deque<Node*> q2;
        Node* temp;
        q1.push_back(node);
        Node* n=new Node(node->val);
        q2.push_back(n);
        Node* start=n;
        s[1]=n;
        while(!q1.empty()){
            temp=q1.front();
            q1.pop_front();
            n=s[temp->val];
            for(int i=0;i<temp->neighbors.size();i++){
                if(!s.contains(temp->neighbors[i]->val)){
                    Node* x=new Node(temp->neighbors[i]->val);
                    q1.push_back(temp->neighbors[i]);
                    s[temp->neighbors[i]->val]=x;
                }
                n->neighbors.push_back(s[temp->neighbors[i]->val]);
            }
        }  
        return start;  
    }
};