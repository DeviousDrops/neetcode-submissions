class MinStack {
public:
    MinStack() {
           
    }
    vector<pair<int,int>> a;
    void push(int value) {
        int n=a.size();
        if(a.size()==0)
            a.push_back({value,value});
        else{
            a.push_back({value,min(a[n-1].second,value)});
        }
    }
    
    void pop() {
        a.pop_back();
    }
    
    int top() {
        return a[a.size()-1].first;
    }
    
    int getMin() {
        return a[a.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */