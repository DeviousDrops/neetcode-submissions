class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<pair<int,int>> p;
        for(int i=0;i<sp.size();i++){
            p.push_back({pos[i],sp[i]});
        }    
        sort(p.begin(),p.end());
        stack<double> s;
        for(int i=pos.size()-1;i>=0;i--){
            double t=(target-p[i].first)*1.0/p[i].second;
            cout<<t<<endl;
            if(!s.empty()&&s.top()>=t)
                continue;
            else 
                s.push(t);
            cout<<"size"<<s.size()<<"\n";
        }
        return s.size();
    }
};