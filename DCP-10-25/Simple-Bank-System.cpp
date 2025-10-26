class Bank {
public:
    vector<pair<int, long long>> vp;
    int accounts;
    Bank(vector<long long>& balance) {
        for(int i=0; i<balance.size(); i++){
            vp.push_back({i, balance[i]});
        }

        accounts = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if((account1 >=1 && account1 <= accounts) && (account2 >= 1 && account2 <= accounts)){
            if(vp[account1-1].second >= money){
                vp[account1-1].second -= money;
                vp[account2-1].second += money;
                return true;
            }
        }

        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account >= 1 && account <= accounts){
            vp[account-1].second += money;
            return true;
        }

        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account >= 1 && account <= accounts){
            if(vp[account-1].second >= money){
                vp[account-1].second -= money;
                return true;
            }
        }

        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */