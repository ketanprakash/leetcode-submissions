class ThroneInheritance {
public:
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;
    string kingName;

    ThroneInheritance(string kingName) {
        this -> kingName = kingName;
    }
    
    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        stack<string> st; 
        st.push(kingName);
        vector<string> ans;

        string node;
        while (!st.empty()){
            node = st.top(); 
            st.pop(); 

            if (!dead.count(node)) ans.push_back(node);

            for (int i = children[node].size() - 1; i >= 0; i--){
                st.push(children[node][i]);
            }
        }

        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */