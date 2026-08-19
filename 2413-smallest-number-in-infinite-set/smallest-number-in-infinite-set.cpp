class SmallestInfiniteSet {
public:
int cur;
unordered_set<int> st;
priority_queue<int,vector<int>,greater<int>> pq;


    SmallestInfiniteSet() {
        cur=1;

    }
    
    int popSmallest() {
        if(!pq.empty())
        {
            int small=pq.top();
            pq.pop();
            st.erase(small);
            return small;
                    }
        return cur++;
    }
    
    void addBack(int num) {
        if(num<cur && st.find(num)==st.end())
        {
            pq.push(num);
            st.insert(num);
        }
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */