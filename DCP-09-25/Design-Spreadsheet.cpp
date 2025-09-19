class Spreadsheet {
public:
    unordered_map<string,int> mp;

    Spreadsheet(int rows) {
        // just initialize, nothing needed for now
    }
    
    void setCell(string cell, int value) {
        mp[cell] = value;
    }
    
    void resetCell(string cell) {
        mp[cell] = 0;
    }
    
    int getValue(string formula) {
        int n = formula.size();
        int ans = 0;
        
        for (int i = 1; i < n; ) {  // skip '=' at start
            if (isdigit(formula[i])) {
                // parse number
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                ans += num;
            }
            else if (isalpha(formula[i])) {
                // parse cell reference like A12
                string cell = "";
                while (i < n && isalpha(formula[i])) {
                    cell += formula[i];
                    i++;
                }
                while (i < n && isdigit(formula[i])) {
                    cell += formula[i];
                    i++;
                }
                ans += mp[cell];  // add value of cell
            }
            else if (formula[i] == '+') {
                i++; // skip plus
            }
            else {
                i++; // skip any unexpected character
            }
        }
        
        return ans;
    }
};
